#pragma once
#include "Op.h"
class Unary :public Op
{
public:
	Unary(Token* tok, Expr* x);
	virtual ~Unary();
	Expr* expr;
	virtual Expr* gen();
	virtual std::string toString();
};

