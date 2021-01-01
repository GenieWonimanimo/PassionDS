#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "InfixCalculator.h"
#include "InfixToPostfix.h" // for call ConvToRPNExp
#include "PostCalculator.h" // for call EvalRPNExp

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy);
	ret = EvalRPNExp(expcpy);

	free(expcpy);
	return ret;
}
