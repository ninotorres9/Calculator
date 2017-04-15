

#include "stdafx.h"
#include "Parser.h"

namespace Calculator
{
	Node* Parser::expNode2()
	{
		auto lhs = expNode1();

		if (scanner_.peekToken().type() == TokenType::PLUS)
		{
			auto op = scanner_.getToken();
			auto rhs = expNode2();

			return new PlusNode(op, lhs, rhs);
		}
		else if (scanner_.peekToken().type() == TokenType::MINUS)
		{
			auto op = scanner_.getToken();
			auto rhs = expNode2();

			return new MinusNode(op, lhs, rhs);
		}
		else
		{
			return lhs;
		}
	}

	Node* Parser::expNode1()
	{
		auto lhs = expNode0();

		if (scanner_.peekToken().type() == TokenType::MUL)
		{
			auto op = scanner_.getToken();
			auto rhs = expNode1();

			return new MulNode(op, lhs, rhs);
		}
		else if (scanner_.peekToken().type() == TokenType::DIV)
		{
			auto op = scanner_.getToken();
			auto rhs = expNode1();

			return new DivNode(op, lhs, rhs);
		}
		else
		{
			return lhs;
		}
	}

	Node* Parser::expNode0()
	{
		auto lhs = termNode();

		if (scanner_.peekToken().type() == TokenType::POWER)
		{
			auto op = scanner_.getToken();
			auto rhs = termNode();

			return new PowerNode(op, lhs, rhs);
		}
		else
		{
			return lhs;
		}
	}

	Node* Parser::termNode()
	{
		return new NumberNode(scanner_.getToken());
	}
}