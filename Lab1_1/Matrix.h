#pragma once

#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

class MatrixException : public logic_error
{
public:
	MatrixException(string message) : logic_error(message) {}
};

template<class T> class Matrix
{
private:
	T * coefficients;
	int rows, cols, size;
public:
	Matrix(int row, int col)
	{
		rows = row;
		cols = col;
		size = rows*cols;  
		coefficients = new T[size];
		for (int i = 0; i < size; i++)
		{
			coefficients[i] = 0;
		}
	}
	Matrix(int row, int col, T* tab)
	{
		rows = row;
		cols = col;
		size = rows*cols;
		coefficients = new T[size];
		for (int i = 0; i < size; i++)
		{
			coefficients[i] = tab[i];
		}
	}
	Matrix(const Matrix<T>& a) 
	{
		rows = a.rows;
		cols = a.cols;
		size = rows*cols;
		coefficients = new T[size];
		for (int i = 0; i < size; i++)
		{
			coefficients[i] = a.coefficients[i];
		}
	}
	~Matrix()
	{
		delete[] coefficients;
	}

	int GetRows() const
	{
		return rows;
	}
	int GetColumns() const
	{
		return cols;
	}

	friend ostream& operator<<(ostream& out,const Matrix<T>& a) 
	{
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				out << a.coefficients[j + i*a.cols] << " ";
			}
			out << endl;
		}
		out << endl;
		return out;
	}
	T& operator()(int row, int col) 
	{
		return coefficients[col + row*cols];
	}
	T operator()(int row, int col) const
	{
		return coefficients[col + row*cols];
	}

	friend bool operator!=(const Matrix<T>& a, const Matrix<T>& b) 
	{
		if (b.rows != a.rows || b.cols != a.cols) return true;
		for (int i = 0; i < a.size; i++)
		{
			if (b.coefficients[i] != a.coefficients[i])return true;
		}
		return false;
	}

	Matrix<T> operator-(const Matrix<T>& a) const
	{
		if (rows != a.rows || cols != a.cols) throw MatrixException("Dimensions do not match");
		Matrix<T> b(rows, cols, coefficients);
		for (int i = 0; i < size; i++)
		{
			b.coefficients[i] -= a.coefficients[i];
		}
		return b;
	}
	Matrix<T> operator-() const
	{
		Matrix<T> a(rows, cols);
		for (int i = 0; i < size; i++)
		{
			a.coefficients[i]-= coefficients[i];
		}
		return a;
	}

	Matrix<T>& operator=(const Matrix<T>& a)
	{
		if (this != &a)
		{
			if (rows != a.rows || cols != a.cols)
			{
				size = a.size;
				rows = a.rows;
				cols = a.cols;
				delete[] coefficients;
				coefficients = new T[size];
			}
			size = a.size;
			rows = a.rows;
			cols = a.cols;
			for (int i = 0; i < size; i++)
			{
				coefficients[i] = a.coefficients[i];
			}
		}
		return *this;
	}

	Matrix<T> operator*(const Matrix<T>& a)
	{
		if (cols != a.rows) throw MatrixException("Dimensions do not match");
		Matrix<T> b(rows, a.cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				for (int k = 0; k < cols; k++)
				{
					b.coefficients[i*cols+j] += coefficients[k+i*cols] * a.coefficients[j*a.cols+k];
				}
			}
		}
		return b;
	}
	Matrix<T> operator*=(const Matrix<T>& a)
	{
		Matrix<T> b(rows, cols, coefficients);
		b = b*a;
		return b;
	}
	Matrix<T> operator*(T a)
	{
		Matrix<T> b(rows, cols, coefficients);
		for (int i = 0; i < size; i++)
		{
			b.coefficients[i] = b.coefficients[i]* a;
		}
		return b;
	}

// uzupe³niæ

};