#pragma once
#include "Token.h"
class StrToken :public Token
{
public:
	StrToken(std::string v);
	~StrToken();

	// ��ȡ�ʷ���Ԫ�Ĺ�ϣֵ
	unsigned long long hashCode();

	// ��ȡ�ʷ���Ԫ��������д�ַ���
	std::string getText();

	std::string getString();
private:
	std::string value;
	const unsigned long long SEED = 378551;
};

