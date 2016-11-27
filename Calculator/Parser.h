#pragma once


#include <string>
#include <sstream>

namespace Calculator
{
	enum class TokenType
	{
		DECIMAL,
		INVALID,
	};

	class Token
	{	
	public:
		Token::Token(Token::TokenType type, double value) :type_(type), value_(value)
		{

		}

	public:
		TokenType					type();
		double						value();

	private:
		TokenType					type_;
		double						value_;
	};
	inline TokenType Token::type()
	{
		return type_;
	}
	inline double Token::value()
	{
		return value_;
	}




	class Scanner
	{
	public:
		Scanner(std::string exp) :exp_(exp), index_(0)
		{

		}

	public:
		char							peekChar();
		char							getChar();
		Token							getToken();
		Token							peekToken();

	public:
		std::string						exp();
		bool							isEndOfExp();
		double							toDouble(std::string);
		std::string						getNumber();

	private:
		std::string						exp_;
		size_t							index_;

	public:


	};
	inline char Scanner::peekChar()
	{
		return isEndOfExp() ? exp_[exp_.size() - 1] : exp_[index_];
	}

	inline char Scanner::getChar()
	{
		return isEndOfExp() ? exp_[exp_.size() - 1] : exp_[index_++];
	}

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

	inline Token Scanner::peekToken()
	{
		Scanner tempSc = Scanner(exp_);
		return tempSc.getToken();
	}

	inline std::string Scanner::exp()
	{
		return exp_;
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






