#include "Operation.hpp"

namespace SimpleInterpreter
{
	Operation::Operation(OperationTypes operationType, const std::string& param) :
		OperationType{ operationType }, Param{ param }
	{
	}

	std::ostream& operator << (std::ostream& out, const Operation& operation)
	{
		out << "    ";
		switch (operation.OperationType)
		{
			case OperationTypes::CreateVariable:	out << "CreateVariable";	break;
			case OperationTypes::RemoveVariable:	out << "RemoveVariable";	break;
			case OperationTypes::Store:				out << "Store";				break;
			case OperationTypes::Push:				out << "Push";				break;
			case OperationTypes::Print:				out << "Print";				break;
			case OperationTypes::Add:				out << "Add";				break;
			case OperationTypes::Subtract:			out << "Subtract";			break;
			case OperationTypes::Multiply:			out << "Multiply";			break;
			case OperationTypes::Divide:			out << "Divide";			break;
		}

		if (!operation.Param.empty()) out << ": " << operation.Param;

		return out;
	}
}