// Calculator.cpp : 定义 DLL 应用程序的导出函数。
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
	// char filename[] = "..."; // 此处写入文件名 
	std::ofstream fout("d:\\demo.a");
	fout << text;
}

int main()
{
	toFile("1+2*3");
	return 0;
}



