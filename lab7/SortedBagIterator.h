#pragma once
#include "SortedBag.h"
#include <stack>

typedef int TComp;
typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);

class SortedBag;
class SortedBagIterator
{
	friend class SortedBag;
private:

	const SortedBag& sb;
	int currentIndex;
	std::stack<int> stack{};
	int currentFreq;

	//Constructor receives a reference of the container.
	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty
	SortedBagIterator(const SortedBag& _sb) : sb{ _sb }
	{ 
		this->init();
	};


public:

	void init();

	//sets the iterator to the first element of the container
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid
	void next();

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	TElem getCurrent() const;
	
};

