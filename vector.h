#ifndef _VECTOR_H
#define _VECTOR_H

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    void** data;
    int size;
    int internal_capacity;
    size_t item_size;
}vector;


vector* vector_create(int nritems,size_t itemsize);
void vector_free(vector** ar);
int vector_expand(vector* ar);
int vector_insert(vector* ar, void* item);
void* vector_get(vector* ar,unsigned int idx);
void* vector_update(vector* ar,unsigned int idx,void* val);
void* vector_remove(vector* ar, unsigned int idx);



#endif
