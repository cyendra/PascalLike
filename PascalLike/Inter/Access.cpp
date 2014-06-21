#include "Access.h"


Access::Access(Token* a, Expr* i, Type p) :Op(a,p)
{
	arr = a;
	idx = i;
}


Access::~Access()
{

}

Expr* Access::gen()
{
	return new Access(arr, idx->reduce(), type);
}

void Access::jumping(int t, int f)
{
	emitjumps(reduce()->toString(), t, f);
}

std::string Access::toString()
{
	return arr->getText() + " [ " + idx->toString() + " ]";
}
