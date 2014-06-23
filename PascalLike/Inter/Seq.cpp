#include "Seq.h"


Seq::Seq(Stmt* s1, Stmt* s2)
{
	stmt1 = s1;
	stmt2 = s2;
}


Seq::~Seq()
{
}

void Seq::gen(int b, int a)
{
	if (stmt1 == Stmt::NullStmt) stmt2->gen(b, a);
	else if (stmt2 == Stmt::NullStmt) stmt1->gen(b, a);
	else
	{
		int label = newLabel();
		stmt1->gen(b, label);
		emitLabel(label);
		stmt2->gen(label, a);
	}
}
