//
//  eTemplate.h
//  glututor1
//
//  Created by Macbook White on 11/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ETEMPLATE
#define ETEMPLATE


#include <stdio.h>
#include <string.h>
#include <stdlib.h>






char* _getTemplateBlock(const char* tblock,const char* template);

int replaceTemplateTag(const char* tag,const char* val,char** template);

int _processTemplateTag(const char* tag,const char* val,char** template);


#endif
