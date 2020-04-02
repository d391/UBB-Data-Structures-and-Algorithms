#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedBag.h"
#include <iostream>

bool relation(TComp e1, TComp e2)
{
	return e1 < e2;
}

int main()
{
	//testAll();
	testAllExtended();
	SortedBag sb(relation);
	sb.add(2);
	sb.add(2);
	sb.add(3);
	sb.add(3);
	sb.add(1);
	sb.add(1);
	int n = sb.elementsWithMinimumFrequency();
	std::cout << n << std::endl;
	return 0;
}