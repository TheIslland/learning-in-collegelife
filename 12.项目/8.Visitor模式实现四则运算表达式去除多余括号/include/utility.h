#pragma once
#include "Expression.h"
int IsLarger(BinaryOperator B1, BinaryOperator B2);
bool Is(const char*& Stream, const char* Text);
int Regular(int input);
char GetOp(BinaryOperator B);

struct Exception
{
	const char* Start;
	const char* Error;

	Exception(const char* aStart, const char* aError)
	{
		Start = aStart;
		Error = aError;
	}
};