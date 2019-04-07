#pragma once
#include "Expression.h"
#include "utility.h"
#include <string>
#include <stack>
using std::string;
using std::stack;
using std::to_string;


class ExpressionPointer :public Expression::IVisior
{
public:
	string result;


	void Visit(NumberExpression* node);


	
	void Visit(BinaryExpression* node);
	
};

