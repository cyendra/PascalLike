#pragma once
#include "Node.h"
#include "Expr.h"
class Stmt :public Node
{
public:
	Stmt();
	virtual ~Stmt();
	virtual void gen(int b, int a);
	int after;
	static Stmt* NullStmt;
	static Stmt* Enclosing;
};

