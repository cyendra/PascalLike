#pragma once
#include "Stmt.h"
class While :public Stmt
{
public:
	While();
	virtual ~While();
	Expr* expr;
	Stmt* stmt;
	virtual void init(Expr* x, Stmt* s);
	virtual void gen(int b, int a);
};

