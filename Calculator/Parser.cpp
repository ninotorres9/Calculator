
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

double ExpParser::exp3()
{
	auto lhs = exp2();

	while (!scanner_.isEndOfExp() && scanner_.peekChar() != ')')
	{
		switch (scanner_.peekChar())
		{
		case '+':
			handleAddExp(lhs);
			break;
		case '-':
			handleSubExp(lhs);
			break;
		default:
			break;
		}
	}

	return lhs;
}

double ExpParser::exp2()
{
	auto lhs = exp1();

	switch (scanner_.peekChar())
	{
	case '*':
		handleMulExp(lhs);
		break;
	case '/':
		handleDivExp(lhs);
		break;
	default:
		break;
	}

	return lhs;
}

double ExpParser::exp1()
{
	auto lhs = term();

	switch (scanner_.peekChar())
	{
	case '^':
		handleSquareExp(lhs);
		break;
	default:
		break;
	}

	return lhs;
}


double ExpParser::term()
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
		handleTermExp(result);
	}

	return result;

}



std::string AsmParser::exp3()
{
	auto lhs = exp2();

	while (!scanner_.isEndOfExp() && scanner_.peekChar() != ')')
	{
		switch (scanner_.peekChar())
		{
		case '+':
			scanner_.getChar();	// skip
			lhs += exp3();
			lhs += std::string("pop eax\n") + "pop ebx\n" + "add eax, ebx\n" + "push eax\n";
			break;
		case '-':
			scanner_.getChar();	//skip
			lhs += exp3();
			lhs += std::string("pop eax\n") + "pop ebx\n" + "sub eax, ebx\n" + "push eax\n";
			break;
		default:
			break;
		}
	}

	return lhs;
}

std::string AsmParser::exp2()
{
	auto lhs = term();

	switch (scanner_.peekChar())
	{
	case '*':
		scanner_.getChar();	// skip
		lhs += exp2();
		lhs += std::string("pop eax\n") + "pop ebx\n" + "imul eax, ebx\n" + "push eax\n";
		break;
	case '/':
		scanner_.getChar();	//skip
		lhs += exp2();
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


