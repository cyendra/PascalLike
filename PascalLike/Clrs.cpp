#include "Clrs.h"


Clrs::Clrs()
{
}


Clrs::~Clrs()
{
}

void Clrs::gao()
{
	std::cout << "GAO" << std::endl;
}
Clrs Clrs::c;
Clrs* Clrs::p = &c;
Clrs* Clrs::wow = new Clrs();