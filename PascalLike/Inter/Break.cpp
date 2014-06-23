#include "Break.h"


Break::Break()
{
	if (Stmt::Enclosing == Stmt::NullStmt) error("unenclosed break");
	stmt = Stmt::Enclosing;
}


Break::~Break()
{
}

void Break::gen(int b, int a)
{
	std::stringstream buf;
	std::string s;
	buf << "goto L" << stmt->after << std::endl;
	std::getline(buf, s);
	emit(s);
}