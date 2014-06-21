#pragma once
#include "Logical.h"
class Or :public Logical
{
public:
	Or(Token* tok, Expr* x1, Expr* x2);
	virtual ~Or();
	virtual void jumping(int t, int f);
};

