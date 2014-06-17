#include "IntegerToken.h"

IntegerToken::IntegerToken(int v) :NumToken()
{
	value = v;
	tag = Integer;
}


IntegerToken::~IntegerToken()
{
}


unsigned long long IntegerToken::hashCode()
{
	unsigned long long hs = 0;
	while (value)
	{
		hs += value % 1000 * SEED;
		value /= 1000;
	}
	return hs;
}

int IntegerToken::getInt()
{
	return value;
}

std::string IntegerToken::getText()
{
	std::string s;
	std::stringstream os;
	os << value;
	os >> s;
	return s;
}