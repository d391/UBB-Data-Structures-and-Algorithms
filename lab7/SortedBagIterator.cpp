#include "SortedBagIterator.h"
#include <exception>
#include<iostream>


//complexity: O(n)
void SortedBagIterator::init()
{
	int index = this->sb.root;
	while (index != -1)
	{
		this->stack.push(index);
		index = this->sb.elements[index].left;
	}
	if (this->stack.empty() == false)
	{
		this->currentIndex = this->stack.top();
		this->currentFreq = this->sb.elements[this->currentIndex].info.frequency;
	}
	else
		this->currentIndex = -1;
}

//complexity: O(n)
void SortedBagIterator::first()
{
	this->init();
}

//complexity: O(n)
void SortedBagIterator::next()
{
	if (this->valid() == false)
		throw std::exception();
	if (this->currentFreq > 1)
		this->currentFreq--;
	else
	{
		int index = this->stack.top();
		this->stack.pop();
		if (this->sb.elements[index].right != -1)
		{
			index = this->sb.elements[index].right;
			while (index != -1)
			{
				this->stack.push(index);
				index = this->sb.elements[index].left;
			}
		}
		if (this->stack.empty() == false)
		{
			this->currentIndex = this->stack.top();
			this->currentFreq = this->sb.elements[this->currentIndex].info.frequency;
		}
		else
			this->currentIndex = -1;
	}
}

//complexity: theta(1)
bool SortedBagIterator::valid() const
{
	return this->currentIndex != -1;
}

//complexity: theta(1)
TElem SortedBagIterator::getCurrent() const
{
	if(this->valid())
		return this->sb.elements[this->currentIndex].info.element;
	throw std::exception();
}



