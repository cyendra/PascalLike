#include "Op.h"


Op::Op(Token* tok, Type p) :Expr(tok, p)
{
}


Op::~Op()
{
}

Expr* Op::reduce()
{
	Expr* x = gen();
	Temp* t = new Temp(type);
	emit(t->toString() + " = " + x->toString());
	return t;
}