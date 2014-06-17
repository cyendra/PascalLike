#pragma once
#include "Token.h"
class IdToken :public Token
{
public:
	IdToken(const char* s);
	virtual ~IdToken();

	virtual bool isWord(const char* s);

	// ��ȡ�ʷ���Ԫ�Ĺ�ϣֵ����ϣ�������������о���
	unsigned long long hashCode();

	// ��ȡ�ʷ���Ԫ��������д�ַ���
	std::string getText();
private:
	std::string value;
	const unsigned long long SEED = 239933;
};

