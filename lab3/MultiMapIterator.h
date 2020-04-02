#pragma once
#include "MultiMap.h"
#include "MultiMapIterator.h"
#include "MiniIterator.h"

class MultiMap;
class MainNode;
class MiniIterator;

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class MultiMapIterator
{
	friend class MultiMap;
	friend class MainNode;
	friend class SideNode;
private:
	MultiMapIterator(const MultiMap& mp) : multiMap{ mp } { first(); };
	const MultiMap& multiMap;
	MainNode *ckey;
	SideNode *sideCkey;
	int initialised = 0;

public:
	void first();
	void next();
	bool valid() const;
	TElem getCurrent() const;
};
