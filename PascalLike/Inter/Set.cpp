#include "Set.h"


Set::Set(Token* i, Expr* x)
{
	id = i;
	expr = x;
}


Set::~Set()
{
}

void Set::gen(int b, int a)
{
	emit(id->getText() + " = " + expr->gen()->toString());
}