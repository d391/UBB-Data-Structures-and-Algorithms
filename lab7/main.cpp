#include "SortedBag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

bool relation(TComp r1, TComp r2) {
	return r1 <= r2;
}

int main()
{
	SortedBag sb{relation};
	sb.add(2);
	sb.add(2);
	sb.add(2);
	sb.add(3);
	sb.add(3);
	sb.add(3);
	sb.add(4);
	std::cout << sb.elementsWithThisFrequency(3);
	testAll();
	testAllExtended();
	return 0;
}