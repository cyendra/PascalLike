#include "ReservedToken.h"


ReservedToken::ReservedToken(const char* s) :IdToken(s)
{
	tag = Reserved;
}


ReservedToken::~ReservedToken()
{
}


