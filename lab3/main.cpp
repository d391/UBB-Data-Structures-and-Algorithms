#pragma once
#include "MultiMap.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

int main()
{
	MultiMap m;
	//m.add(11, 8);
	//m.add(13, 2);
	//m.add(1, 5);
	//m.add(10, 4);
	std::cout << m.minKey();
	testAllExtended();
	return 0;
}