#pragma once
#include "../std.h"
#include "../Token/alltoken.h"
class Env
{
public:
	Env();
	Env(Env* n);
	~Env();
	void put(std::string w, IdToken* id);
	IdToken* get(std::string w);
protected:
	Env* prev;
private:
	std::map<std::string, IdToken*> table;
};

