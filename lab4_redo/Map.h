#pragma once
#define NULL_TVALUE -1
#include <iostream>
#include "MapIterator.h"

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class DllaNode
{
public:
	DllaNode() {};
	TElem info;
	int next;
	int prev;
};


class Map
{
	friend class DllaNode;
	friend class MapIterator;

private:

	// representation of Map
	DllaNode *elements;
	int capacity;
	int head;
	int tail;
	int firstEmpty;
	int arrSize;
	int totalElements;

public:

	// implicit constructor
	Map();
	TElem getElement(int index) const { return this->elements[index].info; };
	int getNextIndex(int index) const { return this->elements[index].next; };

	// adds a pair (key,value) to the map
	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	//if the key does not exist, a new pair is added and the value null is returned
	TValue add(TKey c, TValue v);

	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TELEM otherwise
	TValue search(TKey c) const;

	//removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TELEM otherwise
	TValue remove(TKey c);

	//returns the number of pairs (key,value) from the map
	int size() const;

	//checks whether the map is empty or not
	bool isEmpty() const;

	//returns an iterator for the map
	MapIterator iterator() const;

	int getValueRange()const;

	// destructor
	~Map();

private:
	void resize();
};






