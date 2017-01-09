#pragma once

#include <string>

namespace Calculator
{
	enum class TokenType
	{
		NUMBER,
		PLUS,
		MINUS,
		MUL,
		DIV,
		INVALID,
	};

	class Token
	{
	public:
		Token::Token(Token::TokenType type, std::string value) :type_(type), value_(value) { ; }

	public:
		TokenType					type();
		std::string					value();

	private:
		TokenType					type_;
		std::string					value_;
	};


	inline TokenType Token::type()
	{
		return type_;
	}
	inline std::string Token::value()
	{
		return value_;
	}
}