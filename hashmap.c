//
//  hashmap.c
//  glututor1
//
//  Created by Macbook White on 11/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hashmap.h"



unsigned int defaultHashCompareFunc(void* val1,void* val2)
{
    if(val1==NULL || val2==NULL)return 0;
   // return strcmp((char*)val1,(char*)val2)==0?1:0;
    char* s1=(char*)val1;
    char* s2=(char*)val2;
    
    int ret=strcmp(s1,s2);
    return ret==0?1:0;
    
}

unsigned int jenkinsHash(char *key, size_t len)
{
    unsigned int hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash%HASH_BUCKETS_NR;
}

hashMap* createHashMap(void)
{
    
    hashMap *map=(hashMap*)calloc(1, sizeof(hashMap));
    if(map==NULL)return NULL;
    
    map->buckets=(hashBucket*)calloc(HASH_BUCKETS_NR,sizeof(hashBucket));
    if(map->buckets==NULL)
    {
        free(map);
        return NULL;
    }
    
    map->size=0;
    map->comparemethod=defaultHashCompareFunc;
    map->hashmethod=jenkinsHash;
    
    return map;
}

hashItem* addItemToBucket(char* key,void* data,int hash,hashBucket** bucket)
{
    if(key==NULL || data==NULL || (*bucket)==NULL)return NULL;
    
    hashItem* item=(hashItem*)calloc(1,sizeof(hashItem));
    if(item==NULL)return NULL;
    
    item->key=key;
    item->data=data;
    item->hash=hash;
    
   
    hashItem* tmp=(*bucket)->head;
    if(tmp!=NULL)
    {
        item->prev=tmp;
    }
    
   
    (*bucket)->head=item;
    (*bucket)->size++;
    
    return item;
}


hashItem* addHashItem(char* key,void* data,hashMap **map)
{
    if(key==NULL || data==NULL || (*map)==NULL)return NULL;
    
    int hashkey=(*map)->hashmethod(key,strlen(key));
    
    hashBucket* bucket=&(*map)->buckets[hashkey];
    
    
    hashItem* item=addItemToBucket(key, data, hashkey, &bucket);
    if(item!=NULL)
    {
        (*map)->size++;
    }
    return item;
    
}


hashItem* getHashItem(char* key,hashMap **map)
{
    if(key==NULL || (*map)==NULL)return NULL;
    int hashkey=(*map)->hashmethod(key,strlen(key));
    hashBucket* bucket=&(*map)->buckets[hashkey];
   
    hashItem* tmp=bucket->head;
    while(tmp!=NULL)
    {
        if((*map)->comparemethod((char*)tmp->key,key))
        {
            return tmp;
        }
        tmp=tmp->prev;
    }
    
    return NULL;
}

int deleteHashItem(char* key,hashMap **map)
{
    if(key==NULL || (*map)==NULL)return 0;
    
    int hashkey=(*map)->hashmethod(key,strlen(key));
    hashBucket* bucket=&(*map)->buckets[hashkey];
    
    hashItem* tmp=bucket->head;
    hashItem* old=NULL;
    while(tmp!=NULL)
    {
        if((*map)->comparemethod((char*)tmp->key,key))
        {
            hashItem* next=tmp->prev;
            old->prev=next;
            free(tmp);
            bucket->size--;
            (*map)->size--;
            return 1;
        }
        old=tmp;
        tmp=tmp->prev;
    }

    return 0;
    
}

int deleteHashMap(hashMap **map)
{
    if((*map)==NULL)return 0;
    
    hashBucket* tbuck;
    
    for(int x=0;x<HASH_BUCKETS_NR;x++)
    {
        tbuck=&(*map)->buckets[x];
        hashItem* item=tbuck->head;
        if(item==NULL)
        {
            
            continue;  
        }
        
        hashItem* tmpItem=NULL;
        
        while(item!=NULL)
        {
            tmpItem=item;
            free(item);
            
            item=tmpItem->prev;
        }
        
        
    }
    
    free((*map)->buckets);
    free(*map);
    return 1;
}

void debugBucket(int hash,hashMap *map)
{
    hashBucket *bucket=&map->buckets[hash];
    hashItem* tmp=bucket->head;
    
    printf("BUCKET %i: SIZE:  %i\n",hash,bucket->size);
    
    while(tmp!=NULL)
    {
        
        printf("ITEM: %s-%s\n",tmp->key,(char*)tmp->data);
        
        tmp=tmp->prev;
    }
}

void debugHashMap(hashMap *map)
{
    if(map==NULL)return;
    
    for(int x=0;x<map->size;x++)
    {
        debugBucket(x, map);
    }
}
