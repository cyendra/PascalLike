#pragma once
#include "../std.h"
#include "../Token/alltoken.h"
#include "../Inter/allnode.h"
#include "../Symbols/Env.h"
class Parser
{
public:
	Parser();
	~Parser();
private:
	Lexer lex;
	Token* look;
	Env* top;
	int used;
	void move();
	void error(std::string s);
	void match(std::string s);
	void match(Token::Type);
	void match(Token::Tag);
	void program();
	Stmt* block();
	void decls();
	Type type();
	//Type dims(Type p);
	Stmt* stmts();
	Stmt* stmt();
	Stmt* assign();
	Expr* boolean();
	Expr* join();
	Expr* equality();
	Expr* rel();
	Expr* expr();
	Expr* term();
	Expr* unary();
	Expr* factor();
	//Access* offset(Token* a);
};

