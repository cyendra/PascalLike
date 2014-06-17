#include "IdToken.h"


IdToken::IdToken(const char* s) :Token()
{
	type = Identifier;
	tag = None;
}


IdToken::~IdToken()
{
}

bool IdToken::isWord(const char* s)
{
	return value == s;
}

std::string IdToken::getText()
{
	return value;
}

unsigned long long IdToken::hashCode()
{
	unsigned long long hs = 0;
	int len = value.length();
	for (int i = 0; i < len; i++)
	{
		hs = hs * SEED + value[i];
	}
	return hs;
}
