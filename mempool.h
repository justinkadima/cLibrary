#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <stdlib.h>
#include <stdio.h>


typedef struct 
{
    void* buffer;
    size_t max;
    size_t idx;
}mempool;

mempool* pool_create(size_t sz);
void* pool_get(mempool* pool,size_t sz);
void  pool_free(mempool* pool);

#endif
