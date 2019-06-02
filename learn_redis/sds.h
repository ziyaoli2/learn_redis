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

sds sdsnewlen(const void* init, size_t initlen);
sds sdsnew(const char *init);
sds sdsempty(void);













#endif /* sds_h */
