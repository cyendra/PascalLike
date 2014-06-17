#pragma once
#include "Token.h"
class StrToken :public Token
{
public:
	StrToken(std::string v);
	~StrToken();

	// 获取词法单元的哈希值
	unsigned long long hashCode();

	// 获取词法单元的字面书写字符串
	std::string getText();

	std::string getString();
private:
	std::string value;
	const unsigned long long SEED = 378551;
};

