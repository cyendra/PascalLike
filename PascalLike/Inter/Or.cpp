#include "Or.h"


Or::Or(Token* tok, Expr* x1, Expr* x2) :Logical(tok, x1, x2)
{
}


Or::~Or()
{
}

void Or::jumping(int t, int f)
{
	int label = t != 0 ? t : newLabel();
	expr1->jumping(label, 0);
	expr2->jumping(t, f);
	if (t == 0) emitLabel(label);
}