#include "SortedBag.h"
#include <iostream>
#include <vector>
#include <stack>

//complexity: theta(100)
SortedBag::SortedBag(Relation r) 
{
	this->rel = r;
	this->root = -1;
	this->firstEmpty = 1;
	this->numberOfElements = 0;
	this->capacity = 100;
	this->elements = new BSTNode[100];
	this->arraySize = 0;
	/*this->next = new int[100];
	for (int i = 0; i < 100; i++)
		this->next[i] = i + 1;
	this->next[100] = -1;*/
}


int SortedBag::addRec(int currentIndex, TComp e)
{
	if (currentIndex == -1)
	{
		this->elements[this->firstEmpty].info.element = e;
		this->elements[this->firstEmpty].info.frequency = 1;
		this->elements[this->firstEmpty].left = -1;
		this->elements[this->firstEmpty].right = -1;
		int oldEmpty = this->firstEmpty;
		this->nextFirstEmpty();
		//this->firstEmpty = this->next[this->firstEmpty];
		return oldEmpty;
	}
	else if (this->rel(this->elements[currentIndex].info.element, e))
		this->elements[currentIndex].right = this->addRec(this->elements[currentIndex].right, e);
	else	
		this->elements[currentIndex].left = this->addRec(this->elements[currentIndex].left, e);
	return currentIndex;
}


//complexity: O(n)
void SortedBag::add(TComp e)
{
	if (this->firstEmpty == this->capacity)
		this->resize();
	this->numberOfElements++;
	int currentIndex = this->root;
	if (currentIndex == -1)
	{
		this->root = 0;
		this->elements[this->root].info.element = e;
		this->elements[this->root].info.frequency = 1;
		this->elements[this->root].left = -1;
		this->elements[this->root].right = -1;

	}
	else
	{
		while (currentIndex != -1)
		{
			if (this->elements[currentIndex].info.element == e)
			{
				this->elements[currentIndex].info.frequency++;
				return;
			}
			if (this->rel(this->elements[currentIndex].info.element, e))
				currentIndex = this->elements[currentIndex].right;
			else
				currentIndex = this->elements[currentIndex].left;
		}
		this->addRec(this->root, e);
	}
	if(this->firstEmpty == this->arraySize+1)
		this->arraySize++;
}



int SortedBag::removeRec(int currentIndex, TComp e)
{
	if (currentIndex == -1)
		return currentIndex;

	if (e == this->elements[currentIndex].info.element)
	{
		if (this->elements[currentIndex].left== - 1)
		{
			int rightIndex = this->elements[currentIndex].right;
			this->elements[currentIndex].info.element = 0;
			this->elements[currentIndex].info.frequency = 0;
			this->elements[currentIndex].left = -1;
			this->elements[currentIndex].right = -1;
			return rightIndex;
		}
		else if (this->elements[currentIndex].right == -1)
		{
			int leftIndex = this->elements[currentIndex].left;
			this->elements[currentIndex].info.element = 0;
			this->elements[currentIndex].info.frequency = 0;
			this->elements[currentIndex].left = -1;
			this->elements[currentIndex].right = -1;
			return leftIndex;
		}

		int minIndex = this->minimum(this->elements[currentIndex].right);
		this->elements[currentIndex].info.element = this->elements[minIndex].info.element;
		this->elements[currentIndex].right = this->removeRec(this->elements[currentIndex].right, this->elements[currentIndex].info.element);
	}
	else if (this->rel(e, this->elements[currentIndex].info.element))
		this->elements[currentIndex].left = this->removeRec(this->elements[currentIndex].left, e);
	else
		this->elements[currentIndex].right = this->removeRec(this->elements[currentIndex].right, e);
	return currentIndex;
}

int SortedBag::elementsWithThisFrequency(int frequency) const
{
	if (frequency <= 0)
		throw std::exception();
	int count = 0, currentCount = 0, currentEl;
	SortedBagIterator it{ *this };
	if (it.valid())
	{
		currentEl = it.getCurrent();
		currentCount++;
		it.next();
	}
	while (it.valid())
	{
		if (it.getCurrent() == currentEl)
			currentCount++;
		else
		{
			if (currentCount == frequency)
				count++;
			currentCount = 1;
			currentEl = it.getCurrent();
		}
		it.next();
	}
	return count;

}


//complexity: O(n)
bool SortedBag::remove(TComp e)
{
	int currentIndex = this->root;
	while (currentIndex != -1)
	{
		if (this->elements[currentIndex].info.element == e)
		{
			if (this->elements[currentIndex].info.frequency > 1)
				this->elements[currentIndex].info.frequency--;
			else
				this->root = this->removeRec(this->root, e);
			this->numberOfElements--;
			//this->next[currentIndex] = this->firstEmpty;
			this->firstEmpty = currentIndex;
			return true;
		}
		if (this->rel(this->elements[currentIndex].info.element, e))
			currentIndex = this->elements[currentIndex].right;
		else
			currentIndex = this->elements[currentIndex].left;
	}
	return false;
}


//complexity: O(n)
bool SortedBag::search(TComp e) const
{
	int currentIndex = this->root;
	while (currentIndex != -1)
	{
		if (this->elements[currentIndex].info.element == e)
			return true;
		if (this->rel(this->elements[currentIndex].info.element, e))
			currentIndex = this->elements[currentIndex].right;
		else
			currentIndex = this->elements[currentIndex].left;
	}
	return false;
}


//complexity: O(n)
int SortedBag::nrOccurrences(TComp e) const
{
	int currentIndex = this->root;
	while (currentIndex != -1)
	{
		if (this->elements[currentIndex].info.element == e)
			return this->elements[currentIndex].info.frequency;
		if (this->rel(this->elements[currentIndex].info.element, e))
			currentIndex = this->elements[currentIndex].right;
		else
			currentIndex = this->elements[currentIndex].left;
	}
	return 0;
}


//complexity: Theta(1)
int SortedBag::size() const
{
	return this->numberOfElements;
}

//complexity: Theta(1)
SortedBagIterator SortedBag::iterator() const
{
	return SortedBagIterator(*this);
}

//complexity: Theta(1)
bool SortedBag::isEmpty() const
{
	return this->numberOfElements == 0;
}

//complexity: O(n)
void SortedBag::nextFirstEmpty()
{
	this->firstEmpty++;
	while (this->firstEmpty < this->arraySize && this->elements[this->firstEmpty].info.frequency != 0)
		this->firstEmpty++;
}

//complexity: O(n)
int SortedBag::minimum(int startIndex)
{
	int currentIndex = startIndex;
	if (startIndex == -1)
		return -1;
	while (this->elements[currentIndex].left != -1)
		currentIndex = this->elements[currentIndex].left;

	return currentIndex;
}


SortedBag::~SortedBag()
{
	//delete[]this->next;
	delete[]this->elements;
}

//complexity: Theta(n*2)
void SortedBag::resize()
{
	//this->firstEmpty = this->capacity;
	BSTNode *newElements = new BSTNode[this->capacity*2];
	int *newNext = new int[this->capacity * 2];
	for (int i = 0; i < this->arraySize; i++)
	{
		newElements[i] = this->elements[i];
		//newNext[i] = this->next[i];
	}
	this->firstEmpty = this->capacity; 
	delete[]this->elements;
	//delete[]this->next;
	this->capacity = this->capacity * 2;
	this->elements = newElements;
	//this->next = newNext;
}
