#pragma once
#include "Token.h"
class IdToken :public Token
{
public:
	IdToken(const char* s);
	virtual ~IdToken();

	virtual bool isWord(const char* s);

	// 获取词法单元的哈希值，哈希函数由子类自行决定
	unsigned long long hashCode();

	// 获取词法单元的字面书写字符串
	std::string getText();
private:
	std::string value;
	const unsigned long long SEED = 239933;
};

