#include "Parser.h"


Parser::Parser()
{
	top = nullptr;
	used = 0;
	move();
}


Parser::~Parser()
{
}

void Parser::move()
{
	try{
		look = lex.read();
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;;
	}
}

void Parser::error(std::string err)
{
	std::stringstream buf;
	std::string s;
	buf << "near line " << lex.getLineNumber() << ": " << err << std::endl;
	std::getline(buf, s);
	throw std::exception(s.c_str());
}

void Parser::match(std::string s)
{
	if (look->isWord(s.c_str())) move();
	else error("syntax error " + s);
}

void Parser::match(Token::Type tp)
{
	if (look->isType(tp)) move();
	else error("type error");
}

void Parser::match(Token::Tag tg)
{
	if (look->isTag(tg)) move();
	else error("tag error");
}

void Parser::program()
{
	Stmt* s = block();
	int begin = s->newLabel();
	int after = s->newLabel();
	s->emitLabel(begin);
	s->gen(begin, after);
	s->emitLabel(after);
}

Stmt* Parser::block()
{
	match("begin");
	Env* savedEnv = top;
	top = new Env(top);
	decls();
	Stmt* s = stmts();
	match("end");
	match(";");
	top = savedEnv;
	return s;
}

void Parser::decls()
{
	while (look->isWord("var"))
	{
		match("var");
		Token* tok = look;
		match(Token::Identifier);
		match(":");
		Type p = type();
		top->put(tok->getText(), (IdToken*)tok);
	}
}

Type Parser::type()
{
	Type p;
	if (look->isWord("integer")) p = Type::integer;
	if (look->isWord("real")) p = Type::real;
	if (look->isWord("boolean")) p = Type::boolean;
	if (look->isWord("string")) p = Type::string;
	match(Token::Identifier);
	return p;
}

Stmt* Parser::stmts()
{
	if (look->isWord("end")) return Stmt::NullStmt;
	return new Seq(stmt(), stmts());
}

Stmt* Parser::stmt()
{
	Expr* x;
	Stmt *s, *s1, *s2;
	Stmt* savedStmt;
	if (look->isWord(";"))
	{
		move();
		return Stmt::NullStmt;
	}
}

Stmt* Parser::assign()
{

}

Expr* Parser::boolean()
{

}

Expr* Parser::join()
{

}

Expr* Parser::equality()
{

}

Expr* Parser::rel()
{

}

Expr* Parser::expr()
{

}

Expr* Parser::term()
{

}

Expr* Parser::unary()
{

}

Expr* Parser::factor()
{

}
