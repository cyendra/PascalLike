#include "Expr.h"


Expr::Expr(Token* tok, Type p)
{
	op = tok;
	type = p;
}


Expr::~Expr()
{
}


Expr* Expr::gen()
{
	return this;
}

Expr* Expr::reduce()
{
	return this;
}

void Expr::jumping(int t, int f)
{
	emitjumps(toString(), t, f);
}

void Expr::emitjumps(std::string test, int t, int f)
{
	std::stringstream stm;
	
	std::string s;
	
	if (t != 0 && f != 0)
	{
		stm << "if " << test << " goto L" << t << std::endl;
		std::getline(stm, s);
		emit(s);
		stm << "goto L" << f << std::endl;
		std::getline(stm, s);
		emit(s);
	}
	else if (t != 0)
	{
		stm << "if " << test << " goto L" << t << std::endl;
		std::getline(stm, s);
		emit(s);
	}
	else if (f != 0)
	{
		stm << "iffalse" << test << " goto L" << f << std::endl;
		std::getline(stm, s);
	}
}

std::string Expr::toString()
{
	return op->getText();
}