#pragma once

#include "Parser.h"



namespace Calculator
{
	double expression(std::string exp)
	{
		Parser parser = Parser(exp);
		return parser.exp();
	}

}





