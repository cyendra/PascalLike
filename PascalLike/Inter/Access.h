#pragma once
#include "Op.h"
// �������ʱ������
class Access :public Op
{
public:
	Access(Token* a, Expr* i, Type p);
	virtual ~Access();
	Token* arr;
	Expr* idx;
	virtual Expr* gen();
	virtual void jumping(int t, int f);
	virtual std::string toString();
};

