#include "Map.h"

//complexity: Theta(1)
Map::Map()
{
	this->capacity = 100;
	this->arrSize = 0;
	this->elements = new DllaNode[this->capacity];
	this->head = -1;
	this->tail = -1;
	this->firstEmpty = 0;
	this->totalElements = 0;
	for (int index = 0; index < this->capacity; index++)
		this->elements[index].next = index + 1;
	this->elements[this->capacity-1].next = -1;

}

//complexity: Theta(n), n - the capacity of the array
void Map::resize()
{
	this->firstEmpty = this->capacity;
	DllaNode *auxArray = new DllaNode[this->capacity * 2];
	for (int index = 0; index < this->capacity; index++)
		auxArray[index] = this->elements[index];
	for (int index = this->capacity; index < this->capacity * 2; index++)
		auxArray[index].next = index + 1;
	auxArray[this->capacity*2-1].next = -1;
	
	delete[] this->elements;
	this->elements = auxArray;
	this->capacity = this->capacity * 2;
}

//complexity: O(n), n - the length of the array
TValue Map::add(TKey c, TValue v)
{
	if (this->firstEmpty == -1)
		this->resize();
	int index = this->head;
	while (index != -1)
	{
		if (this->elements[index].info.first == c)
		{
			int oldValue = this->elements[index].info.second;
			this->elements[index].info.second = v;
			return oldValue;
		}
		index = this->elements[index].next;
	}
	TElem newInfo;
	newInfo.first = c;
	newInfo.second = v;
	int oldEmpty = this->firstEmpty;
	this->firstEmpty = this->elements[this->firstEmpty].next;
	this->elements[oldEmpty].next = -1;

	this->elements[oldEmpty].prev = this->tail;

	this->elements[oldEmpty].info = newInfo;

	if (this->tail != -1) {

		this->elements[this->tail].next = oldEmpty;

	}
	else
	{
		this->head = oldEmpty;
		this->elements[this->head].prev = -1;
		this->elements[this->head].next = -1;
	}
	this->tail = oldEmpty;
	this->totalElements++;
	return NULL_TVALUE;
}

//complexity: O(n), n - the length of the array
TValue Map::search(TKey c) const
{
	int index = this->head;
	while (index != -1)
	{
		if (this->elements[index].info.first == c)
			return this->elements[index].info.second;
		index = this->elements[index].next;
	}
	return NULL_TVALUE;
}

//complexity: O(n), n - the length of the array
TValue Map::remove(TKey c)
{
	if (this->head == -1)
		return NULL_TVALUE;
	if (this->head == this->tail)
		if (this->elements[this->head].info.first == c)
		{
			int oldValue = this->elements[this->head].info.second;
			int oldHead = this->head;
			this->head = -1;
			this->tail = -1;
			this->elements[oldHead].next = this->firstEmpty;
			this->firstEmpty = oldHead;
			this->totalElements--;
			return oldValue;
		}
		else
			return NULL_TVALUE;
	if (this->elements[this->head].info.first == c)
	{
		int oldValue = this->elements[this->head].info.second;
		int oldHead = this->head;
		this->head = this->elements[this->head].next;
		this->elements[this->head].prev = -1;
		this->elements[oldHead].next = this->firstEmpty;
		this->firstEmpty = oldHead;
		this->totalElements--;
		return oldValue;
	}
	if (this->elements[this->tail].info.first == c)
	{
		int oldValue = this->elements[this->tail].info.second;
		int oldTail = this->tail;
		this->tail = this->elements[this->tail].prev;
		this->elements[this->tail].next = -1;
		this->elements[oldTail].next = this->firstEmpty;
		this->firstEmpty = oldTail;
		this->totalElements--;
		return oldValue;
	}
	
	int index = this->elements[this->head].next;
	while (index != this->tail)
	{
		if (this->elements[index].info.first == c)
		{
			int prev = this->elements[index].prev;
			int next = this->elements[index].next;
			int oldValue = this->elements[index].info.second;
			this->elements[prev].next = next;
			this->elements[next].prev = prev;
			this->elements[index].next = this->firstEmpty;
			this->firstEmpty = index;
			this->totalElements--;
			return oldValue;
		}
		else
			index = this->elements[index].next;
		
	}
	return NULL_TVALUE;
}

//complexity: Theta(1)
int Map::size() const
{
	return this->totalElements;
}

//complexity: Theta(1)
bool Map::isEmpty() const
{
	return this->totalElements == 0;
}

//complexity: Theta(1)
MapIterator Map::iterator() const
{
	return MapIterator(*this);
}

int Map::getValueRange()const
{
	if (this->head == -1)
		return -1;
	int index = this->head, minValue, maxValue;
	minValue = this->elements[this->head].info.second;
	maxValue = this->elements[this->head].info.second;
	index = this->elements[index].next;
	while (index != -1)
	{
		if (this->elements[index].info.second < minValue)
			minValue = this->elements[index].info.second;
		else if (this->elements[index].info.second > maxValue)
			maxValue = this->elements[index].info.second;
		index = this->elements[index].next;
	}
	return maxValue - minValue;
}

//complexity: Theta(1)
Map::~Map()
{
	delete[] this->elements;
}
