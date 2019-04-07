#include "Expression.h"

Expression::Expression()
{
	IsLeft = false;
}
void NumberExpression::Accept(IVisior* visitor)
{
	visitor->Visit(this);
}
NumberExpression::NumberExpression(int number)
{
	Value = number;
}
void BinaryExpression::Accept(IVisior* visitor)
{
	visitor->Visit(this);
}
