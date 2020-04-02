#pragma once
#include "Iterator.h"
#include <iostream>


//resets the iterator
//complexity: Theta(1)
void SortedBagIterator::first()
{
	this->mainIndex = 0;
	this->sideIndex = 0;
}

//goes to the next element in the iterator
//complexity: Theta(1)
void SortedBagIterator::next()
{
	if (this->valid() == true)
	{
		if (this->sideIndex < this->sortBag.nrOccurrences(this->getCurrent()))
			this->sideIndex++;
		else
		{
			this->mainIndex++;
			this->sideIndex = 0;
		}
	}
	else
		throw std::exception();
}

//checks if the iterator is still valid
//returns true if it is and false otherwise
//complexity: Theta(1)
bool SortedBagIterator::valid() const
{
	if (this->mainIndex == this->sortBag.getArraySize())
		return false;
	return true;
}

//returns the current elment of the iterator or throws an exception if the iterator is not valid
//complexity: Theta(1)
int SortedBagIterator::getCurrent() const
{
	if (this->valid() == true)
		return this->sortBag.getElements()[this->mainIndex].elem;
	throw std::exception();
}

//destructor
SortedBagIterator::~SortedBagIterator()
{

}

