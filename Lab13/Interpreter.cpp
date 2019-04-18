#include "Interpreter.hpp"

namespace SimpleInterpreter
{
#pragma region Etap 0
	
	// Konwertuje tekst na float. Jesli sie nie da, to rzuca wyjatkiem.
	float Interpreter::StringToFloat(const std::string& valueStr)
	{
		float value;
		std::stringstream stream{ valueStr };
		if (!(stream >> value))
			throw std::runtime_error{ "Invalid value" };
		return value;
	}

	// Konwertuje float na tekst
	std::string Interpreter::FloatToString(float value)
	{
		std::stringstream stream;
		stream << value;
		return stream.str();
	}

	// Wykonuje funkcje odpowiadajaca podanej operacji.
	void Interpreter::ExecuteOperation(const Operation& operation)
	{
		switch (operation.OperationType)
		{
			case OperationTypes::CreateVariable:
			CreateVariable();
			break;

			case OperationTypes::RemoveVariable:
			RemoveVariable();
			break;

			case OperationTypes::Store:
			Store();
			break;

			case OperationTypes::Push:
			Push(operation.Param);
			break;

			case OperationTypes::Print:
			Print();
			break;

			case OperationTypes::Add:
			Add();
			break;

			case OperationTypes::Subtract:
			Subtract();
			break;

			case OperationTypes::Multiply:
			Multiply();
			break;

			case OperationTypes::Divide:
			Divide();
			break;

			default:
			throw std::runtime_error{ "Invalid operation" };
		}
	}

	std::ostream& operator << (std::ostream& out, const Interpreter& interpreter)
	{
		out << "VARIABLES:" << std::endl;
		interpreter.PrintVariables(out);

		out << "OPERATIONS:" << std::endl;
		interpreter.PrintOperations(out);

		out << "OPERATIONS QUEUE:" << std::endl;
		interpreter.PrintOperationsQueue(out);

		out << "DATA STACK:" << std::endl;
		interpreter.PrintDataStack(out);

		return out;
	}

#pragma endregion

#pragma region Etap 1

	// Etap 1:
	// Zwracana jest wartoœæ ze szczytu stosu (przekonwertowana ze string na float).
	// Etap 2:
	// Jesli wartosc na szczycie stosu to nazwa zmiennej, to zwraca jej wartosc.
	// W przeciwnym wypadku zwraca wartoœæ ze stosu (przekonwertowana ze string na float).
	float Interpreter::PopValue()
	{
		// Etap 1
		/*float w = StringToFloat(stos.top());
		stos.pop();
		return w;*/
		// Etap 2
		std::string w = stos.top();
		auto it = mapa.upper_bound(w);
		if (it == mapa.begin())
		{
			float w = StringToFloat(stos.top());
			stos.pop();
			return w;
		}
		stos.pop();
		it--;
		float k = it->second;
		return k;
	}

	// Zamienia wartosc na string i wrzuca na stos.
	void Interpreter::PushValue(float value)
	{
		// Etap 1
		std::string wartosc = FloatToString(value);
		stos.push(wartosc);
	}

	// Wrzuca string na stos.
	void Interpreter::Push(const std::string& param)
	{
		// Etap 1
		stos.push(param);
	}
	
	// Sciaga 2 elementy ze stosu, dodaje je, wynik zapisuje na stosie.
	void Interpreter::Add()
	{
		// Etap 1
		float a = PopValue();
		float b = PopValue();
		PushValue(a + b);
	}

	// Sciaga 2 elementy ze stosu, odejmuje od pierwszego drugi, wynik zapisuje na stosie.
	void Interpreter::Subtract()
	{
		// Etap 1
		float a = PopValue();
		float b = PopValue();
		PushValue(a - b);
	}

	// Sciaga 2 elementy ze stosu, mnozy pierwszy przez drugi, wynik zapisuje na stosie.
	void Interpreter::Multiply()
	{
		// Etap 1
		float a = PopValue();
		float b = PopValue();
		PushValue(a * b);
	}

	// Sciaga 2 elementy ze stosu, dzieli pierwszy przez drugi, wynik zapisuje na stosie.
	void Interpreter::Divide()
	{
		// Etap 1
		float a = PopValue();
		float b = PopValue();
		PushValue(a / b);
	}
	
	void Interpreter::PrintDataStack(std::ostream& out) const
	{
		// Etap 1
		std::stack<std::string> s = stos;
		int  i = 0;
		while (!s.empty())
		{
			out << i << ": " << s.top() << std::endl;
			s.pop();
			i++;
		}
		
	}

#pragma endregion

#pragma region Etap 2

	// Zwraca string ze szczytu stosu
	std::string Interpreter::PopName()
	{
		// Etap 2
		std::string w=stos.top();
		stos.pop();
		return w;
	}

	// Pobiera nazwe zmiennej ze stosu, nastepnie jej wartosc i tworzy zmienna.
	void Interpreter::CreateVariable()
	{
		// Etap 2
		std::string nazwa = PopName();
		float wartosc = PopValue();
		mapa.insert(make_pair(nazwa, wartosc));
	}

	// Pobiera nazwe zmiennej ze stosu i usuwa ja.
	void Interpreter::RemoveVariable()
	{
		// Etap 2
		std::string w = stos.top();
		auto it = mapa.upper_bound(w);
		if (it == mapa.begin() && ((--it)->first) != w)
		{
			return;
		}
		mapa.erase(--it);
	}

	// Pobiera nazwe zmiennej ze stosu, pobiera wartosc ze stosu i przypisuje zmiennej wartosc.
	void Interpreter::Store()
	{
		// Etap 2
		std::string nazwa = PopName();
		float wartosc = PopValue();
		auto it = mapa.upper_bound(nazwa);
		(--it)->second = wartosc;
	}
	
	// Sciaga wartosc ze stosu i ja drukuje na ekran.
	void Interpreter::Print()
	{
		// Etap 2
		float w = PopValue();
		std::cout << w;
	}
	
	void Interpreter::PrintVariables(std::ostream& out) const
	{
		// Etap 2
		auto it1 = mapa.begin();
		auto it2 = mapa.end();
		std::for_each(it1, it2, [&out](std::pair<std::string,float> el) {
			out << el.first << ' ' << el.second << std::endl;
		}
		);
	}

#pragma endregion

#pragma region Etap 3

	void Interpreter::SetOperations(const std::vector<Operation>& operations)
	{
		// Etap 3
	}

	// Wykonuje caly program
	void Interpreter::Execute()
	{
		// Etap 3
	}

	void Interpreter::PrintOperations(std::ostream& out) const
	{
		// Etap 3
	}

	void Interpreter::PrintOperationsQueue(std::ostream& out) const
	{
		// Etap 3
	}

#pragma endregion

#pragma region Etap 4

	void Interpreter::ParseOperations(const std::vector<std::pair<std::string, std::string>>& operations)
	{
		// Etap 4
	}

#pragma endregion
}
