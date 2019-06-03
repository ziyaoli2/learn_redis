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
    //test1 sds sdsnewlen(const void* init, size_t initlen);
    const char* n = "Apple";
    sds name = sdsnewlen(n, strlen(n));
    printf("Test1: %s\n", name);
    
    //test2 sds sdsnew(const char *init);
    n = "Bob";
    name = sdsnew(n);
    printf("Test2: %s\n", name);
    
    //test3 sds sdsempty(void);
    name = sdsempty();
    printf("Test3: %s\n", name);
    
    //test4 size_t sdslen(const sds s);
    printf("Test4: %d\n", (int)sdslen(name));
    
    //test5 sds sdsdup(const sds s)
    name = sdsnew("Cat");
    sds copy = sdsdup(name);
    printf("Test5: %s\n", copy);
    
    //test6 void sdsfree(sds s);
    printf("Test6: free\n");
    sdsfree(copy);
    
    //test7 size_t sdsavail(const sds s);
    printf("Test7: %d\n", (int)sdsavail(name));
    
    //test 8 sds sdsgrowzero(sds s, size_t len)
    name = sdsnew("Dog");
    sds larger = sdsgrowzero(name, 5);
    printf("%s free is %d\n", larger, (int)sdsavail(larger));
    
    
    
    
    
    
    
    return 0;
}
