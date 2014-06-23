#pragma once
#include "Stmt.h"
class Seq :public Stmt
{
public:
	Seq(Stmt* s1, Stmt* s2);
	virtual ~Seq();
	Stmt* stmt1;
	Stmt* stmt2;
	virtual void gen(int b, int a);

};

