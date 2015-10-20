#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"





list* List_Init(listFuncCompare fcomp)
{
    list* lista=(list*)calloc(1,sizeof(list));
    if(lista==NULL)return NULL;
    
    lista->head=NULL;
    lista->tail=NULL;
    lista->size=0;
    lista->compare=fcomp;
    
    return lista;
    
}


listItem* List_PushItem(list* lista,listDir idir,void* val)
{
    if(lista==NULL || val==NULL)return NULL;
    listItem* item=(listItem*)calloc(1,sizeof(listItem));
    if(item==NULL) return NULL;
    
    item->next=NULL;
    item->prev=NULL;
    item->data=val;
    
    
    if(lista->head==NULL)
    {
        lista->tail=lista->head=item;
        
    }
    else
    {
        
                listItem* tmp=NULL;
        
                if(idir==HEAD)
                {
                    tmp=lista->head;
                    item->prev=tmp;
                    tmp->next=item;
                    lista->head=item;
                }
                else
                {
                    tmp=lista->tail;
                    item->next=tmp;
                    tmp->prev=item;
                    lista->tail=item;
                    
                }
        
    }
    
    lista->size++;
    
    return item;
    
}



listItem* List_FindItem(list* lista,void* val)
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

bool List_DeleteItem(list* lista,void* val,bool freedata)
{
    if(!lista)return false;
    
    listItem* found=List_FindItem( lista,val);
    if(found!=NULL)
    {
        listItem* tmp=NULL;
        
        if(found==lista->head)
        {
            return List_PopItem(lista,HEAD,freedata);
        }
        if(found==lista->tail)
        {
            return List_PopItem(lista,TAIL,freedata);
        }
        
        tmp=found->prev;
        if(tmp)tmp->next=found->next;
        
        tmp=found->next;
        if(tmp)tmp->prev=found->prev;
        
        if(freedata)free(found->data);
        free(found);
        
        lista->size--;
        
        return true;
    }
    return false;
    
}



bool List_PopItem(list* lista,listDir dir,bool freedata)
{
    
    if(lista==NULL)return false;
    
    listItem* item=NULL;
    listItem* tmp=NULL;
    
    switch(dir)
    {
        case HEAD:
            item=lista->head;
            if(item)
            {
                tmp=item->prev;
                if(tmp)tmp->next=NULL;
                lista->head=tmp;
                if(freedata)free(item->data);
                free(item);
                lista->size--;
                return true;
            }
            
            break;
            
        case TAIL:
            item=lista->tail;
            if(item)
            {
                tmp=item->next;
                if(tmp)tmp->prev=NULL;
                lista->tail=tmp;
                if(freedata)free(item->data);
                free(item);
                lista->size--;
                return true;
            }
            
            break;
            
    }
    return false;
}



void List_Traverse(list* lista,listDir startFrom,listFuncTraverse traverseFunc)
{
    
    if(!lista)return;
    listItem* item=NULL;
   
    switch(startFrom)
    {
        
        case HEAD:
        
           item=lista->head;
           
           
           while(item)
           {
               traverseFunc(item->data);
               item=item->prev;
           }
        
        break;
        case TAIL:
        
            item=lista->tail;
           
           while(item)
           {
               traverseFunc(item->data);
               item=item->next;
           }
        
        break;
    }
}



void List_Delete(list** lista,bool freedata)
{
    listItem* tmp=(*lista)->head;
    
    while(tmp!=NULL)
    {
        listItem* nn=tmp->prev;
        if(nn!=NULL)
        {
            nn->next=NULL;
            
        }
       
        if(freedata)
        {
            free(tmp->data);
        }
        free(tmp);
        tmp=nn;
        (*lista)->size--;
        
    }
    
    free(*lista);
    *lista=NULL;
    
}

