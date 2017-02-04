#ifndef _VECTOR_H
#define _VECTOR_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef void (*free_fp)(void**);

typedef struct
{
    void** data;
    int size;
    int internal_capacity;
    free_fp freeFunc;
}vector;


vector* vector_create(int nritems,free_fp freefunc);
void vector_free(vector** ar);
int vector_expand(vector* ar);
int vector_insert(vector* ar, void* item);
void* vector_get(vector* ar,unsigned int idx);
void* vector_update(vector* ar,unsigned int idx,void* val);
void* vector_remove(vector* ar, unsigned int idx);



#endif
