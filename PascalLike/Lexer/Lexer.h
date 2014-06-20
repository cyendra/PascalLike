#pragma once
#include "../std.h"
#include "../Token/alltoken.h"
#include "Reader.h"
#include "Matcher.h"
class Lexer
{
private:
	typedef std::vector<Token*> ArrayList;
	typedef std::string string;
public:
	Lexer();
	~Lexer();
	Token* read();
	Token* peek(int i);
	static int getLineNumber();
protected:
	void readLine();
	void addToken(string tok);
	string toStringLiteral(string s);
	static int line;
private:
	ArrayList queue;
	bool hasMore;
	Reader reader;
	bool fillQueue(int i);
	Matcher matcher;
};

