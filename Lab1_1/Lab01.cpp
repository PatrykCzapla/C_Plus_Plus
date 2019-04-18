#include "Matrix.h"

int main()
{
	double coeffs[] = { 1,2,3,4,5,6,7,8,9 };
	double coeffsReversed[] = { 9,8,7,6,5,4,3,2,1 };

	double coeffsLonger[30];
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 10; j++)
			coeffsLonger[10 * i + j] = k++;

	//--------------ETAP I---------------

	cout << "-------------------- ETAP I------------------------------" << endl;

	Matrix<int> m(5, 5);
	Matrix<double> m1(1, 1);
	const Matrix<double> m3(3, 3, coeffs);
	Matrix<double> m3b(3, 3, coeffsReversed);
	Matrix<double> m2 = m3;
	Matrix<double> m4(10, 3, coeffsLonger);
	Matrix<double> m5(3, 10, coeffsLonger);

	cout << m;
	cout << m1;
	cout << m2;
	cout << m3;
	cout << m3b;
	cout << m4;
	cout << m5;

	cout << "rows = " << m.GetRows() << ", columns = " << m.GetColumns() << endl;
	cout << "rows = " << m2.GetRows() << ", columns = " << m2.GetColumns() << endl;
	cout << "rows = " << m3.GetRows() << ", columns = " << m3.GetColumns() << endl;
	cout << "rows = " << m4.GetRows() << ", columns = " << m4.GetColumns() << endl;
	cout << "rows = " << m5.GetRows() << ", columns = " << m5.GetColumns() << endl;


	cout << "-------------------- ETAP II------------------------------" << endl;
	cout << m1(0, 0) << endl;
	cout << m3(2, 1) << endl;

	m2(1, 1) = 99;

	m1 = m2;
	cout << m1;
	auto tmp = m3-m3b;
	cout << tmp;

	tmp = -m3b;
	cout << tmp;

	cout << tmp - m3b;
	bool areNotEqual = m1 != m3;
	cout << boolalpha << areNotEqual << endl;

	m1(1, 1) = m3(1, 1);

	areNotEqual = m1 != m3;
	cout << areNotEqual << endl;


	cout << "-------------------- ETAP III------------------------------" << endl;

	double tab1[] = { 1,4,6,10,2,7,5,3 };
	double tab1a[] = { 3,3,2,2,2,1,1,1 };
	double tab2[] = { 1,4,6,2,7,5,9,0,11,3,1,0 };
	auto tmp1 = Matrix<double>(2, 4, tab1);
	auto tmp1a = Matrix<double>(2, 4, tab1a);
	auto tmp2 = Matrix<double>(4, 3, tab2);

	cout << tmp1;
	cout << tmp2;

	auto tmp3 = tmp1 * tmp2;
	cout << tmp3;

	tmp3 = tmp1 * 0.5 - tmp1a * 0.2;
	cout << tmp3;

	tmp1 = tmp1 * 2;

	cout << tmp1;

	tmp1 *= tmp2;
	cout << tmp1;

	cout << "-------------------- ETAP IV------------------------------" << endl;

	//dodac odpowiednie wyjatki, wtedy kiedy trzeba

	/*try {
		auto test_exception1 = tmp2 * tmp2;
	}
	catch (MatrixException &e)
	{
		cout << e.what() << endl;
	}
	try {
		auto test_exception2 = tmp2 - tmp1;
	}
	catch (MatrixException &e)
	{
		cout << e.what() << endl;
	}
	try {
		double exception_value1 = tmp2(-1, 0);
	}
	catch (MatrixException &e)
	{
		cout << e.what() << endl;
	}
	try {
		double exception_value2 = tmp2(10, 10);
	}
	catch (MatrixException &e)
	{
		cout << e.what() << endl;
	}*/

	return 0;
}
