#pragma once
#include "Expr.h"
#include "Temp.h"
class Logical :public Expr
{
public:
	Logical(Token* tok, Expr* x1, Expr* x2);
	virtual ~Logical();
	Expr* expr1;
	Expr* expr2;
	Type check(Type p1, Type p2);
	virtual Expr* gen();
	virtual std::string toString();
};

