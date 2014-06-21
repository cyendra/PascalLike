#include "Constant.h"


Constant::Constant(Token* tok, Type p) :Expr(tok,p)
{

}


Constant::~Constant()
{
}

void Constant::jumping(int t, int f)
{
	std::stringstream buf;
	std::string s;
	if (this->op->isWord("true") && t != 0)
	{
		buf << "goto L" << t << std::endl;
		std::getline(buf, s);
		emit(s);
	}
	else if (this->op->isWord("false") && f != 0)
	{
		buf << "goto L" << f << std::endl;
		std::getline(buf, s);
		emit(s);
	}

}
