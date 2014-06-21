#pragma once
#include "Expr.h"
class Constant :public Expr
{
public:
	Constant(Token* tok, Type p);
	virtual ~Constant();
	virtual void jumping(int t, int f);
};

