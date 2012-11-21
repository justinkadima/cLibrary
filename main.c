//
//  main.c
//  glututor1
//
//  Created by Macbook White on 10/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "hashmap.h"
#include "refcount.h"
#include "debug.h"

//#include "template.h"

char* template="<html><head></head><body>"\
                "<p>unu</p>"\
                "#articol[["\
                "<h1>#[title]</h1>"\
                "<h2>#[pass]</h2>"\
                "<h3>#[title]</h3>"\
                "]]"\
                "</body></html>";




int main (int argc, const char * argv[])
{
    /*    
    char* art=_getTemplateBlock("articol",template);
    printf("templeta este: %s\n",art);
    
    char* old=art;
   
    
    int x=_processTemplateTag("title","JUSTIN",&art);
    x=_processTemplateTag("pass","PAROLA", &art);
    
    if(x>0)free(old);
    
    printf("NR: %i\n",x);
    printf("NOUA templeta: %s\n",art);
    
    
    free(art);
    
    */
    
    
   /* list* ll=_createList();
    ll->compare=strcompare;
    
    if(ll!=NULL)
    {
        for(int a=0;a<10;a++)
        {
            char* buf=(char*)calloc(1024,sizeof(char));
            sprintf(buf,"%i",a);
            _addItem(buf,HEAD,&ll);
            
        }
        
    }
    
    for(listItem* lt=ll->head;lt!=NULL;lt=lt->prev)
    {
        printf("%s\n",(char*)lt->data);
    }
    
    listItem* tm=findItem("3",ll);
    if(tm!=NULL)
    {
        
        printf("am gasit: %s\n",(char*)tm->data);
    }
    
      
    
    deleteList(&ll);
    */
    
    /*
    hashMap* map=createHashMap();
    if(map!=NULL)
    {
        const char* k="justin";
        
        for(int x=0;x<100;x++)
        {
            
            char *buf=(char*)calloc(100,sizeof(char));
            sprintf(buf,"%s%i",k,x);
            
            addHashItem(buf, buf, &map);
        }
        printf("%i\n",map->size);
        
        char dc[]="justin1";
        
        
        hashItem* g1=getHashItem(dc, &map);
        if(g1!=NULL)
        {
            printf("VALOAREA ESTE: %s-%s\n",g1->key,(char*)g1->data);
        }
        
        
        debugHashMap(map);
        
        
        deleteHashMap(&map);
        
        
    }*/
    
    /*char* unu=(char*)Alloc(sizeof(char)*10);
    sprintf(unu,"%s","val1");
    printf("%s\n",unu);
    
    unu=Retain(unu);
    
    printf("RC: %i\n",getRetainCount(unu));
    
    
    Release(unu);
    Release(unu);
    */
        
    
    FILE * pFile;
    pFile = fopen ("unexist.ent","r");
    if (pFile == NULL)
    {
        __warning("blavla");
    }
    return 0;
}

