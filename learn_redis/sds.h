//
//  sds.h
//  learn_redis
//
//  Created by Ziyao Li on 6/2/19.
//  Copyright © 2019 Ziyao Li. All rights reserved.
//

#ifndef sds_h
#define sds_h

typedef char* sds;


/*
* struct to store a string
*/
struct sdshdr {
    
    // size of buf
    int len;
    
    // available length
    int free;
    
    // content
    char buf[];
    
};

//static inline-> no need to create stack, no need to care about function outside with same name.
static inline size_t sdslen(const sds s) {
    struct sdshdr* sh = (void*)(s - sizeof(struct sdshdr));
    return sh->len;
}

static inline size_t sdsavail(const sds s) {
    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
    return sh->free;
}

sds sdsnewlen(const void* init, size_t initlen);
sds sdsnew(const char *init);
sds sdsempty(void);
size_t sdslen(const sds s);
sds sdsdup(const sds s);
void sdsfree(sds s);
size_t sdsavail(const sds s);









#endif /* sds_h */
