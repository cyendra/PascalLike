#pragma once
#include "Expr.h"

class Op :public Expr
{
public:
	Op(Token* tok, Type p);
	virtual ~Op();
	virtual Expr* reduce();
};

