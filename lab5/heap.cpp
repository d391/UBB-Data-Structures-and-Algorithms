#include "heap.h"
#include <iostream>

Heap::Heap()
{
	this->len = 0;
	this->capacity = 100;
	this->elems = new TElem[this->capacity];
	this->elems[0] = 0;
}

void Heap::resize()
{
	TElem *auxArray = new TElem[this->capacity * 2];
	for (int index = 1; index <= this->len; index++)
		auxArray[index] = this->elems[index];
	//delete[] this->elems;
	this->elems = auxArray;
	this->capacity = this->capacity * 2;
}


void Heap::bubble_up(int p)
{
	int poz = p;
	TElem elem = this->elems[p];
	int parentPoz = p / 2;
	while (poz > 1 && elem < this->elems[parentPoz])//(poz > 1 && elem > this->elems[parentPoz])
	{
		this->elems[poz] = this->elems[parentPoz];
		poz = parentPoz;
		parentPoz = poz / 2;
	}
	this->elems[poz] = elem;
}

void Heap::add(TElem e)
{
	if (this->len == this->capacity)
		this->resize();
	this->elems[this->len + 1] = e;
	this->len++;
	bubble_up(this->len);
}

void Heap::bubble_down(int p)
{
	int poz = p;
	TElem elem = this->elems[p], aux;
	int maxChild = -1;
	while (poz < this->len)
	{
		maxChild = -1;
		if (poz * 2 <= this->len)
			maxChild = poz * 2;
		if (poz * 2 + 1 <= this->len && this->elems[2 * poz + 1] < this->elems[2 * poz])//this->elems[2 * poz + 1] > this->elems[2 * poz])
			maxChild = poz * 2 + 1;;
		if (maxChild != -1 && this->elems[maxChild] < elem)//this->elems[maxChild] > elem)
		{
			aux = this->elems[poz];
			this->elems[poz] = this->elems[maxChild];
			this->elems[maxChild] = aux;
			poz = maxChild;
		}
		else
			poz = this->len + 1;
	}
}

TElem Heap::remove()
{
	TElem delNumber = this->elems[1];
	this->elems[1] = this->elems[this->len];
	this->len--;
	bubble_down(1);
	return delNumber;
}

Heap::~Heap()
{
	//delete[] this->elems; 
}
