// Calculator.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Expression.h"

#include <iostream>

int main(int argc, char* argv[])
{
	//if (argc > 1)
	//{
	//	auto text = std::string(argv[1]);
	//	auto exp = Calculator::Expression(text);
	//	std::cout << text << " = " << exp.result() << std::endl;
	//}
	//
	//return 0;

	while (true)
	{
		std::cout << "expression: ";
		std::string exp;
		std::cin >> exp;

		std::cout << "result: " << Calculator::Expression(exp).result() << std::endl;
		std::cout << std::endl;
	}

	system("PAUSE");
	return 0;
}



