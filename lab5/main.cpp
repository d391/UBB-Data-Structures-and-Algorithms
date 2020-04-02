#include "test.h"
#include "heap.h"
#include <iostream>

int main()
{
	testP10();
	Heap h;
	h.add(23);
	h.add(10);
	h.add(1);
	h.add(56);
	h.add(100);
	h.add(17);
	h.remove();
	h.add(64);
	h.remove();
	h.add(2);
	h.remove();
	h.add(11);
	h.remove();
	for (int i = 1; i <= h.getSize(); i++)
		std::cout << h.getHeap()[i] << std::endl;
	return 0;
}