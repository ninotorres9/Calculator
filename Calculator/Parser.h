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


	class Parser
	{
	public:
		Parser(std::string exp) :scanner_(exp)
		{

		}

	public:
		double						exp();
		double						exp2();
		double						exp1();
		double						term();

	private:
		Scanner scanner_;
	};

	inline double Parser::exp()
	{
		return exp2();
	}









	






}











