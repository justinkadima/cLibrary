
#ifndef REFCOUNT_H
#define REFCOUNT_H

#include<stdlib.h>

typedef struct
{
    void* ptr;
    unsigned int retainCount;
}RefObject;


void* RC_Alloc(size_t sz);
void* RC_Retain(void *obj);
void RC_Release(void *item);
unsigned int RC_GetRetainCount(void *item);

#endif
