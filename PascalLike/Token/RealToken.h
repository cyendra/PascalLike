#pragma once
#include "NumToken.h"
class RealToken :public NumToken
{
public:

	RealToken(double v);
	~RealToken();

	// 获取词法单元的哈希值
	unsigned long long hashCode();
	// 获取字面字符串
	std::string getText();

	// 获取实型的值
	double getDouble();

private:
	// 实型的值
	double value;
	// 计算哈希值的种子
	const unsigned long long SEED = 49999;
};

