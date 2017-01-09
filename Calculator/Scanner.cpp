


#include "stdafx.h"
#include "Scanner.h"

using namespace Calculator;


Token Scanner::getToken()
{
	if (isdigit(peekChar()))
	{
		std::string value;
		value.append(getNumber());
		if (peekChar() == '.')
		{
			value.push_back(getChar());
			value.append(getNumber());
		}
		return Token(TokenType::NUMBER, value);
	}
	else if (peekChar() == '+')
	{
		skipChar();	//skip the plus
		return Token(TokenType::PLUS, "+");
	}
	else if (peekChar() == '-')
	{
		skipChar();	//skip the plus
		return Token(TokenType::MINUS, "-");
	}
	else if (peekChar() == '*')
	{
		skipChar();	//skip the plus
		return Token(TokenType::MUL, "*");
	}
	else if (peekChar() == '/')
	{
		skipChar();	//skip the plus
		return Token(TokenType::DIV, "/");
	}
	else
	{
		return Token(TokenType::INVALID, "0.0");
	}
}