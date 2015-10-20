#ifndef LIST_H
#define LIST_H

#include<stdbool.h>

typedef int (*listFuncCompare)(void*,void*);
typedef void (*listFuncTraverse)(void*);



typedef struct _listItem
{
    struct _listItem* next;
    struct _listItem* prev;
    void* data;
    
}listItem;



typedef struct
{
    listItem* head;
    listItem* tail;
    int size;
    listFuncCompare compare;
    
}list;

typedef enum
{
    HEAD=1,
    TAIL=2
}listDir;




list* List_Init(listFuncCompare fcomp);

listItem* List_PushItem(list* lista,listDir idir,void* val);

listItem* List_FindItem(list* lista,void* val);

bool List_DeleteItem(list* lista,void* val,bool freedata);

void List_Delete(list** lista,bool freedata);


bool List_PopItem(list* lista,listDir dir,bool freedata);

void List_Traverse(list* lista,listDir startFrom,listFuncTraverse traverseFunc);



#endif
