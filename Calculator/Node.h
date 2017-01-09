#pragma once

#include "Scanner.h"

namespace Calculator
{
	class Visitor;

	class Node
	{
	public:
		Node(Token token, Node* left = nullptr, Node* right = nullptr) : token_(token), left_(left), right_(right) { ; }

	public:
		inline virtual double accept(Visitor *visitor) = 0;

	public:
		TokenType					type();
		std::string					value();
		Node*						left();
		Node*						right();

	private:
		Token token_;
		Node* left_;
		Node* right_;
	};

	class PlusNode : public Node
	{
	public:
		PlusNode(Token token, Node* left = nullptr, Node* right = nullptr) : Node(token, left, right) { ; }

	public:
		virtual double accept(Visitor *visitor);
	};

	class MinusNode : public Node
	{
	public:
		MinusNode(Token token, Node* left = nullptr, Node* right = nullptr) : Node(token, left, right) { ; }
	public:
		virtual double accept(Visitor *visitor);
	};

	class MulNode : public Node
	{
	public:
		MulNode(Token token, Node* left = nullptr, Node* right = nullptr) : Node(token, left, right) { ; }

	public:
		virtual double accept(Visitor *visitor);
	};

	class DivNode : public Node
	{
	public:
		DivNode(Token token, Node* left = nullptr, Node* right = nullptr) : Node(token, left, right) { ; }

	public:
		virtual double accept(Visitor *visitor);
	};

	class NumberNode : public Node
	{
	public:
		NumberNode(Token token, Node* left = nullptr, Node* right = nullptr) : Node(token, left, right) { ; }

	public:
		virtual double accept(Visitor *visitor);
	};




	inline TokenType Node::type()
	{
		return token_.type();
	}

	inline std::string Node::value()
	{
		return token_.value();
	}

	inline Node* Node::left()
	{
		return left_;
	}

	inline Node* Node::right()
	{
		return right_;
	}

}

