#include "stdafx.h"
#include "CppUnitTest.h"
#include "Parser.h"
#include "Expression.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Calculator;

namespace TestCalculator
{		



	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestTokenType)
		{
			TokenType tokenType = TokenType::DECIMAL;
		}

		TEST_METHOD(TestToken)
		{
			Assert::AreEqual(Token(TokenType::DECIMAL, 1.5).value(), 1.5, L"Assign to token value");
		}

		TEST_METHOD(TestScanner)
		{

			Assert::AreEqual(Scanner("1+2").exp(), std::string("1+2"), L"Assign to expression");
			Assert::AreEqual(Scanner("2+3").exp(), std::string("2+3"), L"Assign to expression");

			// get char
			Scanner scanner("1+2");
			Assert::AreEqual(scanner.getChar(), '1', L"Get first char");
			Assert::AreEqual(scanner.getChar(), '+', L"Get second char");
			Assert::AreEqual(scanner.getChar(), '2', L"Get last char");
			Assert::AreEqual(scanner.getChar(), '2', L"End of expression");
			Assert::IsTrue(scanner.isEndOfExp(), L"Is end of expression");

			// peek char
			scanner = Scanner("2");
			Assert::AreEqual(scanner.peekChar(), '2', L"Peek first char");
			Assert::AreEqual(scanner.peekChar(), '2', L"peek end of expression");
			
			// token type
			scanner = Scanner("1");
			Assert::IsTrue(scanner.getToken().type() == TokenType::DECIMAL, L"Get token type");

			// integer
			scanner = Scanner("2");
			Assert::AreEqual(scanner.getToken().value(), 2.0, L"Get token value for integer");

			// multidigit integer
			scanner = Scanner("32");
			Assert::AreEqual(scanner.getToken().value(), 32.0, L"Get token value for mult integer");

			// opening of the 0
			scanner = Scanner("005");
			Assert::AreEqual(scanner.getToken().value(), 5.0, L"Omit the opening of the 0");

			// decimal
			scanner = Scanner("1.5");
			Assert::AreEqual(scanner.getToken().value(), 1.5, L"Get token for decimal");

			// invalid token
			scanner = Scanner("+");
			Assert::IsTrue(scanner.getToken().type() == TokenType::INVALID, L"Invalid token");
	
			// peek token
			scanner = Scanner("23");
			Assert::AreEqual(scanner.peekToken().value(), 23.0, L"Peek token");
			Assert::AreEqual(scanner.peekToken().value(), 23.0, L"Peek token");

		
		}

		

		TEST_METHOD(TestParser)
		{

			Parser parser = Parser("1+2");
			Assert::AreEqual(parser.exp(), 3.0, L"Expression result for add");

			parser = Parser("3-3+3-3");
			Assert::AreEqual(parser.exp(), 0.0, L"Expression result for add and sub");

			parser = Parser("3*2");
			Assert::AreEqual(parser.exp(), 6.0, L"Expression result for mul");

			parser = Parser("3+2*5/2-1");
			Assert::AreEqual(parser.exp(), 7.0, L"Expression result for four operations");

			parser = Parser("(10+2)");
			Assert::AreEqual(parser.exp(), 12.0, L"Expression result for parenthesis");

			parser = Parser("(10+2)*3*(1+2)");
			Assert::AreEqual(parser.exp(), 108.0, L"Expression result for mixed");

			parser = Parser("0.5*2+10");
			Assert::AreEqual(parser.exp(), 11.0, L"Expression result for demical");

		}

		//class Calculator
		//{
		//public:
		//	Calculator(std::string exp) : exp_(exp)
		//	{
		//		;
		//	}
		//
		//public:

		//	inline double Calculator::exp()
		//	{
		//		Parser parser = Parser(exp_);
		//		return parser.exp();
		//	}


		//private:
		//	std::string exp_;
		//};


		TEST_METHOD(TestExpression)
		{
			auto result = expression("1+2+3");
			Assert::AreEqual(result, 6.0, L"expression result");
		}

	};
}












