//
//  sds.c
//  learn_redis
//
//  Created by Ziyao Li on 6/2/19.
//  Copyright © 2019 Ziyao Li. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sds.h"

sds sdsnewlen(const void* init, size_t initlen) {
    struct sdshdr* sh;
    
    if (init) {
        sh = malloc(sizeof(struct sdshdr) + initlen + 1);
    } else {
        sh = calloc(sizeof(struct sdshdr) + initlen + 1, 1);
    }
    
    if (sh == NULL) return NULL;
    
    sh->len = (int)initlen;
    sh->free = 0;
    
    if (initlen && init) {
        memcpy(sh->buf, init, initlen);
    }
    
    sh->buf[initlen] = '\0';
    
    return (char*)sh->buf;
}
