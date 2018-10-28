#pragma once
#include "configparam.h"

typedef struct
{
	char head[4];
	int  maxch;
	int  intervalTimelong;
	int  SampleRate;
	int  PsTrigCaculateTimelong;
	int  RawDataStorageTimeInter;
}ParamFile_Header;

typedef struct 
{
	char head[4];
	int  chId;
	int  SampleRate;
}DataFile_Header;

class StorageFile{

public:
	StorageFile();
	~StorageFile();
	int WriteParam(FILE *fp,CHRESULT *result);
	int ReadParam(FILE *fp,CHRESULT *result);
	int WriteParamHeader(FILE *fp,ParamFile_Header header);
	int WriteDataHeader(FILE *fp,int chId,int  SampleRate);
	int WriteData(FILE *fp,float *data,int len);
	int ReadParamHeader(FILE *fp,ParamFile_Header *pfheader);
	int ReadDataHeader(FILE *fp,DataFile_Header *dfheader);

private:
	ParamFile_Header mPfheader;
	DataFile_Header	 mDfheader;

};