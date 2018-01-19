#ifndef DEBUG_H
#define DEBUG_H

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<stdarg.h>
#include<string.h>

typedef enum
{
        Info,
        Warning,
        Fatal
    
}DebugLevel;

void __debug(char* file,int line,DebugLevel level,char *mes,...);

#define log_last_error() fprintf(stderr,"LAST ERROR: %s \n",strerror(errno))

#define log_info(mes,...) __debug(__FILE__,__LINE__,Info,mes,__VA_ARGS__)

#define log_fatal(mes,...) __debug(__FILE__,__LINE__,Fatal,mes,__VA_ARGS__)

#define log_warning(mes,...) __debug(__FILE__,__LINE__,Warning,mes,__VA_ARGS__)


int __check(char* file,int line,int condition);
#define check(condition)  __check(__FILE__,__LINE__,condition)



#endif
