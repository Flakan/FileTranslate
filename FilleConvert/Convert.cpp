
#include "stdafx.h"
#include "Convert.h"
#include "configparam.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  CreateTxtHeader(FILE *fp)
{
	//fprintf(fp,"CH\t状态\t数据总量\t数据文件\t时间触发\t所有触发\t平均值\t均方差\t有效值\t方差\t标准差\t偏度\t峭度\t最大幅值\t绝对幅值\t方根幅值\t偏态(Cs)\t峰态(Co)\t波形(k)\t脉冲(I)\t峰值(C)\t裕度(L)\t中心频率\t频率标准差\n");
	fprintf(fp,"%2s\t%2s\t%8s\t%4s\t%8s\t%8s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s",
				"CH","ST","SUM","FILE","TimeTrig","ALLTRIG","AVG","均方差","有效值","方差","标准差","偏度","峭度","最大幅值","绝对幅值","方根幅值","偏态(Cs)","峰态(Co)","波形(k)","脉冲(I)","峰值(C)","裕度(L)","中心频率","频率标准差");
	fprintf(fp,"\n");
	return 0;
}
void WriteTxtResult(FILE *fp ,CHRESULT res)
{
	fprintf(fp,"% 2d\t% 2d\t%8d\t%4d\t",res.chId,res.resultState,res.dataSum,res.filenameindex);
	fprintf(fp,"%8d\t%8d\t",res.result.mTimeTrigNum,res.result.mAllTrigNum);
	fprintf(fp,"% 16.4f\t% 16.4f\t",res.result.mAverage,res.result.mRmVal);
	fprintf(fp,"% 16.4f\t% 16.4f\t",res.result.mRmsVal,res.result.mFangCha);
	fprintf(fp,"% 16.4f\t% 16.4f\t",res.result.mStdCha,res.result.mSkew);
	fprintf(fp,"% 16.4f\t% 16.4f\t",res.result.mQurt,res.result.mAmpMax);
	fprintf(fp,"% 16.4f\t% 16.4f\t",res.result.mAbsAvarage,res.result.mAqrtAbs);
	fprintf(fp,"% 16.4f\t% 16.4f\t",res.result.mCsFactor,res.result.mCoFactor);
	fprintf(fp,"% 16.4f\t% 16.4f\t",res.result.mKFactor,res.result.mIPulse);
	fprintf(fp,"% 16.4f\t% 16.4f\t",res.result.mCvalue,res.result.mLvalue);
	fprintf(fp,"% 16.4f\t%16.4f\t",res.result.mFcval,res.result.mFrval);
	fprintf(fp,"\n");
}