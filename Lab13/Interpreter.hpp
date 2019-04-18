#ifndef SIMPLE_INTERPRETER_INTERPRETER_HPP
#define SIMPLE_INTERPRETER_INTERPRETER_HPP

#include "Operation.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
namespace SimpleInterpreter
{
	class Interpreter
	{
	private:
		static float StringToFloat(const std::string& valueStr);
		static std::string FloatToString(float value);
		std::stack<std::string> stos;
		std::multimap<std::string, float> mapa;
		std::string PopName();
		float PopValue();
		void PushValue(float value);

		void ExecuteOperation(const Operation& operation);

	public:
		void CreateVariable();
		void RemoveVariable();

		void Store();
		void Push(const std::string& param);
		void Print();

		void Add();
		void Subtract();
		void Multiply();
		void Divide();

		void SetOperations(const std::vector<Operation>& operations);
		void ParseOperations(const std::vector<std::pair<std::string, std::string>>& operations);
		
		void Execute();

		void PrintOperations(std::ostream& out) const;
		void PrintOperationsQueue(std::ostream& out) const;
		void PrintDataStack(std::ostream& out) const;
		void PrintVariables(std::ostream& out) const;

		friend std::ostream& operator << (std::ostream& out, const Interpreter& interpreter);
	};
}

#endif // !SIMPLE_INTERPRETER_INTERPRETER_HPP
