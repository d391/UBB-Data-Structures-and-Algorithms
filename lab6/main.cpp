#pragma once
#include "Matrix.h"
#include "MatrixIterator.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

int main()
{
	Matrix m{2,3};
	m.modify(1, 1, 2);
	m.modify(2, 2, 3);
	m.modify(1, 3, 4);
	MatrixIterator mi{ m, 1 };
	while (mi.valid())
	{
		std::cout << mi.getCurrent() << std::endl;
		mi.next();
	}
	testAll();
	testAllExtended();
	return 0;
}
