#pragma once
#include "NumToken.h"
class IntegerToken :public NumToken
{
public:

	// 构造一个值为v的整型数
	IntegerToken(int v);
	~IntegerToken();

	// 获取词法单元的哈希值
	unsigned long long hashCode();
	
	// 获取整型的值
	int getInt();

	// 获取字面字符串
	std::string getText();

private:

	// 整型的值
	int value;

	// 计算哈希值的种子
	const unsigned long long SEED = 13331;
};

