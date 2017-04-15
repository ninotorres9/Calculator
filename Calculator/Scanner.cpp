


#include "stdafx.h"
#include "Scanner.h"

using namespace Calculator;


Token Scanner::getToken()
{
	skipSpace();

	auto firstChar = peekChar();

	if (isdigit(firstChar))
	{
		return getNumberToken();
	}
	else if (firstChar == '+') 
	{
		skipChar();	//skip the plus
		return Token(TokenType::PLUS, "+");
	}
	else if (firstChar == '-')
	{
		skipChar();	//skip the plus
		return Token(TokenType::MINUS, "-");
	}
	else if (firstChar == '*')
	{
		skipChar();	//skip the plus
		return Token(TokenType::MUL, "*");
	}
	else if (firstChar == '/')
	{
		skipChar();	//skip the plus
		return Token(TokenType::DIV, "/");
	}
	else if (firstChar == '^')
	{
		skipChar();	// skip the power
		return Token(TokenType::POWER, "^");
	}
	else
	{
		return Token(TokenType::INVALID, "0.0");
	}
}