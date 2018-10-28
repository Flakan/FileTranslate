
#include "stdafx.h"
#include "Convert.h"
#include "configparam.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  CreateTxtHeader(FILE *fp)
{
	//fprintf(fp,"CH\t״̬\t��������\t�����ļ�\tʱ�䴥��\t���д���\tƽ��ֵ\t������\t��Чֵ\t����\t��׼��\tƫ��\t�Ͷ�\t����ֵ\t���Է�ֵ\t������ֵ\tƫ̬(Cs)\t��̬(Co)\t����(k)\t����(I)\t��ֵ(C)\tԣ��(L)\t����Ƶ��\tƵ�ʱ�׼��\n");
	fprintf(fp,"%2s\t%2s\t%8s\t%4s\t%8s\t%8s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s\t%16s",
				"CH","ST","SUM","FILE","TimeTrig","ALLTRIG","AVG","������","��Чֵ","����","��׼��","ƫ��","�Ͷ�","����ֵ","���Է�ֵ","������ֵ","ƫ̬(Cs)","��̬(Co)","����(k)","����(I)","��ֵ(C)","ԣ��(L)","����Ƶ��","Ƶ�ʱ�׼��");
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