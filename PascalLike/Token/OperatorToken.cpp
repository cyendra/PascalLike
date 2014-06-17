#include "OperatorToken.h"


OperatorToken::OperatorToken(const char* s) :IdToken(s)
{
	tag = Operator;
}


OperatorToken::~OperatorToken()
{
}



