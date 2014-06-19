#pragma once
#include "../std.h"
class Reader
{
public:
	Reader(std::istream &i = std::cin);
	~Reader();
	std::string readLine();
	int getLineNumber();
	void resetLine();
	bool hasMore();
private:
	int lineNumber;
	bool endOfFile;
	std::istream &in;
};

