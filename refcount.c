//
//  refcount.c
//  glututor1
//
//  Created by Macbook White on 11/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "refcount.h"

void* Alloc(size_t size)
{
    RefObject* obj=(RefObject*)calloc(1,sizeof(RefObject)+size);
    if(obj==NULL)return NULL;
    
    obj->ptr=obj;
    obj->ptr+=sizeof(RefObject);
    
    obj->retainCount++;
    
    return (void*)obj->ptr;
    
}


void* Retain(void *obj)
{
    if(obj==NULL) return NULL;
    
    void* tmp=obj;
    tmp-=sizeof(RefObject);
    
    RefObject* ref=(RefObject*)tmp;
    
    if(ref==NULL)return NULL;
    
    ref->retainCount++;
    
    return obj;
    
}


void Release(void *obj)
{
    if(obj==NULL) return;
    
    void* tmp=obj;
    tmp-=sizeof(RefObject);
    
    RefObject* ref=(RefObject*)tmp;
    
    if(ref==NULL)return;
    
    ref->retainCount--;
    
    if(ref->retainCount==0)
    {
        free(ref);
        obj=NULL;
    }
    
}

unsigned int getRetainCount(void *obj)
{
    if(obj==NULL) return 0;
    
    void* tmp=obj;
    tmp-=sizeof(RefObject);
    
    RefObject* ref=(RefObject*)tmp;
    
    if(ref==NULL)return 0;
    
    return ref->retainCount;
}