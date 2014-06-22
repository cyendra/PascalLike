#include "If.h"


If::If(Expr* x, Stmt* s)
{
	expr = x;
	stmt = s;
	if (expr->type.isType(Type::boolean)) expr->error("boolean required in if");
}


If::~If()
{
}

void If::gen(int b, int a)
{
	int label = newLabel();
	expr->jumping(0, a);
	emitLabel(label);
	stmt->gen(label, a);
}