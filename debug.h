//
//  debug.h
//  glututor1
//
//  Created by Macbook White on 11/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef DEBUG_H
#define DEBUG_H

typedef enum
{
        Info,
        Warning,
        Fatal
    
}DebugLevel;


#define __info(mes) debug(__FILE__,__LINE__,Info,mes)
#define __warning(mes) debug(__FILE__,__LINE__,Warning,mes)
#define __fatal(mes) debug(__FILE__,__LINE__,Fatal,mes)

void debug(char* file,int line,DebugLevel level,char *mes);


#endif
