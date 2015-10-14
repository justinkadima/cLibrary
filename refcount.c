

#include <stdio.h>
#include <stdlib.h>

#include "refcount.h"

void* RC_Alloc(size_t size)
{
    RefObject* obj=(RefObject*)calloc(1,sizeof(RefObject)+size);
    if(obj==NULL)return NULL;
    
    obj->ptr=obj;
    obj->ptr+=sizeof(RefObject);
    
    obj->retainCount++;
    
    return (void*)obj->ptr;
    
}


void* RC_Retain(void *obj)
{
    if(obj==NULL) return NULL;
    
    void* tmp=obj;
    tmp-=sizeof(RefObject);
    
    RefObject* ref=(RefObject*)tmp;
    
    if(ref==NULL)return NULL;
    
    ref->retainCount++;
    
    return obj;
    
}


void RC_Release(void *obj)
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

unsigned int RC_GetRetainCount(void *obj)
{
    if(obj==NULL) return 0;
    
    void* tmp=obj;
    tmp-=sizeof(RefObject);
    
    RefObject* ref=(RefObject*)tmp;
    
    if(ref==NULL)return 0;
    
    return ref->retainCount;
}
