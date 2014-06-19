#include "Reader.h"


Reader::Reader(std::istream &i) :in(i)
{
	lineNumber = 0;
	endOfFile = false;
}


Reader::~Reader()
{
	
}

void Reader::resetLine()
{
	lineNumber = 0;
}

int Reader::getLineNumber()
{
	return lineNumber;
}

bool Reader::hasMore()
{
	return !endOfFile;
}

std::string Reader::readLine()
{
	std::string str;
	lineNumber++;
	if (std::getline(in, str))
	{
		return str;
	}
	else
	{
		endOfFile = true;
		return "";
	}

}