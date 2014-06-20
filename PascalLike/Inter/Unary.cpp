#include "Unary.h"


Unary::Unary(Token* tok, Expr* x) :Op(tok, Type::UnkownVarType)
{
	expr = x;
	type = Type::max(Type::integer, expr->type);
	if (type.isType(Type::UnkownVarType)) error("type error");
}


Unary::~Unary()
{
}

Expr* Unary::gen()
{
	return new Unary(op, expr->reduce());
}

std::string Unary::toString()
{
	return op->getText() + " " + expr->toString();
}