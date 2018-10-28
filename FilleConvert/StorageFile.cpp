#include "stdafx.h"
#include "StorageFile.h"
#include <stdio.h>
#include <stdlib.h>

StorageFile::StorageFile()
{

}

StorageFile::~StorageFile()
{

}
int StorageFile::WriteData(FILE *fp,float *data,int len)
{
	if(fp==NULL||data==NULL||len<1)
	{
		return -1;
	}
	int ret = fwrite(data,sizeof(float),len,fp);
	if(ret<0)
	{
		return -1;
	}
	return 0;
}
int StorageFile::WriteParam(FILE *fp,CHRESULT *result)
{
	if(fp==NULL||result==NULL)
	{
		return -1;
	}
	int ret = fwrite(result,sizeof(CHRESULT),1,fp);
	if(ret != 1)
	{
		return -1;
	}
	return 0;
}

int StorageFile::ReadParam(FILE *fp,CHRESULT *result)
{
	int ret = fread(result,sizeof(CHRESULT),1,fp);
	if(ret != 1)
	{
		return -1;
	}
	return 0;
}

int StorageFile::WriteParamHeader(FILE *fp,ParamFile_Header header)
{
	int ret=0;
	mPfheader.head[0]='P';
	mPfheader.head[1]='A';
	mPfheader.head[2]='R';
	mPfheader.head[3]='A';
	mPfheader.maxch=CHANNELNUM;
	ret = fwrite(&mPfheader,sizeof(ParamFile_Header),1,fp);
	if(ret != 1)
	{
		return -1;
	}
	return 0;
}
int StorageFile::ReadParamHeader(FILE *fp,ParamFile_Header *pfheader)
{
	int ret = fread(pfheader,sizeof(ParamFile_Header),1,fp);
	if(ret != 1)
	{
		return -1;
	}		
	return 0;	
}

int StorageFile::WriteDataHeader(FILE *fp,int chId,int  SampleRate)
{
	int ret=0;
	mDfheader.head[0]='D';
	mDfheader.head[1]='A';
	mDfheader.head[2]='D';
	mDfheader.head[3]='A';
	mDfheader.chId=chId;
	mDfheader.SampleRate = SampleRate;
	ret = fwrite(&mDfheader,sizeof(DataFile_Header),1,fp);
	if(ret != 1)
	{
		return -1;
	}		
	return 0;
}

int StorageFile::ReadDataHeader(FILE *fp,DataFile_Header *dfheader)
{
	int ret = fread(dfheader,sizeof(DataFile_Header),1,fp);
	if(ret != 1)
	{
		return -1;
	}		
	return 0;
}


