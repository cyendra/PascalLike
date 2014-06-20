#include "Arith.h"

Arith::Arith(Token* tok, Expr* x1, Expr* x2) :Op(tok, Type::UnkownVarType)
{
	expr1 = x1;
	expr2 = x2;
	type = Type::max(expr1->type ,expr2->type);
	if (type.isType(Type::UnkownVarType))
	{
		error("type error");
	}
}


Arith::~Arith()
{
}

Expr* Arith::gen()
{
	return new Arith(op, expr1->reduce(), expr2->reduce());
}

std::string Arith::toString()
{
	return expr1->toString() + " " + op->getText() + " " + expr2->toString();
}