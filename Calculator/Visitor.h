#pragma once

#include "Node.h"

namespace Calculator
{

	class Visitor
	{
	public:
		inline double visit(PlusNode* node)
		{
			return node->left()->accept(this) + node->right()->accept(this);
		}

		inline double visit(MinusNode* node)
		{
			return node->left()->accept(this) - node->right()->accept(this);
		}

		inline double visit(MulNode* node)
		{
			return node->left()->accept(this) * node->right()->accept(this);
		}

		inline double visit(DivNode* node)
		{
			return node->left()->accept(this) / node->right()->accept(this);
		}

		inline double visit(NumberNode* node)
		{
			return toDouble(node->value());
		}

		inline double toDouble(std::string str)
		{
			std::istringstream stream(str);
			double result;
			stream >> result;
			return result;
		}
	};
}