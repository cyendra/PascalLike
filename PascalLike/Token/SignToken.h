#pragma once
#include "Token.h"
class SignToken :public Token
{
public:
	SignToken(Token::Tag t);
	~SignToken();
	unsigned long long hashCode();
	std::string getText();
};

