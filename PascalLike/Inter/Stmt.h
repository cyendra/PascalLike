#pragma once
#include "Node.h"
class Stmt :public Node
{
public:
	Stmt();
	virtual ~Stmt();
	virtual void gen(int b, int a);
	int after;
};

