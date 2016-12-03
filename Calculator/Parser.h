#pragma once

#include "Scanner.h"


namespace Calculator
{




	class ExpParser
	{
	public:
		ExpParser(std::string exp) :scanner_(exp)
		{

		}

	public:
		double						exp();
		double						exp3();
		double						exp2();
		double						exp1();
		double						term();

	public:
		inline void handleAddExp(double &lhs)
		{
			scanner_.skipChar();
			lhs += exp3();
		}
		inline void handleSubExp(double &lhs)
		{
			scanner_.skipChar();
			lhs -= exp3();
		}
		inline void handleMulExp(double &lhs)
		{
			scanner_.skipChar();	
			lhs *= exp2();
		}
		inline void handleDivExp(double &lhs)
		{
			scanner_.skipChar();
			lhs /= exp2();
		}
		inline void handleSquareExp(double &lhs)
		{
			scanner_.skipChar();
			lhs = pow(lhs, exp1());
		}
		inline void handleTermExp(double &lhs)
		{
			lhs = scanner_.getToken().value();
		}

	private:
		Scanner scanner_;
	};

	inline double ExpParser::exp()
	{
		return exp3();
	}


	class AsmParser
	{
	public:
		AsmParser(std::string exp) :scanner_(exp)
		{

		}

	public:
		std::string					exp();
		std::string					exp3();
		std::string					exp2();
		std::string					term();

	public:
		std::string toThreeDecimals(double decimal);

	private:
		Scanner scanner_;

	};

	inline std::string AsmParser::exp()
	{
		return exp3();
	}

	inline std::string AsmParser::toThreeDecimals(double decimal)
	{
		std::string buffer = std::to_string(decimal);
		return std::string(buffer.begin(), buffer.end() - 3);
	}









	






}











