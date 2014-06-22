#pragma once
#include "Stmt.h"

class Else :public Stmt
{
public:
	Else(Expr* x, Stmt* s1, Stmt* s2);
	virtual ~Else();
	Expr* expr;
	Stmt* stmt1;
	Stmt* stmt2;
	virtual void gen(int b, int a);
};

