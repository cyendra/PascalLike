#pragma once
#include "../std.h"
#include "../Lexer/Lexer.h"
class Node
{
public:
	Node();
	virtual ~Node();
protected:
	int lexLine;
	virtual void error(std::string s);
	static int labels;
public:
	virtual int newLabel();
	virtual void emitLabel(int i);
	virtual void emit(std::string s);
};

