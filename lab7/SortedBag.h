#pragma once
#include "SortedBagIterator.h"

typedef int TComp;
typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);

struct Elem
{
	TElem element = 0;
	int frequency = 0;
};

struct BSTNode
{
	Elem info;
	int left = -1;
	int right = -1;
};
class SortedBagIterator;

class SortedBag 
{
	friend class SortedBagIterator;
private:
	int root;
	int firstEmpty;
	int capacity;
	int numberOfElements;
	BSTNode *elements;
	Relation rel;
	int minElem;
	int arraySize;
	//int *next;

public:

	//constructor
	SortedBag(Relation r);

	BSTNode* getElements() { return this->elements; };
	int getSize() { return this->arraySize; };

	//adds an element to the sorted bag
	int addRec(int currentIndex, TComp e);
	void add(TComp e);

	//removes one occurrence of an element from a sorted bag
	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appearch is the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	//checks if the sorted bag is empty
	bool isEmpty() const;

	void nextFirstEmpty();

	int minimum(int startIndex);

	int removeRec(int currentIndex, TComp e);

	int elementsWithThisFrequency(int frequency) const;

	//destructor
	~SortedBag();
private:
	void resize();
};