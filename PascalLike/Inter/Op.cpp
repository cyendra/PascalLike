#include "Op.h"


Op::Op(OperatorToken* tok, Type p) :Expr(tok, p)
{
}


Op::~Op()
{
}

Expr* Op::reduce()
{
	Expr* x = gen();
	Temp* t = new Temp(type);
	emit(" = " + x->toString());
	return x;
}