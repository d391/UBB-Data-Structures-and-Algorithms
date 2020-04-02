#pragma once
#include "Map.h"

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class Map;

//unidirectional iterator for a Map

class MapIterator
{
	friend class Map;
private:

	//Constructor receives a reference of the Map.
	//after creation the iterator will refer to the first element of the Map, or it will be invalid if the Map is empty
	//contains a reference of the Map it iterates over
	const Map& m;
	
	int currentIndex;

public:
	MapIterator(const Map& m) : m{ m } { first(); };
	//sets the iterator to the first element of the Map
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid

	void next();

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	TElem getCurrent() const;

	~MapIterator();
};


