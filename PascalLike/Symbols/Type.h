#pragma once
class Type
{
public:
	enum VarType
	{
		UnkownVarType, integer, real, string, boolean
	};
	Type();
	Type(VarType t);
	~Type();
	bool isType(VarType t);
	static bool numeric(Type p);
	static Type max(Type p1, Type p2);
	bool operator==(Type& t)
	{
		if (t.isType(type)) return true;
		return false;
	}
private:
	VarType type;
};

