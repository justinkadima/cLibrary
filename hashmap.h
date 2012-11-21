//
//  hashmap.h
//  glututor1
//
//  Created by Macbook White on 11/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef HASHMAP_H
#define HASHMAP_H


#define HASH_BUCKETS_NR  100

typedef unsigned int (*hashFunc)(char* key,size_t len);
typedef unsigned int (*compareFunc)(void *val1,void *val2);

unsigned int defaultHashCompareFunc(void* val1,void* val2);
unsigned int jenkinsHash(char *key, size_t len);

typedef struct _hashItem
{
    char *key;
    void *data;
    struct _hashItem *prev;
    int hash;
    
}hashItem;

typedef struct _hashBucket
{
    int size;
    hashItem *head;
    
}hashBucket;


typedef struct _hashMap
{
    hashBucket *buckets;
    int size;
    hashFunc hashmethod;
    compareFunc comparemethod;
    
}hashMap;


hashMap* createHashMap(void);
hashItem* addItemToBucket(char* key,void* data,int hash,hashBucket **bucket);
hashItem* addHashItem(char* key,void* data,hashMap **map);
hashItem* getHashItem(char* key,hashMap **map);
int deleteHashItem(char* key,hashMap **map);
int deleteHashMap(hashMap **map);

void debugBucket(int hash,hashMap *map);
void debugHashMap(hashMap *map);

#endif
