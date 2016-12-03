#pragma once

#include "Scanner.h"


namespace Calculator
{

	class Parser
	{
	public:
		Parser(std::string exp) :scanner_(exp)
		{

		}

	public:
		double						exp();
		double						exp3();
		double						exp2();
		double						exp1();
		double						term();

	public:
		inline virtual void handleAddExp(double &lhs) = 0;
		inline virtual void handleSubExp(double &lhs) = 0;
		inline virtual void handleMulExp(double &lhs) = 0;
		inline virtual void handleDivExp(double &lhs) = 0;
		inline virtual void handleSquareExp(double &lhs) = 0;
		inline virtual void handleTermExp(double &lhs) = 0;

	protected:
		Scanner scanner_;
	};

	inline double Parser::exp()
	{
		return exp3();
	}



	class ExpParser : public Parser
	{
	public:
		ExpParser(std::string exp) : Parser(exp)
		{

		}

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
	};




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











