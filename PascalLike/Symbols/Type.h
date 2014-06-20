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
private:
	VarType type;
};

