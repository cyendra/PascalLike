#pragma once
#include "Node.h"
#include "../Symbols/Type.h"

class Expr :Node
{
public:
	Expr(Token* tok, Type p);
	virtual ~Expr();
	Token *op;
	Type type;
	virtual Expr* gen();
	Expr* reduce();
	void jumping(int t, int f);
	void emitjumps(std::string test, int t, int f);
	virtual std::string toString();
	
};

