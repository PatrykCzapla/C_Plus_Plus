#include <iostream>

#include "Interpreter.hpp"

int main()
{
	using namespace SimpleInterpreter;


	std::cout << "===================================== Etap 1 =====================================" << std::endl;
	{
		Interpreter interpreter;

		std::cout << "============= Pusty interpreter =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("12.3");
		interpreter.Push("7.7");

		std::cout << "============= 2 elementy na stosie (7.7 i 12.3) =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Add();

		std::cout << "============= Suma 7.7 + 12.3 = 20.0 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("2.5");
		interpreter.Subtract();

		std::cout << "============= Odjecie wyniku od 2.5 (2.5 - 20 = -17.5) =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("7.25");
		interpreter.Push("10");
		interpreter.Push("201.5");

		interpreter.Divide();
		interpreter.Add();

		std::cout << "============= Dzielenie i dodawanie (201.5 / 10 + 7.25 = 27.4). Na stosie 27.4 i -17.5 =============" << std::endl;
		std::cout << interpreter << std::endl;	
	}
	std::cout << "===================================== Etap 2 =====================================" << std::endl;
	{
		Interpreter interpreter;

		interpreter.Push("12.3");
		interpreter.Push("Num1");

		std::cout << "============= Na stosie Num1 i 12.3 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.CreateVariable();

		std::cout << "============= Stworzenie zmiennej Num1 = 12.3 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("Num1");
		interpreter.Push("2.3");
		interpreter.Subtract();

		std::cout << "============= 2.3 - Num1 = -10.0 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("Num1");
		interpreter.Store();

		std::cout << "============= Num1 = -10 =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("9.87");
		interpreter.Push("Num1");
		interpreter.Multiply();
		interpreter.Push("Num2");
		interpreter.CreateVariable();

		std::cout << "============= Num2 = Num1 * 9.87 (Num2 = -98.7) =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("Num2");
		interpreter.Push("Num1");
		interpreter.CreateVariable();

		std::cout << "============= Num1 = Num2 (2 zmienne Num1 i 1 Num2) =============" << std::endl;
		std::cout << interpreter << std::endl;

		interpreter.Push("8.7");
		interpreter.Push("Num1");
		interpreter.Add();
		interpreter.Push("Num1");
		interpreter.Store();

		std::cout << "============= Wyswietl Num1 (druga) (-90) =============" << std::endl;
		interpreter.Push("Num1");
		interpreter.Print();

		interpreter.Push("Num1");
		interpreter.RemoveVariable();

		std::cout << "============= Wyswietl Num1 (pierwsza) (-10) =============" << std::endl;
		interpreter.Push("Num1");
		interpreter.Print();

		std::cout << "============= 2 zmienne. Num1 = -10, Num2 = -98.7 =============" << std::endl;
		std::cout << interpreter << std::endl;
	}
	system("pause");
//	std::cout << "===================================== Etap 3 =====================================" << std::endl;
//	{
//		std::vector<Operation> mainOperations = {
//			// Create Num1
//			{ OperationTypes::Push, "123.3" },
//			{ OperationTypes::Push, "Num1" },
//			{ OperationTypes::CreateVariable, "" },
//
//			// Print Num1
//			{ OperationTypes::Push, "Num1" },
//			{ OperationTypes::Print, "" },
//
//			// stack = Num1 + 7
//			{ OperationTypes::Push, "7" },
//			{ OperationTypes::Push, "Num1" },
//			{ OperationTypes::Add, "" },
//
//			// Num1 = stack
//			{ OperationTypes::Push, "Num1" },
//			{ OperationTypes::Store, "" },
//
//			// Print Num1
//			{ OperationTypes::Push, "Num1" },
//			{ OperationTypes::Print, "" },
//		};
//
//		Interpreter interpreter;
//		interpreter.SetOperations(mainOperations);
//
//		std::cout << "============= Przed wykonaniem =============" << std::endl;
//		std::cout << interpreter << std::endl;
//
//		interpreter.Execute();
//
//		std::cout << "============= Po wykonaniu =============" << std::endl;
//		std::cout << interpreter << std::endl;
//	}
//
//	std::cout << "===================================== Etap 4 =====================================" << std::endl;
//	{
//		std::vector<std::pair<std::string, std::string>> invalidOperations = {
//			// Set last param
//			{ "Push", "2" },
//			{ "Push", "Param3" },
//			{ "CreateVariable", "" },
//
//			// Set second param
//			{ "Push", "3" },
//			{ "Push", "Param2" },
//			{ "CreateVariable", "" },
//
//			// Set first param
//			{ "Push", "4" },
//			{ "Push", "Param1" },
//			{ "CreateVariable", "" },
//
//			// Param1 * Param1
//			{ "Push", "Param1" },
//			{ "Push", "Param1" },
//			{ "Multiply", "" },
//
//			// Param2 * Param2
//			{ "Push", "Param2" },
//			{ "Push", "Param2" },
//			{ "Multiply", "" },
//
//			{ "InvalidOp", "123" }
//		};
//
//		std::vector<std::pair<std::string, std::string>> mainOperations = {
//			// Set last param
//			{ "Push", "2" },
//			{ "Push", "Param3" },
//			{ "CreateVariable", "" },
//
//			// Set second param
//			{ "Push", "3" },
//			{ "Push", "Param2" },
//			{ "CreateVariable", "" },
//
//			// Set first param
//			{ "Push", "4" },
//			{ "Push", "Param1" },
//			{ "CreateVariable", "" },
//
//			// Param1 * Param1
//			{ "Push", "Param1" },
//			{ "Push", "Param1" },
//			{ "Multiply", "" },
//
//			// Param2 * Param2
//			{ "Push", "Param2" },
//			{ "Push", "Param2" },
//			{ "Multiply", "" },
//
//			// Param3 * Param3
//			{ "Push", "Param3" },
//			{ "Push", "Param3" },
//			{ "Multiply", "" },
//
//			// Param3^2 + Param2^2
//			{ "Add", "" },
//
//			// (Param3^2 + Param2^2) + Param1^2
//			{ "Add", "" },
//
//			// Create result
//			{ "Push", "Result" },
//			{ "CreateVariable", "" },
//
//			// Remove first param
//			{ "Push", "Param1" },
//			{ "RemoveVariable", "" },
//
//			// Remove second param
//			{ "Push", "Param2" },
//			{ "RemoveVariable", "" },
//
//			// Remove last param
//			{ "Push", "Param3" },
//			{ "RemoveVariable", "" },
//
//			// Print Result
//			{ "Push", "Result" },
//			{ "Print", "" },
//
//			// Push invalid variable name
//			{ "Push", "Param1" },
//			{ "Push", "Result" },
//			{ "Multiply", "" },
//		};
//
//
//		Interpreter interpreter;
//
//		std::cout << "============= Blad parsowania =============" << std::endl;
//		try
//		{
//			interpreter.ParseOperations(invalidOperations);
//		}
//		catch (const std::exception& exc)
//		{
//			std::cout << "ERROR: " << exc.what() << std::endl;
//		}
//
//		interpreter.ParseOperations(mainOperations);
//
//		std::cout << "============= Przed wykonaniem =============" << std::endl;
//		std::cout << interpreter << std::endl;
//
//		std::cout << "============= Blad \"Invalid value\" na ostatniej lini (Multiply). Result = 29 =============" << std::endl;
//		interpreter.Execute();
//
//		std::cout << "============= Po wykonaniu (Result = 29) =============" << std::endl;
//		std::cout << interpreter << std::endl;
//	}
//
//	return 0;
}