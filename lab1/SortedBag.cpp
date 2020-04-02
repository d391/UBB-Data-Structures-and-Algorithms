#pragma once
#include "SortedBag.h"
#include <iostream>

// ADT SortedBag - having elements of type TComp, represented using <element, frequency> pairs sorted using 
//a relation on the elements

// constructor off the SortedBag
//Complexity: Theta(1)
SortedBag::SortedBag(Relation r)
{
	this->rel = r;
	this->arrSize = 0;
	this->capacity = 100;
	this->elements = new TElem[this->capacity];
}

//realocates more memory when the capacity is full
//complexity: Theta(n) n-size of the dynamic array
void SortedBag::resize()
{
	TElem *auxArray = new TElem[this->capacity * 2];
	for (int index = 0; index < this->arrSize; index++)
		auxArray[index] = this->elements[index];
	delete[] this->elements;
	this->elements = auxArray;
	this->capacity = this->capacity * 2;
}

//adds a new element to the SortedBag
//Complexity: o(n^2) n-size of the dynamic array
void SortedBag::add(TComp e)
{
	if (this->arrSize == this->capacity)
		this->resize();
	if (this->arrSize == 0)
	{
		this->elements[this->arrSize].elem = e;
		this->elements[this->arrSize].frequency = 1;
		this->arrSize++;
	}
	else
	{
		for (int index = 0; index < this->arrSize; index++)
			if (e == this->elements[index].elem)
			{
				this->elements[index].frequency++;
				return;
			}
		for (int index = 0; index < this->arrSize; index++)
			if (rel(e, this->elements[index].elem) == true)
			{
				for (int index2 = this->arrSize; index2 > index; index2--)
					this->elements[index2] = this->elements[index2 - 1];
				this->elements[index].elem = e;
				this->elements[index].frequency = 1;
				this->arrSize++;
				return;
			}
		this->elements[this->arrSize].elem = e;
		this->elements[this->arrSize].frequency = 1;
		this->arrSize++;
	}
}

//removes an element from the SortedBag
//returns true if the element has been deleted or false if it does not exist
//complexiity: O(n^2) n-size of the dynamic array
bool SortedBag::remove(TComp e)
{
	for (int index = 0; index < this->arrSize; index++)
		if (e == this->elements[index].elem)
			if(this->elements[index].frequency > 1)
			{
				this->elements[index].frequency--;
				return true;
			}
			else
			{
				for (int index2 = index; index2 < this->arrSize - 1; index2++)
					this->elements[index2] = this->elements[index2 + 1];
				this->arrSize--;
				return true;
			}
	return false;
}

//searches for an element in the SortedBag
//returns true if the elements exists, false otherwise
//complexity: O(n) n-size of the dynamic array
bool SortedBag::search(TComp e) const
{
	for (int index = 0; index < this->arrSize; index++)
		if (e == this->elements[index].elem)
			return true;
	return false;
}

//returns the number of occurences of a given element
//complexity: O(n) n-size of the dynamic array
int SortedBag::nrOccurrences(TComp e) const
{
	for (int index = 0; index < this->arrSize; index++)
		if (e == this->elements[index].elem)
			return this->elements[index].frequency;
	return 0;
}


//returns an iterator for the SortedBag
//complexity: Theta(1)
SortedBagIterator SortedBag::iterator() const
{
	return SortedBagIterator(*this);
}

//returns the size of the SortedBag
//complexity: Theta(n) n-size of the dynamic array
int SortedBag::size() const
{
	int s = 0;
	for (int index = 0; index < this->arrSize; index++)
		s += this->elements[index].frequency;
	return s;
}

//verifies if the SortedBag is empty
//returns true if it is and false otherwise
//complexity: Theta(1)
bool SortedBag::isEmpty() const
{
	if (this->arrSize == 0)
		return true;
	return false;
}

int SortedBag::elementsWithMinimumFrequency() const
{
	int number = 1, minFre;
	minFre = this->elements[0].frequency;
	for (int index = 1; index < this->arrSize; index++)
		if (minFre > this->elements[index].frequency)
		{
			minFre = this->elements[index].frequency;
			number = 1;
		}
		else if (minFre == this->elements[index].frequency)
			number++;
	return number;
}

//destructor
//complexity: Theta(1)
SortedBag::~SortedBag()
{
	delete[] this->elements;
}