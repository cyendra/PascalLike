#pragma once
#include "Node.h"
class Expr :Node
{
public:
	Expr();
	virtual ~Expr();
	Token *op;
	Expr* gen();
	Expr* reduce();
	void jumping(int t, int f);
	void emitjumps(std::string test, int t, int f);
};

