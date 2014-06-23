#pragma once
#include "Stmt.h"
class Set :public Stmt
{
public:
	Set(Token* i, Expr* x);
	virtual ~Set();
	Token* id;
	Expr* expr;
	virtual void gen(int b, int a);
};

