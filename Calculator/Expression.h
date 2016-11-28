#pragma once

#include "Parser.h"

namespace Calculator
{
	class Expression
	{
	public:
		Expression(std::string exp) : exp_(exp)
		{
			;
		}

	public:
		double result();

	private:
		std::string exp_;
	};

	inline double Expression::result()
	{
		Parser parser = Parser(exp_);
		return parser.exp();
	}
}




