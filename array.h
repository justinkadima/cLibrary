#ifndef _ARRAY_H
#define _ARRAY_H

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    void** data;
    int size;
    int internal_capacity;
    size_t item_size;
}array;


array* array_create(int nritems,size_t itemsize);
void array_free(array** ar);
int array_expand(array* ar);
int array_insert(array* ar, void* item);
void* array_get(array* ar,unsigned int idx);
void* array_update(array* ar,unsigned int idx,void* val);
void* array_remove(array* ar, unsigned int idx);



#endif
