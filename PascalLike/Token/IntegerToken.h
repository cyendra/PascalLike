#pragma once
#include "NumToken.h"
class IntegerToken :public NumToken
{
public:

	// ����һ��ֵΪv��������
	IntegerToken(int v);
	~IntegerToken();

	// ��ȡ�ʷ���Ԫ�Ĺ�ϣֵ
	unsigned long long hashCode();
	
	// ��ȡ���͵�ֵ
	int getInt();

	// ��ȡ�����ַ���
	std::string getText();

private:

	// ���͵�ֵ
	int value;

	// �����ϣֵ������
	const unsigned long long SEED = 13331;
};

