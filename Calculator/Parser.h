#pragma once

#include "Scanner.h"
#include "Node.h"

namespace Calculator
{
	class Parser
	{
	public:
		Parser(std::string text) : scanner_(text) { ; }

	public:
		Node*						node();
		Node*						expNode2();
		Node*						expNode1();
		Node*						expNode0();
		Node*						termNode();
		
	private:
		Scanner scanner_;
	};

	inline Node* Parser::node()
	{
		return expNode2();
	}
}

