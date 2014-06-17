#include "Token.h"


Token::Token()
{
	type = Unknown;
	tag = None;
	
}
Token::~Token()
{

}

bool Token::isType(Type t)
{
	return type == t;
}

bool Token::isTag(Tag t)
{
	return tag == t;
}

Token::Type Token::getType()
{
	return type;
}

Token::Tag Token::getTag()
{
	return tag;
}

int Token::getInt()
{
	throw std::exception("Token can not getInt");
}

double Token::getDouble()
{
	throw std::exception("Token can not getDouble");
}

std::string Token::getString()
{
	throw std::exception("Token can not getString");
}

bool Token::isWord(const char* s)
{
	throw std::exception("Token can not test Word");
}

std::set<std::string> Token::words = {
	"if", "else"
};

bool Token::inReserved(const char* s)
{
	if (words.find(s) != words.end()) return true;
	return false;
}