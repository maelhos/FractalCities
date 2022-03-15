#pragma once
#include "stdinc.h"
#include <stdio.h>

enum e_ErrorLevel
{
	d_Info = 0,
	d_Warning = 1,
	d_Error = 2
};


static uint8_t DEBUG = e_ErrorLevel::d_Info;

int32_t printd(const std::string& message, e_ErrorLevel errLvl);
int32_t checkd(bool cond, e_ErrorLevel errLvl);
int32_t assertd(bool cond);
