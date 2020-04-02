#pragma once
#include "MultiMap.h"

class SideNode;
class MultiMapIterator;
class MultiMap;

class MiniIterator
{
	friend class MultiMapIterator;
	friend class MultiMapIterator;
private:
	SideNode *miniHead;
	SideNode *miniHeadAux;
	int cValue;
public:
	MiniIterator(SideNode *mh);
	void first();
	void next();
	bool valid() const;
	int getCurrent() const;
	~MiniIterator();
};

