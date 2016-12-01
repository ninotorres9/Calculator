#pragma once

#include "Parser.h"
#include <iostream>
#include <fstream>


namespace Calculator
{
	class Expression
	{
	public:
		Expression(std::string text) : expParser_(text),  asmParser_(text)
		{
			
		}
	public:
		void						toFile(std::string fileName);
		double						result();

	private:
		ExpParser expParser_;
		AsmParser asmParser_;
		
	};

	inline void Expression::toFile(std::string fileName)
	{
		auto text = asmParser_.exp();
		std::ofstream fout(fileName);
		fout << text;
	}

	inline double Expression::result() { return expParser_.exp(); }

}





