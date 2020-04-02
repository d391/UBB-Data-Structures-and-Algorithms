#pragma once
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "Map.h"
#include <iostream>

int main()
{
	/*Map m;
	m.add(1, 2);
	m.add(2, 3);
	m.add(3, 4);
	m.add(4, 5);
	m.add(5, 6);
	m.add(6, 7);
	for (int i = 0; i < m.size(); i++)
		std::cout << m.getElement(i).first << " ";
	std::cout << std::endl;
	m.remove(2);
	m.remove(5);
	m.add(9999, 9999);
	m.add(99, 9999);
	for (int i = 0; i < m.size(); i++)
		std::cout << m.getElement(i).first << " ";
	std::cout << std::endl;*/
	//std::cout << m.getValueRange();
	testAll();
	testAllExtended();
	return 0;
}