#pragma once
#include "../std.h"
class Matcher
{
public:
	enum Group
	{
		Unkown, Integer, Real, String, Literal, Operator
	};
	Matcher();
	~Matcher();
	void match(std::string);
	std::string scan();
	bool hasNext();
	Group group;
private:
	void readch();
	bool readch(char c);
	bool endOfLine;
	char peek;
	std::string str;
	int pos;
	int beginPos;
};

