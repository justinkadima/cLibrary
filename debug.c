//
//  debug.c
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "debug.h"


void debug(char* file,int line,DebugLevel level,char *mes)
{
    
    switch(level)
    {
        case Info:
            fprintf(stderr, "INFO: %s FILE: %s LINE: %i\n",mes,file,line);
            break;
        case Warning:
            fprintf(stderr, "WARNING: %s FILE: %s LINE: %i ERROR: %s\n",mes,file,line,strerror(errno));
            
#if defined(DEBUG)
            
            fprintf(stderr,"Continue(y/n)?\n");
            while(1)
            {
                char key=getchar();
                
                if(key=='n')
                {
                    fprintf(stderr,"Will abord...\n");
                    exit(EXIT_FAILURE);
                }
                if(key=='y')
                {
                    fprintf(stderr, "Will continue..\n");
                    break;
                }
                
            }
            
#endif
            
            break;
        case Fatal:
            fprintf(stderr, "FATAL: %s FILE: %s LINE: %i ERROR: %s\n",mes,file,line,strerror(errno));
            fprintf(stderr,"Will abord...\n");
            exit(EXIT_FAILURE);
            break;
            
            
    }
    
}