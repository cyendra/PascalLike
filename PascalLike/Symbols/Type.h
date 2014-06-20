#pragma once
class Type
{
public:
	enum VarType
	{
		UnkownVarType, integer, real, string
	};
	Type();
	Type(VarType t);
	~Type();
	bool isType(VarType t);
	static bool numeric(Type p);
	static Type max(Type p1, Type p2);
private:
	VarType type;
};

