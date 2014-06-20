#pragma once
#include "Expr.h"
class Temp :public Expr
{
public:
	Temp(Type p);
	virtual ~Temp();
	virtual std::string toString();

	static int count;
	int number;
	static std::vector<Token*> temps;
	static Token* getTempToken();
};

