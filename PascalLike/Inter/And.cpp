#include "And.h"


And::And(Token* tok, Expr* x1, Expr* x2) :Logical(tok, x1, x2)
{
}


And::~And()
{
}

void And::jumping(int t, int f)
{
	int label = f != 0 ? f : newLabel();
	expr1->jumping(0, label);
	expr2->jumping(t, f);
	if (f == 0) emitLabel(label);
}