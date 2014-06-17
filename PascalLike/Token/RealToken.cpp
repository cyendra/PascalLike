#include "RealToken.h"


RealToken::RealToken(double v) :NumToken()
{
	value = v;
	tag = Real;
}


RealToken::~RealToken()
{
}

unsigned long long RealToken::hashCode()
{
	unsigned long long hs = 0;
	do
	{
		hs += (unsigned long long)value * SEED;
		value /= 1000;
	} while (value < 1e-6);
	return hs;
}

double RealToken::getDouble()
{
	return value;
}

std::string RealToken::getText()
{
	std::string s;
	std::stringstream os;
	os << value;
	os >> s;
	return s;
}