
#include "stdafx.h"
#include "Parser.h"

using namespace Calculator;


Token Scanner::getToken()
{
	if (!isdigit(peekChar()))
	{
		return Token(TokenType::INVALID, 0.0);
	}
	else
	{
		std::string value;
		value.append(getNumber());
		if (peekChar() == '.')
		{
			value.push_back(getChar());
			value.append(getNumber());
		}
		return Token(TokenType::DECIMAL, toDouble(value));
	}
}

double Parser::exp2()
{
	auto lhs = exp1();

	while (!scanner_.isEndOfExp() && scanner_.peekChar() != ')')
	{
		switch (scanner_.peekChar())
		{
		case '+':
			scanner_.getChar();	// skip
			lhs += exp2();
			break;
		case '-':
			scanner_.getChar();	//skip
			lhs -= exp2();
			break;
		default:
			break;
		}
	}

	return lhs;
}

double Parser::exp1()
{
	auto lhs = term();

	switch (scanner_.peekChar())
	{
	case '*':
		scanner_.getChar();	// skip
		lhs *= exp1();
		break;
	case '/':
		scanner_.getChar();	//skip
		lhs /= exp1();
		break;
	default:
		break;
	}

	return lhs;
}

double Parser::term()
{
	double result;

	if (scanner_.peekChar() == '(')
	{
		scanner_.getChar();	// skip
		result = exp();
		if (scanner_.peekChar() == ')')
		{
			scanner_.getChar(); //skip
		}
		else
		{
			;
		}

	}
	else
	{
		result = scanner_.getToken().value();
	}

	return result;

}









std::string AsmParser::exp2()
{
	// auto lhs = term();
	auto lhs = exp1();

	while (!scanner_.isEndOfExp() && scanner_.peekChar() != ')')
	{
		switch (scanner_.peekChar())
		{
		case '+':
			scanner_.getChar();	// skip
			lhs += exp2();
			lhs += std::string("pop eax\n") + "pop ebx\n" + "add eax, ebx\n" + "push eax\n";
			break;
		case '-':
			scanner_.getChar();	//skip
			lhs += exp2();
			lhs += std::string("pop eax\n") + "pop ebx\n" + "sub eax, ebx\n" + "push eax\n";
			break;
		default:
			break;
		}
	}

	return lhs;
}

std::string AsmParser::exp1()
{
	auto lhs = term();

	switch (scanner_.peekChar())
	{
	case '*':
		scanner_.getChar();	// skip
		lhs += exp1();
		lhs += std::string("pop eax\n") + "pop ebx\n" + "imul eax, ebx\n" + "push eax\n";
		break;
	case '/':
		scanner_.getChar();	//skip
		lhs += exp1();
		lhs += std::string("pop eax\n") + "pop ebx\n" + "idiv eax, ebx\n" + "push eax\n";
		break;
	default:
		break;
	}

	return lhs;
}

std::string AsmParser::term()
{
	std::string result;

	if (scanner_.peekChar() == '(')
	{
		scanner_.getChar();	// skip
		result = exp();
		if (scanner_.peekChar() == ')')
		{
			scanner_.getChar(); //skip
		}
		else
		{
			;
		}
	}
	else
	{
		auto decimal = toThreeDecimals(scanner_.getToken().value());
		result += std::string("push ") + decimal + "\n";
	}


	return result;
}


