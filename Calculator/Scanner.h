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
		char							peekChar();
		char							getChar();
		void							skipChar(int);

	public:
		Token							getToken();
		Token							peekToken();
		std::vector<Token>				getTokenList();
		std::string						getNumber();

	public:
		bool							isEndOfExp();
		double							toDouble(std::string);
		
	private:
		std::string						exp_;
		size_t							index_;

	};





	inline char Scanner::peekChar()
	{
		if (exp_.size() != 0)
		{
			return isEndOfExp() ? exp_[exp_.size() - 1] : exp_[index_];
		}
		else
		{
			return char('-1');
		}
	}

	inline char Scanner::getChar()
	{
		return isEndOfExp() ? exp_[exp_.size() - 1] : exp_[index_++];
	}

	inline void Scanner::skipChar(int num = 1)
	{
		for (auto each : std::vector<int>(num))
		{
			getChar();
		}
	}

	inline Token Scanner::peekToken()
	{
		std::string str(exp_.begin() + index_, exp_.end());
		Scanner temp = Scanner(str);
		return temp.getToken();
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

	inline std::string Scanner::getNumber()
	{
		std::string value;
		while (isdigit(peekChar()) && !isEndOfExp())
		{
			value.push_back(getChar());
		}
		return value;
	}
}