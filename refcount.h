//
//  refcount.h
//  glututor1
//
//  Created by Macbook White on 11/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef REFCOUNT_H
#define REFCOUNT_H

#include<stdlib.h>

typedef struct _refObject
{
    void* ptr;
    unsigned int retainCount;
}RefObject;


void* Alloc(size_t sz);
void* Retain(void *obj);
void Release(void *item);
unsigned int getRetainCount(void *item);

#endif
