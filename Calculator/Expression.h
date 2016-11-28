#pragma once

#include "Parser.h"

namespace Calculator
{
	extern "C" __declspec(dllexport) double expression(std::string exp)
	{
		Parser parser = Parser(exp);
		return parser.exp();
	}

	extern "C" __declspec(dllexport)const char* demo(const char* a)
	{
		return a;
	}
}





