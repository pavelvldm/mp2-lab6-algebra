#include <iostream>
#include "postfix.h"
int main()
{
	int a;
	string check;
	std::cout << "infix:";
	std::cin >> check;
	TPostfix help(check);
	std::cout << endl << help.ToPostfix() << endl;
//	std::cout << "Hello world";
	std::cin >> a;
	
}