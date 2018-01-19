#include "debug.h"

#if defined(__unix__) || defined(__unix)

    #define COLOR_RED "\x1b[31m" 
    #define COLOR_GREEN   "\x1b[32m"
    #define COLOR_YELLOW  "\x1b[33m"
    #define COLOR_END "\x1b[0m" 

#else

    #define COLOR_RED "" 
    #define COLOR_GREEN   ""
    #define COLOR_YELLOW  ""
    #define COLOR_END "" 

#endif




void __warn();

void __debug(char* file,int line,DebugLevel level,char *mes,...)
{
    
    char buf[256];
	
	va_list args;
    va_start (args, mes);
    vsprintf (buf,mes, args);
    va_end (args);

    switch(level)
    {
        case Info:
            fprintf(stderr, "%s INFO: %s FILE: %s LINE: %i %s\n",COLOR_GREEN,buf,file,line,COLOR_END);
            break;
        case Warning:
            fprintf(stderr, "%s WARNING: %s FILE: %s LINE: %i %s\n",COLOR_YELLOW,buf,file,line,COLOR_END);
            __warn();
            break;
        case Fatal:
            fprintf(stderr, " %s FATAL: %s FILE: %s LINE: %i %s\n",COLOR_RED,buf,file,line,COLOR_END);
            fprintf(stderr,"Will abord...\n");
            exit(EXIT_FAILURE);
            break;
            
            
    }
    
}

void __warn(){

    #if defined(DEBUG_WARN)
            
            fprintf(stderr,"Continue(y/n)?\n");
            while(1)
            {
                char key=getchar();
                
                if(key=='n')
                {
                    fprintf(stderr,"abording...\n");
                    exit(EXIT_FAILURE);
                }
                if(key=='y')
                {
                    fprintf(stderr, "continuing..\n");
                    break;
                }
                
            }
            
    #endif
}

int __check(char* file, int line,int condition){
    if(!condition){
         fprintf(stderr, "%s CHECK FAILLED: FILE: %s LINE: %i %s\n",COLOR_YELLOW,file,line,COLOR_END);
         __warn();
    }
    return condition;
}

