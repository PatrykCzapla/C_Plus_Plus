#ifndef SIMPLE_INTERPRETER_OPERATION_HPP
#define SIMPLE_INTERPRETER_OPERATION_HPP

#include <string>
#include <iostream>

namespace SimpleInterpreter
{
	enum OperationTypes
	{
		CreateVariable,
		RemoveVariable,

		Store,
		Push,
		Print,
		
		Add,
		Subtract,
		Multiply,
		Divide,
	};

	struct Operation
	{
		OperationTypes OperationType;
		std::string Param;

		Operation(OperationTypes operationType, const std::string& param = "");

		friend std::ostream& operator << (std::ostream& out, const Operation& operation);
	};
}

#endif // !SIMPLE_INTERPRETER_OPERATION_HPP
