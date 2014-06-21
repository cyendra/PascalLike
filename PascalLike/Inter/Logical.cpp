#include "Logical.h"


Logical::Logical(Token* tok, Expr* x1, Expr* x2) :Expr(tok, Type::UnkownVarType)
{
	expr1 = x1;
	expr2 = x2;
	type = check(expr1->type, expr2->type);
	if (type.isType(Type::UnkownVarType)) error("type error");
}


Logical::~Logical()
{
}

Expr* Logical::gen()
{
	std::stringstream buf;
	std::string s;
	int f = newLabel();
	int a = newLabel();
	Temp* temp = new Temp(type);
	this->jumping(0, f);
	emit(temp->toString + " = true");
	buf << "goto L" << a << std::endl;
	std::getline(buf, s);
	emit(s);
	emitLabel(f);
	emit(temp->toString() + " = false");
	emitLabel(a);
	return temp;
}

std::string Logical::toString()
{
	return expr1->toString() + " " + op->getText() + " " + expr2->toString();
}

