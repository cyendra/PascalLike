#pragma once
#include "../std.h"
#include "../Lexer/Lexer.h"
#include "../Symbols/Type.h"
class Node
{
public:
	Node();
	virtual ~Node();
	virtual void error(std::string s);
protected:
	int lexLine;
	static int labels;
public:
	virtual int newLabel();
	virtual void emitLabel(int i);
	virtual void emit(std::string s);
};

