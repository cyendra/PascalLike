#pragma once
#include "Token.h"

// 数字类型的词法单元，是抽象类
class NumToken :public Token
{
public:	
	NumToken();
	virtual ~NumToken();
};

