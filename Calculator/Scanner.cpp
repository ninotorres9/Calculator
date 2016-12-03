


#include "stdafx.h"
#include "Scanner.h"

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