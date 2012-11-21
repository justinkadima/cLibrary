//
//  list.h
//  glututor1
//
//  Created by Macbook White on 11/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef LIST_H
#define LIST_H



typedef int (*fcompare)(void* ,void*);

typedef struct _listItem
{
    struct _listItem* next;
    struct _listItem* prev;
    void* data;
    
}listItem;



typedef struct _list
{
    listItem* head;
    listItem* tail;
    int size;
    fcompare compare;
    
}list;

typedef enum _listDir
{
    HEAD=1,
    TAIL=2
}listDir;



list* _createList(void);

listItem* _addItem(void* val,listDir idir,list** lista);

listItem* findItem(void* val,list* lista);

void deleteItem(listItem* item,list* lista);

void popItem(listDir dir,list* lista);


void deleteList(list** lista);

int strcompare(void* s1,void* s2);



#endif
