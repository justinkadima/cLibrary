#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "mongoose.h"
#include "template.h"



char* _get_PostParam(const char* pname,struct mg_connection *con)
{
	int bufsize=1024;
	char postdata[bufsize];
	char* ret=(char*)malloc(bufsize*sizeof(char));
	
	int nrread=mg_read(con, postdata,sizeof(postdata));
	
	
	if(mg_get_var(postdata,nrread,pname,ret,bufsize)==-1)
	{
		printf("Post variable %s not found in %s \n",pname,postdata);	
		return NULL;
	}
	
	return ret;
	
}

char* _get_GetParam(const char* pname,const struct mg_request_info* req)
{
	int buffer=1024;
	char* ret=(char*)malloc(buffer*sizeof(char));
	
	if(mg_get_var(req->query_string,buffer,pname,ret,buffer)==-1)
	{
		printf("Get variable %s not found in %s \n",pname,req->query_string);
		return NULL;	
	}
	
	return ret;
}

void* reqHandler(enum mg_event event,struct mg_connection *conn)
{
	const struct mg_request_info *request_info = mg_get_request_info(conn);
  	void *ret="done";

  	if (event == MG_NEW_REQUEST) 
  	{
  		if(strcmp(request_info->uri,"/template")==0)
  		{
  			
  			
            mg_printf(conn,"HTTP/1.0 200 OK\r\n Content-Type: text/html\r\n\r\n ");
            
            char* template="<html><head></head><body>"\
            "<p>unu</p>"\
            "#articol[["\
            "<h1>#[title]</h1>"\
            "<h2>#[pass]</h2>"\
            "<h3>#[title]</h3>"\
            "]]"\
            "</body></html>";

            char* art=_getTemplateBlock("articol",template);
            
  			char* old=art;
            int x=_processTemplateTag("title","ALOHA",&art);
            x=_processTemplateTag("pass","PAROLA", &art);
            
            mg_printf(conn,"%s",art);
            
            if(x>0)free(old);
            free(art);
            
  			return ret;
  		}
        
        if(strcmp(request_info->uri,"/get")==0)
        {
            char* usr=_get_GetParam("user",request_info);
  			
            mg_printf(conn,"HTTP/1.0 200 OK\r\n Content-Type: text/html\r\n\r\n ");
            if(usr!=NULL)
  			{
  				mg_printf(conn,"User Param: %s \n",usr);
                
  			}
  			
  			free(usr);
  			return ret;
        }
  		
  		return NULL;	
  	}
  	
  	return NULL;
	
}

int main(int argc,char** argv)
{

	printf("starting\n");
		
	struct mg_context *ctx;
	static const char *options[] = {"document_root", "root","listening_ports", "8090","num_threads", "5",NULL};

	ctx=mg_start(&reqHandler,NULL,options);
	
	getchar();

	mg_stop(ctx);
	
	return 0;
}
