#include "Else.h"


Else::Else(Expr* x, Stmt* s1, Stmt* s2)
{
	expr = x;
	stmt1 = s1;
	stmt2 = s2;
	if (expr->type.isType(Type::boolean)) expr->error("boolean required in if");
}


Else::~Else()
{
}

void Else::gen(int b, int a)
{
	int label1 = newLabel();
	int label2 = newLabel();
	expr->jumping(0, label2);
	emitLabel(label1);
	stmt1->gen(label1, a);
	std::stringstream buf;
	std::string s;
	buf << "goto L" << a << std::endl;
	buf >> s;
	emit(s);
	emitLabel(label2);
	stmt2->gen(label2, a);
}