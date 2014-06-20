#pragma once
#include "Expr.h"
class Id :public Expr
{
public:
	Id(IdToken* tok, Type p, int b);
	virtual ~Id();
	int offset;
};

