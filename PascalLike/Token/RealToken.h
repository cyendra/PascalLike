#pragma once
#include "NumToken.h"
class RealToken :public NumToken
{
public:

	RealToken(double v);
	~RealToken();

	// ��ȡ�ʷ���Ԫ�Ĺ�ϣֵ
	unsigned long long hashCode();
	// ��ȡ�����ַ���
	std::string getText();

	// ��ȡʵ�͵�ֵ
	double getDouble();

private:
	// ʵ�͵�ֵ
	double value;
	// �����ϣֵ������
	const unsigned long long SEED = 49999;
};

