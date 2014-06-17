#include "Token\Token.h"
#include "Token\IntegerToken.h"
using namespace std;

template <class T>
T func()
{
	int a = 1;
	return a;
}

int main()
{
	cout << Token::inReserved("if") << endl;
	cout << Token::inReserved("twww") << endl;
	getchar();
}