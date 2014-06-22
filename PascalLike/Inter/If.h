#pragma once
#include "Stmt.h"

class If :public Stmt
{
public:
	If(Expr* x, Stmt* s);
	virtual ~If();
	Expr* expr;
	Stmt* stmt;
	virtual void gen(int b, int a);

};

