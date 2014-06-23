#pragma once
#include "Stmt.h"
class Break :public Stmt
{
public:
	Break();
	virtual ~Break();
	Stmt* stmt;
	virtual void gen(int b, int a);
};

