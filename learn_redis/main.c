//
//  main.c
//  learn_redis
//
//  Created by Ziyao Li on 6/2/19.
//  Copyright © 2019 Ziyao Li. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "sds.h"

int main(int argc, const char * argv[]) {
    //test sds sdsnewlen(const void* init, size_t initlen);
    const char* n = "Richard";
    size_t len = strlen(n);
    sds name = sdsnewlen(n, len);
    printf("%s\n", name);
    
    
    
    
    return 0;
}
