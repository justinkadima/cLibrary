//
//  eTemplate.c
//  glututor1
//
//  Created by Macbook White on 11/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "template.h"

char* t_del="#";
char* t_start="[[";
char* t_end="]]";

char* i_del="#";
char* i_start="[";
char* i_end="]";

char* _getTemplateBlock(const char* tblock,const char* template)
{
    
    
    if(tblock==NULL || template==NULL)return NULL;
    
    
    size_t tbsize=strlen(t_del)+strlen(tblock)+strlen(t_start);
    char* startblock=(char*)malloc(tbsize+1);
    memset(startblock,0,tbsize+1);
    
    startblock=strcat(startblock,t_del);
    startblock=strcat(startblock,tblock);
    startblock=strcat(startblock,t_start);
    
    char* beg=strstr(template,startblock);
    
    free(startblock);
    
    if(beg!=NULL)
    {
        beg+=tbsize;
        
        
        char* end=strstr(beg,t_end);
        
        if(end==NULL)
        {
            return NULL;
        }
        
        size_t blen=strlen(beg)-strlen(end);
        char* fin=(char*)malloc(blen+1);
        memset(fin,0,blen+1);
        
        strncpy(fin, beg,blen);
        return fin;
        
    }
    
    return NULL;
    
}



int replaceTemplateTag(const char* tag,const char* val,char** template)
{
    if(*template==NULL || tag==NULL) return 0;
    
    size_t stag=strlen(tag);
    size_t sval=strlen(val);
    
    size_t sblock=strlen(i_del)+strlen(i_start)+stag+strlen(i_end);
    
    char* block=(char*)malloc(sblock+1);
    memset(block,0,sblock);
    
    block=strcat(block,i_del);
    block=strcat(block,i_start);
    block=strcat(block,tag);
    block=strcat(block,i_end);
    
    
    
    char* beg=strstr(*template,block);
    free(block);
    
    if(beg==NULL)
    {
        return 0; 
    }
    
    size_t stemplate=strlen(*template);
    size_t sbeg=strlen(beg);
    
    
    size_t sret=stemplate+1+(sval-stag);
    char* ret=(char*)malloc(sret);
    memset(ret,0,sret);
    
    ret=strncpy(ret,*template,stemplate-sbeg);
    ret=strcat(ret,val);
    
    beg+=sblock;
    
    ret=strcat(ret,beg);
    
    
    *template=ret;
    
    
    return 1;
}


int _processTemplateTag(const char* tag,const char* val,char** template)
{
    if(tag==NULL || *template==NULL)return 0;
    
    
    int x=0;
    
    char* old=NULL;
    
    while(replaceTemplateTag(tag, val, &(*template)))
    {
        if(old!=NULL)free(old);
        old=*template;
        x++;
        
    }
    return x;
    
}



