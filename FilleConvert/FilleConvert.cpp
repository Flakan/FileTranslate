// FilleConvert.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "configparam.h"
#include "StorageFile.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "MGLOG.h"
#include "Convert.h"

#define PARAM_INDEX "ParamIndex.txt"
#define DATA_INDEX  "index.txt"

char DirName[128];
char namebuf[128];


FILE *ParamIndexFile_Open(const char *path)
{
	char buf[128];
	memset(buf,0,sizeof(buf));
	sprintf_s(buf,"%s/%s",path,PARAM_INDEX);
	FILE *fp = fopen(buf,"r");
	if(fp==NULL)
	{
		return NULL;
	}
	return fp;
}
char *ParamIndexFile_FindName(FILE *fp)
{
	printf("ParamIndexFile_FindName\n");
	memset(namebuf,0,sizeof(namebuf));
	fscanf(fp,"%s",namebuf);
	printf("%s\n",namebuf);
	char *ptr = strstr(namebuf,",");
	return ++ptr;
}
FILE *ParamFile_Open(const char *name)
{
	char buf[128];
	memset(buf,0,sizeof(buf));
	sprintf_s(buf,"%s/%s.param",DirName,name);
	FILE *fp = fopen(buf,"rb");
	if(fp==NULL)
	{
		printf("Can not open %s \n",buf);
		return NULL;
	}
	return fp;
}
int main(int argc, char* argv[])
{
	printf("PATH: %s\n",argv[1]);
	char file[128];
	
	memset(DirName,0,sizeof(DirName));
	sprintf_s(DirName,"%s",argv[1]);

	ParamFile_Header PfHeader;
	CHRESULT  Chresult;
	StorageFile storageFile;

	FILE *fpParamIndex =ParamIndexFile_Open(argv[1]);
	if(fpParamIndex ==NULL)
	{
		return -1;
	}
	while(!feof(fpParamIndex))
	{
		memset(file ,0,sizeof(file));
		sprintf_s(file,"%s",ParamIndexFile_FindName(fpParamIndex));
		FILE *fpParam = ParamFile_Open(file);
		if(fpParam == NULL)
		{
			return -1;
		}

		storageFile.ReadParamHeader(fpParam,&PfHeader);
		printf("head:%s ,maxch:%d,intervalTimelong :%d,SampleRate:%d PsTrigCaculateTimelong %d\n",
			PfHeader.head,PfHeader.maxch,PfHeader.intervalTimelong,PfHeader.SampleRate,PfHeader.PsTrigCaculateTimelong );
		char buf[128];
		sprintf_s(buf,"%s/%s.txt",DirName,file);
		FILE *fptxt=fopen(buf,"wb+");
		CreateTxtHeader(fptxt);
		while(storageFile.ReadParam(fpParam,&Chresult)==0)
		{
			//printf("index %d  all %d\n",Chresult.result.mTimeTrigNum,Chresult.result.mAllTrigNum);
			//printf("Chresult.chId %d,Chresult.resultState %d,Chresult.filenameindex %d,Chresult.fftsum %d,Chresult.dataSum %d\n",
			//	Chresult.chId,Chresult.resultState,Chresult.filenameindex,Chresult.fftsum,Chresult.dataSum
			//);
			WriteTxtResult(fptxt ,Chresult);
		}
		fclose(fptxt);
		fclose(fpParam);
	}
	fclose(fpParamIndex);
	printf("param file process  finished \n");
	printf("start process data file \n");


	return 0;
}
void  Process_DataFile(void)
{
	char file[128];
	memset(file ,0,sizeof(file));
	sprintf(file,"%s/index.txt",DirName);
	FILE * fpindex = fopen(file,"r");
	if(fpindex == NULL)
	{
		return ;
	}
	while(!feof(fpindex))
	{
		char index[128];
		char name[128];
		memset(name,0,sizeof(name));
		memset(index,0,sizeof(index));
		fscanf(fpindex,"%s",index);
		
		for(int i=0;i<CHANNELNUM;i++)
		{

		}
	}

	fclose(fpindex);
}


