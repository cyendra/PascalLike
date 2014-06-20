#pragma once
#include "Node.h"
#include "../Symbols/Type.h"

class Expr :public Node
{
public:
	Expr(Token* tok, Type p);
	virtual ~Expr();
	Token *op;
	Type type;
	virtual Expr* gen();
	virtual Expr* reduce();
	virtual void jumping(int t, int f);
	virtual void emitjumps(std::string test, int t, int f);
	virtual std::string toString();
	
};

