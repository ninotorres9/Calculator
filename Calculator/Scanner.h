#pragma once

#include "Token.h"

#include <string>
#include <sstream>
#include <vector>


namespace Calculator
{

	class Scanner
	{
	public:
		Scanner(std::string exp) :exp_(exp), index_(0) { ; }

	public:
		char							currentChar();
		char							peekChar();
		char							getChar();
		void							skipChar(int);
		void							skipSpace();

	public:
		Token							getToken();
		Token							peekToken();
		std::vector<Token>				getTokenList();

	public:
		Token							getNumberToken();
		std::string						getDecimal();
		std::string						getInteger();

	public:
		bool							isEndOfExp();
		std::string						restOfExpression();
		double							toDouble(std::string);
		
	private:
		std::string						exp_;
		size_t							index_;

	};

	inline char Scanner::peekChar()
	{
		return isEndOfExp() ? char('-1') : exp_[index_];
	}

	inline char Scanner::currentChar()
	{
		return exp_[index_];
	}

	inline char Scanner::getChar()
	{
		if (isEndOfExp())
		{
			return exp_[exp_.size() - 1];
		}
		else
		{
			return exp_[index_++];
		}
	}

	inline void Scanner::skipChar(int num = 1)
	{
		for (auto each : std::vector<int>(num)) { getChar(); }
	}

	inline void Scanner::skipSpace()
	{
		while (peekChar() == ' ')
		{
			getChar();
		}
	}

	inline Token Scanner::peekToken()
	{
		return Scanner(restOfExpression()).getToken();
	}

	inline std::string Scanner::restOfExpression()
	{
		return std::string(exp_.begin() + index_, exp_.end());	// index to end
	}

	inline std::vector<Token> Scanner::getTokenList()
	{
		std::vector<Token> tokenList;
		while (!isEndOfExp())
		{
			tokenList.push_back(getToken());
		}
		return tokenList;
	}

	inline bool Scanner::isEndOfExp()
	{
		return index_ >= exp_.size() ? true : false;
	}

	inline double Scanner::toDouble(std::string str)
	{
		std::istringstream stream(str);
		double result;
		stream >> result;
		return result;
	}

	inline Token Scanner::getNumberToken()
	{
		std::string value;
		value.append(getInteger());
		if (peekChar() == '.')
		{
			value.append(getDecimal());
		}
		return Token(TokenType::NUMBER, value);
	}

	inline std::string Scanner::getInteger()
	{
		std::string value;
		while (isdigit(peekChar()) && !isEndOfExp())
		{
			value.push_back(getChar());
		}
		return value;
	}

	inline std::string Scanner::getDecimal()
	{
		std::string value;
		value.push_back(getChar());		// dog
		value.append(getInteger());	
		return value;
	}
}