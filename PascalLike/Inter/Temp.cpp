#include "Temp.h"


Temp::Temp(Type p) :Expr(getTempToken(),p)
{
	number = ++count;
}


Temp::~Temp()
{
}

Token* Temp::getTempToken()
{
	IdToken* tok = new IdToken("[$Temp]");
	temps.push_back(tok);
	return tok;
}

std::string Temp::toString()
{
	std::string s;
	std::stringstream buf;
	buf << "t" << number << std::endl;
	std::getline(buf, s);
	return s;
}

int Temp::count = 0;