#include "Env.h"

Env::Env()
{
	prev = nullptr;
}

Env::Env(Env* n)
{
	prev = n;
}


Env::~Env()
{
}


void Env::put(std::string w, IdToken* id)
{
	table.insert(std::make_pair(w,id));
}

IdToken* Env::get(std::string w)
{
	for (Env* e = this; e != nullptr; e = e->prev)
	{
		auto found = e->table.find(w);
		if (found != e->table.end())
		{
			return found->second;
		}
	}
	return nullptr;
}