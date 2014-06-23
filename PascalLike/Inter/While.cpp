#include "While.h"


While::While()
{
	expr = nullptr;
	stmt = nullptr;
}


While::~While()
{
}

void While::init(Expr* x, Stmt* s)
{
	expr = x;
	stmt = s;
	if (expr->type.isType(Type::boolean)) expr->error("boolean required in while");
}

void While::gen(int b, int a)
{
	after = a;
	expr->jumping(0, a);
	int label = newLabel();
	emitLabel(label);
	stmt->gen(label, b);
	std::stringstream buf;
	std::string s;
	buf << "goto L" << b << std::endl;
	std::getline(buf, s);
	emit(s);
}
