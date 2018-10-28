#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void LOG_Init(void);
void LOG_Release(void);
void LOG_fprintf(const char *str,...);
void MGLOG(const char *str,...);

clock_t   MGTIMEMS(void);