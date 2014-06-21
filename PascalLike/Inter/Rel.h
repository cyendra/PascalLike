#pragma once
#include "Logical.h"
class Rel :public Logical
{
public:
	Rel(Token* tok, Expr* x1, Expr* x2);
	virtual ~Rel();
	virtual Type check(Type p1, Type p2);
	virtual void jumping(int t, int f);

};

