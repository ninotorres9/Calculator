
#include "stdafx.h"
#include "Node.h"
#include "Visitor.h"


namespace Calculator
{
	double PlusNode::accept(Visitor *visitor)
	{
		return visitor->visit(this);
	}

	double MinusNode::accept(Visitor *visitor)
	{
		return visitor->visit(this);
	}

	double MulNode::accept(Visitor *visitor)
	{
		return visitor->visit(this);
	}

	double DivNode::accept(Visitor *visitor)
	{
		return visitor->visit(this);
	}

	double PowerNode::accept(Visitor *visitor)
	{
		return visitor->visit(this);
	}

	double NumberNode::accept(Visitor *visitor)
	{
		return visitor->visit(this);
	}
}