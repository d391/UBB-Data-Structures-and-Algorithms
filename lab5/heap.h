#pragma once

typedef int TElem;

class Heap
{
private:
	int capacity;
	int len;
	TElem *elems;
public:
	Heap();
	TElem* getHeap() { return this->elems; };
	int getSize() { return this->len; };
	void add(TElem e);
	void bubble_up(int p);
	TElem remove();
	void bubble_down(int p);
	~Heap();
private:
	void resize();
};

