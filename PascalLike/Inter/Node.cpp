#include "Node.h"


Node::Node()
{
	lexLine = Lexer::getLineNumber();
}


Node::~Node()
{
}


void Node::error(std::string s)
{
	std::stringstream buf;
	buf << "near line " << lexLine << ": " << s;
	std::string err;
	std::getline(buf, err);
	throw std::exception(err.c_str());
}

int Node::newLabel()
{
	return ++labels;
}
	
void Node::emitLabel(int i)
{
	std::cout << "L" << i << ":";
}

void Node::emit(std::string s)
{
	std::cout << "\t" << s << std::endl;
}

int Node::labels = 0;