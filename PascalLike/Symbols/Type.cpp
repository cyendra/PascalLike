#include "Type.h"


Type::Type()
{
}

Type::Type(VarType t)
{
	type = t;
}

Type::~Type()
{
}

bool Type::isType(VarType t)
{
	return t == type;
}

