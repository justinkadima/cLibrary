//
//  list.c
//  glututor1
//
//  Created by Macbook White on 11/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"





list* _createList(void)
{
    list* lista=(list*)calloc(1,sizeof(list));
    if(lista==NULL)return NULL;
    
    lista->head=NULL;
    lista->tail=NULL;
    lista->size=0;
    lista->compare=NULL;
    
    return lista;
    
}


listItem* _addItem(void* val,listDir idir,list** lista)
{
    if(*lista==NULL || val==NULL)return NULL;
    listItem* item=(listItem*)calloc(1,sizeof(listItem));
    if(item==NULL) return NULL;
    
    item->next=NULL;
    item->prev=NULL;
    item->data=val;
    
    
    if((*lista)->head==NULL)
    {
        (*lista)->tail=(*lista)->head=item;
        
    }
    else
    {
        
                listItem* tmp=NULL;
        
                if(idir==HEAD)
                {
                    tmp=(*lista)->head;
                    item->prev=tmp;
                    tmp->next=item;
                    (*lista)->head=item;
                }
                else
                {
                    tmp=(*lista)->tail;
                    item->next=tmp;
                    tmp->prev=item;
                    (*lista)->tail=item;
                    
                }
        
    }
    
    (*lista)->size++;
    
    return item;
    
}



listItem* findItem(void* val,list* lista)
{
    if(val ==NULL || lista==NULL || lista->compare==NULL) return NULL;
    
    
    for(listItem* temp=lista->head;temp!=NULL;temp=temp->prev)
    {
        if(lista->compare(temp->data,val))
        {
            return temp;
        }
        
    }
    
    return NULL;
    
}
void deleteItem(listItem* item,list* lista)
{
    if(item==NULL || lista==NULL)return;
    
    listItem* found=findItem(item->data, lista);
    if(found!=NULL)
    {
        listItem* tmp=NULL;
        
        if(found==lista->head)
        {
            popItem(HEAD, lista);
        }
        if(found==lista->tail)
        {
            popItem(TAIL, lista);
        }
        
        tmp=found->prev;
        tmp->next=found->next;
        
        tmp=found->next;
        tmp->prev=found->prev;
        
        free(found);
        lista->size--;
        
        
    }
    
}



void popItem(listDir dir,list* lista)
{
    
    if(lista==NULL)return;
    
    listItem* item=NULL;
    listItem* tmp=NULL;
    
    switch(dir)
    {
        case HEAD:
            item=lista->head;
            tmp=item->prev;
            tmp->next=NULL;
            lista->head=tmp;
            free(item);
            lista->size--;
            
            break;
            
        case TAIL:
            item=lista->tail;
            tmp=item->next;
            tmp->prev=NULL;
            lista->tail=tmp;
            free(item);
            lista->size--;
            
            break;
            
    }
}

void deleteList(list** lista)
{
    listItem* tmp=(*lista)->head;
    
    while(tmp!=NULL)
    {
        listItem* nn=tmp->prev;
        if(nn!=NULL)
        {
            nn->next=NULL;
            
        }
        //printf("Stergere: %s\n",(char*)tmp->data);
        free(tmp->data);
        free(tmp);
        tmp=nn;
        (*lista)->size--;
        
    }
    
    free(*lista);
    *lista=NULL;
    
}

int strcompare(void* s1,void* s2)
{
    printf("%s - %s \n",(char*)s1,(char*)s2);
    if(strcmp((char*)s1,(char*)s2)==0)return 1;
    return 0;
}
