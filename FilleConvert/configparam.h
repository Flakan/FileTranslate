#pragma once

#include "resource.h"

typedef struct _fft_result{
	float nfre;
	float mFA;
	float mF;
	float mFRMS;
}FFT_RESULT;


typedef struct _CACULATE_RESULT
{
	long  mTimeTrigNum;
	long  mAllTrigNum;
	float mAverage;     //骞冲潎鍊?
	float mRmVal;		//鍧囨柟宸?
	float mRmsVal;		//鏈夋晥鍊?
	float mFangCha;		//鏂瑰樊;
	float mStdCha;		//鏍囧噯宸?
	float mSkew;		//鍋忓害;
	float mQurt;		//宄害;
	float mAmpMax;		//鏈€澶ц祴鍊硷紱					
	float mAbsAvarage;  //缁濆骞冲潎鍊?
	float mAqrtAbs;		//鏂规牴骞呭€?
	float mCsFactor;	//鍋忔€佸洜鏁?
	float mCoFactor;	//宄版€佸洜鏁?
	float mKFactor;		//K娉㈠舰鍥犳暟;
	float mIPulse;		//I鑴夊啿;
	float mCvalue;		//C宄板€?
	float mLvalue;		//L瑁曞害;

	float mFcval;
	float mFrval;

}CACULATE_RESULT;

typedef enum _PARAM_INDEX
{
   kPARAM_AVG=0,
   kPARAM_RMVAL,
   kPARAM_RMSVAL,
   kPARAM_FANGCHA,
   kPARAM_STDCHA,
   kPARAM_SKEW,
   kPARAM_QURT,
   kPARAM_AMPMAX,
   kPARAM_ABSAVG,
   kPARAM_AQRTABS,
   kPARAM_CSFACTOR,
   kPARAM_COFACTOR,
   kPARAM_KFACTOR,
   kPARAM_IPULSE,
   kPARAM_CVALUE,
   kPARAM_LVALUE,
   kPARAM_FCVALUE,
   kPARAM_FRVALUE	
}PARAM_INDEX;

#define TIME_TRIGER  0
#define VAL_TRIGER   1



typedef struct _FFT_INFO{
	char  name[CHANNELNAMELEN];
	float mfre;
	float mExrange;
}FFT_INFO;

typedef struct _PARAM_SET{
	float max_threshold;
	float avg_threshold;
	int   isStoregeData;
}PARAM_SET;

typedef struct _CHGROUP_INFO{
	int mFFtChannelSum;
	int mCounterIndex;
	int mChindex;
	int mParamIndex;
	FFT_INFO FFTChannel[kFFTRESULT_MAX];
	PARAM_SET mParamSet[kVALIDPARAM];
}CHGROUP_INFO;



typedef struct _SYS_SET{
	char storePath[128];//文件存储路径;
	int  mode;
	int  StorageTimelong;//每个文件存储时间长度;
	int  CaculateInternalTime; //参数计算间隔时间;
	int  CaculateTimelong;//计算多长时间的数据;
	int  PsTrigCaculateTimelong;//阈值触发计算时长;
	int  RawDataStorageTimeInter;
	int  FileStorageTimelong;
}SYS_SET;


typedef struct ChannelsResult
{
	int chId;
	int fftsum;
	int resultState;
	int dataSum;
	int filenameindex;
	CACULATE_RESULT result;
	FFT_RESULT fft_res[kFFTRESULT_MAX];
}CHRESULT;

#define   CHECK_CHANNEL_INDEX(index)  if(index<0||index>=CHANNELNUM){return -1;}
