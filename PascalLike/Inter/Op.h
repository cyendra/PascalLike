#pragma once
#include "Expr.h"
#include "Temp.h"
class Op :public Expr
{
public:
	Op(Token* tok, Type p);
	virtual ~Op();
	virtual Expr* reduce();
};

