#pragma once
#include "Logical.h"
class And :public Logical
{
public:
	And(Token* tok, Expr* x1, Expr* x2);
	virtual ~And();
	virtual void jumping(int t, int f);
};

