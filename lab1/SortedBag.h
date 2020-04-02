#pragma once
#include "Iterator.h"

typedef int TComp;

class TElem
{
public:
	TComp elem;
	int frequency;
};

typedef bool(*Relation)(TComp, TComp);

class SortedBag
{
	friend class SortedBagIterator;
private:
	Relation rel;
	TElem *elements;
	int arrSize;
	int capacity;
public:
	SortedBag(Relation r);
	int getArraySize() const { return this->arrSize; };
	TElem* getElements() const { return this->elements; };
	void add(TComp e);
	bool remove(TComp e);
	bool search(TComp e) const;
	int nrOccurrences(TComp e) const;
	int size() const;
	SortedBagIterator iterator() const;
	bool isEmpty() const;
	int elementsWithMinimumFrequency() const;
	~SortedBag();
private:
	void resize();
};