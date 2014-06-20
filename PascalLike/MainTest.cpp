#include "Lexer\Reader.h"

using namespace std;


int main()
{
	string s = "aaaaaaa";
	stringstream stm;
	stm << "goto L" << 123 <<endl;
	getline(stm, s);
	cout << s << endl;
	stm << "wwww" << 1244;
	getline(stm, s);
	cout << s << endl;

	getchar();
}