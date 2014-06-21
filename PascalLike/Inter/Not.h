#pragma once
#include "Logical.h"
class Not :public Logical
{
public:
	Not(Token* tok, Expr* x2);
	virtual ~Not();
	virtual void jumping(int t, int f);
	virtual std::string toString();
};

