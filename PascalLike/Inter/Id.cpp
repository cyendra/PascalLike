#include "Id.h"


Id::Id(IdToken* tok, Type p, int b) :Expr(tok, p)
{
	offset = b;
}


Id::~Id()
{
}
