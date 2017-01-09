#pragma once

#include "Parser.h"

#include <string>

namespace Calculator
{
	class Expression
	{
	public:
		Expression(std::string text);

	public:
		double						result();

	private:
		Node*						node_;
		Visitor*					visitor_;
	};





	Expression::Expression(std::string text)
	{
		Parser parser = Parser(text);
		node_ = parser.node();
	}

	inline double Expression::result()
	{
		return node_->accept(visitor_);
	}
}

