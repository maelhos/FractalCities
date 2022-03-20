#pragma once
#include "../../../stdinc.h"


class FCShader
{
	static uint32_t program;
private:
	uint32_t id;
	const char* src;
	uint32_t type;
public:
	FCShader();
	~FCShader();

private:

};

FCShader::FCShader()
{
}

FCShader::~FCShader()
{
}