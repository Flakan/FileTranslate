#include "stdafx.h"

#include "atlbase.h"
#include "atlstr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace ATL;


static FILE *g_fp=NULL;
void LOG_Init(void)
{
	g_fp=fopen("F:\\log.txt","w");
}
void LOG_Release(void)
{
	fclose(g_fp);
}

void LOG_fprintf(const char *str,...)
{
	if(g_fp==NULL)
		return ;
	char strbuf[256];
	memset(strbuf,0,sizeof(strbuf));
	sprintf_s(strbuf,"%s",str);
	fwrite(strbuf,1,strlen(strbuf),g_fp);
}

void  MGLOG(const char *str,...) 
{
	char strbuf[256];
	memset(strbuf,0,sizeof(strbuf));
	va_list va;
	va_start(va,str);
	_vsnprintf_s(strbuf,sizeof(strbuf)-1,str,va);
	va_end(va);
	OutputDebugString(CA2W(strbuf));
	
}

clock_t   MGTIMEMS(void){	
	return clock();
}