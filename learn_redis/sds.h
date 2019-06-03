//
//  sds.h
//  learn_redis
//
//  Created by Ziyao Li on 6/2/19.
//  Copyright © 2019 Ziyao Li. All rights reserved.
//

#ifndef sds_h
#define sds_h


#define SDS_MAX_PREALLOC (1024*1024)

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
sds sdsgrowzero(sds s, size_t len);




/* Low level functions exposed to the user API */
sds sdsMakeRoomFor(sds s, size_t addlen);
void sdsIncrLen(sds s, int incr);
sds sdsRemoveFreeSpace(sds s);
size_t sdsAllocSize(sds s);



#endif /* sds_h */
