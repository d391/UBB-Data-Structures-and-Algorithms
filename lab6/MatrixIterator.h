#pragma once
#include "Matrix.h"

class Matrix;

class MatrixIterator
{
	friend class Matrix;
private:
	Matrix mat;
	int line;
	int currentCol = 0;

public:
	MatrixIterator(Matrix& m, int l) : mat{ m }, line{l} 
	{
		if (l >= this->mat.nrLines() || l < 1)
			throw std::exception();
	};
	void first();
	void next();
	TElem getCurrent();
	bool valid();
	~MatrixIterator();
};

