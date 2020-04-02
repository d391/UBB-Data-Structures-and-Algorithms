#pragma once
#include "SortedBag.h"

class SortedBagIterator 
{
	friend class SortedBag;
private:

	SortedBagIterator(const SortedBag& sb) : sortBag{ sb }, mainIndex{ 0 }, sideIndex{ 0 } {};
	const SortedBag& sortBag;
	int mainIndex, sideIndex;

public:

	void first();
	void next();
	bool valid() const;
	int getCurrent() const;
	~SortedBagIterator();
};


