#pragma once
#include "Op.h"
class Arith :public Op
{
public:
	Arith(Token* tok, Expr* x1, Expr* x2);
	virtual ~Arith();
	Expr* expr1;
	Expr* expr2;
	virtual Expr* gen();
	virtual std::string toString();
};

