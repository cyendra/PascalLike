#include "Type.h"


Type::Type()
{
	type = UnkownVarType;
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

bool Type::numeric(Type p)
{
	if (p.isType(Type::integer) || p.isType(Type::real)) return true;
	return false;
}

Type Type::max(Type p1, Type p2)
{
	if (p1.isType(Type::string) || p2.isType(Type::string)) return Type::string;
	if (p1.isType(Type::real) || p2.isType(Type::real)) return Type::real;
	if (p1.isType(Type::integer) || p2.isType(Type::integer)) return Type::integer;
	return Type::UnkownVarType;
}
