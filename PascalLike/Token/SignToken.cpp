#include "SignToken.h"


SignToken::SignToken(Token::Tag t) :Token()
{
	if (t != Token::Eol && t != Token::Eof)
	{
		throw std::exception("Not Sign");
	}
	type = Sign;
	tag = t;
}


SignToken::~SignToken()
{
}


unsigned long long SignToken::hashCode()
{
	if (tag == Token::Eol)
	{
		return 139238472342LL;
	}
	if (tag == Token::Eof)
	{
		return 912340325123423LL;
	}
	throw std::exception("Sign Hash Error");
}

std::string SignToken::getText()
{
	if (tag == Token::Eol)
	{
		return "[$EOL]";
	}
	if (tag == Token::Eof)
	{
		return "[$EOF]";
	}
	throw std::exception("Sign Text Error");
}
