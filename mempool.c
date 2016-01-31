#include "mempool.h"


mempool* pool_create(size_t sz)
{
    mempool* pool=(mempool*)malloc(sizeof(mempool));
    if(!pool)
    {
        perror("Out of memory! Unable to create memory pool");
        return NULL;
    }
    
    pool->buffer=(void*)calloc(1,sz);
    if(!pool->buffer)
    {
        perror("Out of memory! Unable to allocate pool memory!");
        free(pool);
        return NULL;
    }
    
    pool->max=sz;
    pool->idx=0;
    return pool;
}

void* pool_get(mempool* pool,size_t sz)
{
    if(!pool)return NULL;
    
    size_t tmp=pool->idx;
    if(tmp+sz>pool->max)
    {
       
        perror("Unable to get memory!Memory pool maxed out.");
        return NULL;
    }
   
    
    void* p=pool->buffer+pool->idx;
    pool->idx+=sz;
    return p;
}




void pool_free(mempool* pool)
{
    if(pool)
    {
        free(pool->buffer);
        pool->buffer=NULL;
        
        free(pool);
        pool=NULL;
    }
    
}
