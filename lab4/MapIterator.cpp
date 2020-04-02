#include "MapIterator.h"

//sets the iterator to the first element of the Map
void MapIterator::first()
{
	this->currentIndex = this->m.getHead();
}

//checks if the iterator is valid
bool MapIterator::valid() const
{
	return this->currentIndex != this->m.elements[this->m.tail].next && this->m.size() != 0;
}

//moves the iterator to the next element
//throws exception if the iterator is not valid

void MapIterator::next()
{
	if (this->valid())
		this->currentIndex = this->m.getNextIndex(this->currentIndex);
	else
		throw std::exception();
}

//returns the value of the current element from the iterator
// throws exception if the iterator is not valid
TElem MapIterator::getCurrent() const
{
	if (this->valid())
		return this->m.getElement(this->currentIndex);
	throw std::exception();
}

MapIterator::~MapIterator()
{

}
