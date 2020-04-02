#pragma once

#include<vector>
#include<utility>
#include "MultiMapIterator.h"
#define NULL_TKEY 0

/*15. ADT MultiMap – using a SLL with unique keys. Every key will be associated with a SLL of the
values belonging to that key.*/

using namespace std;

class MultiMapIterator;

typedef int TKey;
typedef int TValue;

class SideNode
{
public:
	SideNode();
	int info;
	SideNode *next;
	~SideNode();
};

typedef SideNode* TNode;

typedef std::pair<TKey, TValue> TElem;

class MainNode
{
	
public:
	MainNode();
	MainNode *next;
	int key;
	SideNode *sideHead;
	~MainNode();
};

class MultiMap
{
	friend class MultiMapIterator;
	friend class MainNode;
	friend class SideNode;
private:
	MainNode *head;
	int mmSize;

public:
	MultiMap();
	MainNode* getHead() const { return this->head; };
	void add(TKey c, TValue v);
	bool remove(TKey c, TValue v);
	vector<TValue> search(TKey c) const;
	int size() const;
	bool isEmpty() const;
	MultiMapIterator iterator() const;
	TKey minKey() const;
	~MultiMap();
};


