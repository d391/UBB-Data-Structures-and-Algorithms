#include "sum.h"
#include "heap.h"
#include <exception>
#include <iostream>

long computeSum(vector<TElem> vector, int k)
{
	int sum = 0;
	if (k <= 0)
		throw std::exception();
	Heap h;
	for (int i = 0; i < vector.size(); i++)
	{
		h.add(vector[i]);
		sum += vector[i];
		if (i >= k)
			sum -= h.remove();

	}
	/*for (int i = 0; i < vector.size(); i++)
	{
		h.add(vector[i]);
	}
	TElem e = h.remove();
	for (int i = 1; i <= k && i <= vector.size(); i++)
	{
		sum += e;
		e = h.remove();  
	}
	std::cout << endl;*/
	return sum;
}
