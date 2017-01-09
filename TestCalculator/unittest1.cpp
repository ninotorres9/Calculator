#include "stdafx.h"
#include "CppUnitTest.h"
#include "Scanner.h"
#include "Parser.h"
#include "Node.h"
#include "Visitor.h"
#include "Expression.h"

#include <vector>
#include <memory>
#include <exception>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Calculator;

namespace TestCalculator
{		



	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestTokenType)
		{
			TokenType tokenType = TokenType::NUMBER;
		}

		TEST_METHOD(TestScanner_GetChar)
		{
			Scanner scanner("1+2");
			Assert::AreEqual(scanner.getChar(), '1', L"Get first char");
			Assert::AreEqual(scanner.getChar(), '+', L"Get second char");
			Assert::AreEqual(scanner.getChar(), '2', L"Get last char");
			Assert::AreEqual(scanner.getChar(), '2', L"End of expression");
			Assert::IsTrue(scanner.isEndOfExp(), L"Is end of expression");
		}

		TEST_METHOD(TestScanner_SkipChar)
		{
			Scanner scanner = Scanner("1+2");
			scanner.skipChar();
			Assert::AreEqual(scanner.peekChar(), '+', L"skip 1 char");

			scanner = Scanner("1+5");
			scanner.skipChar(2);
			Assert::AreEqual(scanner.peekChar(), '5', L"skip 2 char");
		}

		TEST_METHOD(TestScanner_PeekChar)
		{
			Scanner scanner = Scanner("2");
			Assert::AreEqual(scanner.peekChar(), '2', L"Peek first char");
			Assert::AreEqual(scanner.peekChar(), '2', L"peek end of expression");
		}

		TEST_METHOD(TestScanner_PeekChar_Null)
		{
			Scanner scanner = Scanner("");
			Assert::AreEqual(scanner.peekChar(), char('-1'), L"Peek first char");
		}

		//TEST_METHOD(TestScanner_GetToken_Null)
		//{
		//	auto scanner = Scanner("");
		//	auto token = scanner.getToken();
		//	//Assert::IsTrue(token.type() == TokenType::NUMBER, L"Get token type : decimal");
		//	//Assert::IsTrue(token.value() == "1.5", L"Get token value : 1.5");
		//}

		TEST_METHOD(TestScanner_GetToken_Decimal)
		{
			auto scanner = Scanner("1.5");
			auto token = scanner.getToken();
			Assert::IsTrue(token.type() == TokenType::NUMBER, L"Get token type : decimal");
			Assert::IsTrue(token.value() == "1.5", L"Get token value : 1.5");
		}

		TEST_METHOD(TestScanner_GetToken_Integer)
		{
			auto scanner = Scanner("50");
			auto token = scanner.getToken();
			Assert::IsTrue(token.type() == TokenType::NUMBER, L"Get token type : decimal");
			Assert::IsTrue(token.value() == "50", L"Get token value : 50");
		}

		TEST_METHOD(TestScanner_GetToken_Plus)
		{
			auto scanner = Scanner("+");
			auto token = scanner.getToken();
			Assert::IsTrue(token.type() == TokenType::PLUS, L"Get token type : plus");
			Assert::IsTrue(token.value() == "+", L"Get token value : +");
		}

		TEST_METHOD(TestScanner_GetToken_Minus)
		{
			auto scanner = Scanner("-");
			auto token = scanner.getToken();
			Assert::IsTrue(token.type() == TokenType::MINUS, L"Get token type : minus");
			Assert::IsTrue(token.value() == "-", L"Get token value : -");
		}

		TEST_METHOD(TestScanner_GetToken_Mul)
		{
			auto scanner = Scanner("*");
			auto token = scanner.getToken();
			Assert::IsTrue(token.type() == TokenType::MUL, L"Get token type : mul");
			Assert::IsTrue(token.value() == "*", L"Get token value : *");
		}

		TEST_METHOD(TestScanner_GetToken_Div)
		{
			auto scanner = Scanner("/");
			auto token = scanner.getToken();
			Assert::IsTrue(token.type() == TokenType::DIV, L"Get token type : div");
			Assert::IsTrue(token.value() == "/", L"Get token value : /");
		}

		TEST_METHOD(TestScanner_PeekToken)
		{
			auto scanner = Scanner("23");
			Assert::IsTrue(scanner.peekToken().value() == "23", L"Peek token");	
		}

		TEST_METHOD(TestScanner_PeekToken_Exp)
		{
			auto scanner = Scanner("1+2");
			scanner.getToken();
			Assert::IsTrue(scanner.peekToken().type() == TokenType::PLUS,	L"Peek token");
		}

		TEST_METHOD(TestScanner_GetTokenList)
		{
			auto scanner = Scanner("1+2");
			auto list = scanner.getTokenList();
			Assert::IsTrue(list[0].type() == TokenType::NUMBER, L"list_1 type : number");
			Assert::IsTrue(list[1].type() == TokenType::PLUS,	L"list_2 type : plus");
		}

		TEST_METHOD(TestParser_Plus)
		{
			Parser parser = Parser("1+2");
			auto node = parser.node();
			Assert::IsTrue(node->value() == "+", L"root type : +");
			Assert::IsTrue(node->left()->value() == "1");
			Assert::IsTrue(node->right()->value() == "2");
		}

		TEST_METHOD(TestParser_Minus)
		{
			Parser parser = Parser("1-2");
			auto node = parser.node();
			Assert::IsTrue(node->value() == "-", L"root type : -");
		}

		TEST_METHOD(TestParser_Mul)
		{
			Parser parser = Parser("1*2");
			auto node = parser.node();
			Assert::IsTrue(node->value() == "*", L"root type : *");
		}

		TEST_METHOD(TestParser_Div)
		{
			Parser parser = Parser("1/2");
			auto node = parser.node();
			Assert::IsTrue(node->value() == "/", L"root type : /");
		}

		TEST_METHOD(TestParser_MulAndPlus)
		{
			Parser parser = Parser("1*2+3");
			auto node = parser.node();
			Assert::IsTrue(node->value() == "+", L"root type : +");
			Assert::IsTrue(node->left()->value() == "*", L"left type : *");
		}

		TEST_METHOD(TestNode_Visitor)
		{
			Visitor* visitor = new Visitor();

			auto plusNode = Parser("1+2").node();
			Assert::AreEqual(plusNode->accept(visitor), 3.0, L"1 + 2 = 3.0");

		}

		TEST_METHOD(TestNode_Expression)
		{
			auto expression = Expression("1+2");
			Assert::AreEqual(expression.result(), 3.0, L"1 + 2 = 3.0");

			expression = Expression("3-1");
			Assert::AreEqual(expression.result(), 2.0, L"3 - 1 = 2.0");

			expression = Expression("3*1");
			Assert::AreEqual(expression.result(), 3.0, L"3 * 1 = 3.0");

			expression = Expression("10/2");
			Assert::AreEqual(expression.result(), 5.0, L"10 / 2 = 5.0");

			expression = Expression("1*5+2");
			Assert::AreEqual(expression.result(), 7.0, L"1 * 5 + 2 = 7.0");
		}


	};
}



