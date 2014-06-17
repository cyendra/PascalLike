#include "StrToken.h"


StrToken::StrToken(std::string v) :Token()
{
	type = String;
	value = v;
}


StrToken::~StrToken()
{
}

std::string StrToken::getString()
{
	return value;
}

std::string StrToken::getText()
{
	return value;
}

unsigned long long StrToken::hashCode()
{
	unsigned long long hs = 0;
	int len = value.length();
	for (int i = 0; i < len; i++)
	{
		hs = hs * SEED + value[i];
	}
	return hs;
}