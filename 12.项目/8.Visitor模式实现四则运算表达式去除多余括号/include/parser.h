#pragma once
#include <memory>
#include "Expression.h"
using std::shared_ptr;
shared_ptr<Expression> GetNumber(const char*& Stream);
shared_ptr<Expression> GetTerm(const char*& Stream);
shared_ptr<Expression> GetFactor(const char*& Stream);
shared_ptr<Expression> GetExp(const char*& Stream);
