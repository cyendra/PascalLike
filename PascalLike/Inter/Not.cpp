#include "Not.h"


Not::Not(Token* tok, Expr* x2) :Logical(tok, x2, x2)
{
}


Not::~Not()
{
}

void Not::jumping(int t, int f)
{
	expr2->jumping(f, t);
}

std::string Not::toString()
{
	return op->getText() + " " + expr2->toString();
}