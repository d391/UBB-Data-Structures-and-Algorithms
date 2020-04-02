#include "MultiMapIterator.h"


//resets the iterator
//complexity: Theta(1)
void MultiMapIterator::first()
{
	this->ckey = this->multiMap.head;
	if(this->ckey!=NULL)
		this->sideCkey = this->multiMap.head->sideHead;
}

//gets to the next element of the iterator
//complexity: Theta(1)
void MultiMapIterator::next()
{
	if (this->valid())
		if (this->sideCkey != NULL)
		{
			this->sideCkey = this->sideCkey->next;
			if (this->sideCkey == NULL)
			{
				this->ckey = this->ckey->next;
				if (this->valid())
					this->sideCkey = this->ckey->sideHead;
				//else
					//throw std::exception();
			}
		}
}

//returns true if the iterator is valid, false otherwise
//complexity: Theta(1)
bool MultiMapIterator::valid() const
{
	if (this->ckey != NULL)
		return true;
	return false;
}

//returns the current element of the sll
//complexity: Theta(1)
TElem MultiMapIterator::getCurrent() const
{
	if (this->valid())
	{
		TElem cElem;
		cElem.first = this->ckey->key;
		cElem.second = this->sideCkey->info;
		return cElem;
	}
	else
		throw std::exception();
}
