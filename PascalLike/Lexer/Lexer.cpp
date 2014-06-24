#include "Lexer.h"

Lexer::Lexer()
{
	hasMore = true;

}


Lexer::~Lexer()
{
}

Token* Lexer::read()
{
	if (fillQueue(0))
	{
		Token* res = queue.front();
		queue.erase(queue.begin());
		if (res->isTag(Token::Eol)) line++;
		return res;
	}
	else
	{
		return new SignToken(Token::Eof);
	}
}

Token* Lexer::peek(int i)
{
	if (fillQueue(i))
	{
		return queue[i];
	}
	else
	{
		return new SignToken(Token::Eof);
	}
}

bool Lexer::fillQueue(int i)
{
	while (i >= (int)queue.size())
	{
		if (hasMore) readLine();
		else return false;
	}
	return true;
}

void Lexer::readLine()
{
	string line;
	line = reader.readLine();
	if (!reader.hasMore())
	{
		hasMore = false;
		return;
	}
	int lineNo = reader.getLineNumber();
	matcher.match(line);
	while (matcher.hasNext())
	{
		string tok = "";
		try{
			tok = matcher.scan();
		}
		catch (std::exception e)
		{
			std::cerr <<"line "<<lineNo<<" :"<< e.what() << std::endl;
			return;
		}
		addToken(tok);
	}
	//queue.push_back(new SignToken(Token::Eol));
}

void Lexer::addToken(string tok)
{
	Token* token = nullptr;
	if (matcher.group == Matcher::Integer)
	{
		int v;
		sscanf_s(tok.c_str(), "%d", &v);
		token = new IntegerToken(v);
	}
	else if (matcher.group == Matcher::Real)
	{
		double v;
		sscanf_s(tok.c_str(), "%f", &v);
		token = new RealToken(v);
	}
	else if (matcher.group == Matcher::String)
	{
		token = new StrToken(toStringLiteral(tok));
	}
	else if (matcher.group == Matcher::Literal)
	{
		if (Token::inReserved(tok.c_str()))
		{
			token = new ReservedToken(tok.c_str());
		}
		else
		{
			token = new IdToken(tok.c_str());
		}
	}
	else if (matcher.group == Matcher::Operator)
	{
		token = new OperatorToken(tok.c_str());
	}
	else
	{
		throw std::exception("Unkown Token");
	}
	queue.push_back(token);
}

Lexer::string Lexer::toStringLiteral(string s)
{
	string buf;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		char c = s[i];
		if (c == '\\' && i + 1 < len)
		{
			char c2 = s[i + 1];
			if (c2 == '"' || c2 == '\\')
			{
				c = s[++i];
			}
			else if (c2 == 'n')
			{
				++i;
				c = '\n';
			}
		}
		buf += c;
	}
	return buf;
}


int Lexer::getLineNumber()
{
	return line;
}

int Lexer::line = 1;