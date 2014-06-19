#include "Matcher.h"


Matcher::Matcher()
{
	match("");
}


Matcher::~Matcher()
{
}

void Matcher::match(std::string s)
{
	str = s + '\0';
	beginPos = 0;
	pos = 0;
	peek = ' ';
	endOfLine = false;
	group = Unkown;
}

std::string Matcher::scan()
{
	for (;; readch())
	{
		if (peek == ' ' || peek == '\t') continue;
		else break;
	}

	if (peek == '\0')
	{
		endOfLine = true;
		return "";
	}
	group = Literal;
	
	switch (peek)
	{
	case ':':
		if (readch('=')) return ":=";
		else return ":";
	case '>':
		if (readch('=')) return ">=";
		else return ">";
	case '<':
		if (readch('>')) return "<>";
		if (readch('=')) return "<=";
		return "<";
	}
	
	if (peek == '\"')
	{
		group = String;
		beginPos = pos;
		do {
			readch();
		} while (peek != '\"');
		readch();
	
		return str.substr(beginPos, pos - beginPos - 2);
	}
	beginPos = pos - 1;

	if (isdigit(peek))
	{
		group = Integer;
		do {
			readch();
		} while (isdigit(peek));
		if (peek != ' ' && peek != '\t') throw std::exception("Bad Number(Integer)");
		if (peek != '.') return str.substr(beginPos, pos - beginPos - 1);
		group = Real;
		do {
			readch();
		} while (isdigit(peek));
		if (peek != ' ' && peek != '\t') throw std::exception("Bad Number(Real)");
		return str.substr(beginPos, pos - beginPos - 1);
	}
	group = Literal;

	if (isalpha(peek) || peek == '_')
	{
		do {
			readch();
		} while (isalnum(peek) || peek == '_');
		
		return str.substr(beginPos, pos - beginPos - 1);
	}
	std::string rs;
	rs += peek;
	peek = ' ';
	return rs;
}

bool Matcher::hasNext()
{
	if ((peek == ' ' || peek == '\t') && str[pos] == '\0') endOfLine = true;
	if (peek == '\0') endOfLine = true;
	return !endOfLine;
}

void Matcher::readch()
{
	if (pos == (int)str.length()) throw std::exception("Out Of String");
	if (peek == '\0') throw std::exception("End Of String");
	peek = str[pos++];
}

bool Matcher::readch(char c)
{
	readch();
	if (peek != c) return false;
	peek = ' ';
	return true;
}
