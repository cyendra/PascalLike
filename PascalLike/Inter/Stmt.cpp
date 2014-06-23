#include "Stmt.h"


Stmt::Stmt()
{
}


Stmt::~Stmt()
{
}

void Stmt::gen(int b, int a)
{

}

Stmt* Stmt::NullStmt = new Stmt();
Stmt* Stmt::Enclosing = Stmt::NullStmt;