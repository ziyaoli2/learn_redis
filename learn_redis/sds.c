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

sds sdsnew(const char *init) {
    int len = init == NULL ? 0 : (int)strlen(init);
    return sdsnewlen(init, len);
}

sds sdsempty(void) {
    return sdsnewlen("", 0);
}

//return duplicate
sds sdsdup(const sds s) {
    return sdsnewlen(s, sdslen(s));
}

void sdsfree(sds s) {
    if (s == NULL) {
        return;
    }
    struct sdshdr* sh = (void*)(s - sizeof(struct sdshdr));
    free(sh);
}

sds sdsgrowzero(sds s, size_t len) {
    struct sdshdr* sh = (void*)(s - sizeof(struct sdshdr));
    size_t totlen, curlen = sh->len;
    
    if (len <= curlen) {
        return s;
    }
    
    s = sdsMakeRoomFor(s, len - curlen);
    
    if (s == NULL) {
        return NULL;
    }
    
    sh = (void*)(s - sizeof(struct sdshdr));
    memset(s + curlen, 0, len - curlen + 1);
    
    totlen = sh->len + sh->free;
    sh->len = (int)len;
    sh->free = (int)(totlen-sh->len);
                     
    return s;
}



sds sdsMakeRoomFor(sds s, size_t addlen) {
    struct sdshdr *sh, *newsh;
    
    size_t free = sdsavail(s);
    
    size_t len, newlen;
    
    if (free >= addlen) {
        return s;
    }
    
    len = sdslen(s);
    sh = (void*) (s-(sizeof(struct sdshdr)));
    
    newlen = len + addlen;
    
    if (newlen < SDS_MAX_PREALLOC) {
        newlen *= 2;
    } else {
        newlen += SDS_MAX_PREALLOC;
    }
    
    newsh = realloc(sh, sizeof(struct sdshdr) + newlen + 1);
    
    if (newsh == NULL) {
        return NULL;
    }
    
    newsh->free = (int) (newlen - len);
    
    return newsh->buf;
}










                     
                     
        
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
    
