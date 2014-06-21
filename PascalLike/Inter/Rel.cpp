#include "Rel.h"


Rel::Rel(Token* tok, Expr* x1, Expr* x2) :Logical(tok, x1, x2)
{
}


Rel::~Rel()
{
}


Type Rel::check(Type p1, Type p2)
{
	if (p1 == p2) return Type::boolean;
	return Type::UnkownVarType;
}

void Rel::jumping(int t, int f)
{
	Expr* a = expr1->reduce();
	Expr* b = expr2->reduce();
	std::string test = a->toString() + " " + op->getText() + " " + b->toString();
	emitjumps(test, t, f);
}
