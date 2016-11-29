// Calculator.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Parser.h"

#include <iostream>
#include <fstream>

using namespace Calculator;

void toFile(std::string exp)
{
	AsmParser asmParser = AsmParser(exp);
	auto text = asmParser.exp();
	// char filename[] = "..."; // �˴�д���ļ��� 
	std::ofstream fout("d:\\demo.a");
	fout << text;
}

int main()
{
	toFile("1+2*3");
	return 0;
}



