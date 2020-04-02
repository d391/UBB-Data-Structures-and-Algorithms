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
	//for (int index = 0; index < this->capacity; index++)
		//this->elements[index].next = index + 1;
	//this->elements[this->capacity].next = -1;

}

//complexity: Theta(n), n - the length of the array
void Map::resize()
{
	this->firstEmpty = this->capacity;
	DllaNode *auxArray = new DllaNode[this->capacity * 2];
	for (int index = 0; index < this->arrSize; index++)
		auxArray[index] = this->elements[index];
	//for (int index = this->arrSize; index < this->capacity * 2; index++)
		//auxArray[index].next = index + 1;
	//auxArray[this->capacity*2].next = -1;
	//delete[] this->elements;
	this->elements = auxArray;
	this->capacity = this->capacity * 2;
}

//complexity: O(n), n - the length of the array
TValue Map::add(TKey c, TValue v)
{
	if (this->head == -1)
	{
		TElem newElem;
		newElem.first = c;
		newElem.second = v;
		this->head = 0;
		this->tail = 0;
		this->elements[0].info = newElem;
		this->elements[0].next = -1;
		this->elements[0].prev = -1;
		this->firstEmpty = 1;
		this->arrSize = 1;
		this->totalElements = 1;
		return NULL_TVALUE;
	}
	int index = this->head;
	while (index != -1)
	{
		if (this->elements[index].info.first == c)
		{
			TValue oldValue;
			oldValue = this->elements[index].info.second;
			this->elements[index].info.second = v;
			return oldValue;
		}
		index = this->elements[index].next;
	}

	if (this->firstEmpty == this->capacity)
		this->resize();

	TElem newElem;
	newElem.first = c;
	newElem.second = v;
	this->totalElements++;
	this->arrSize++;
	int oldEmpty = this->firstEmpty;
	if (this->elements[this->firstEmpty].next != -1)
		this->firstEmpty = this->elements[this->firstEmpty].next;
	else
		this->firstEmpty = this->arrSize;
	this->elements[oldEmpty].info = newElem;
	this->elements[this->tail].next = oldEmpty;
	this->elements[oldEmpty].prev = this->tail;
	this->elements[oldEmpty].next = -1;
	this->tail = oldEmpty;
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
	if(this->head == -1)
		return NULL_TVALUE;
	int index = this->head;
	if (this->elements[this->head].info.first == c)
	{
		this->totalElements--;
		this->arrSize--;
		TValue oldValue = this->elements[index].info.second;
		int oldHead = this->head;
		this->head = this->elements[this->head].next;
		this->elements[this->head].prev = -1;
		this->elements[oldHead].info.first = NULL;
		this->elements[oldHead].info.second = NULL;
		this->elements[oldHead].prev = -1;
		this->elements[index].next = this->firstEmpty;
		this->firstEmpty = index;
		return oldValue;
	}
	while (index != this->tail)
	{
		if (this->elements[index].info.first == c)
		{
			this->totalElements--;
			this->arrSize--;
			this->elements[this->elements[index].prev].next = this->elements[index].next;
			this->elements[this->elements[index].next].prev = this->elements[index].prev;
			TValue oldValue = this->elements[index].info.second;
			this->elements[index].info.first = NULL;
			this->elements[index].info.second = NULL;
			this->elements[index].prev = -1;
			this->elements[index].next = this->firstEmpty;
			this->firstEmpty = index;
			return oldValue;
		}
		index = this->elements[index].next;
	}
	if (this->elements[this->tail].info.first == c)
	{
		this->totalElements--;
		this->arrSize--;
		TValue oldValue = this->elements[index].info.second;
		int oldTail = this->tail;
		this->tail = this->elements[this->tail].prev;
		this->elements[oldTail].info.first = NULL;
		this->elements[oldTail].info.second = NULL;
		this->elements[oldTail].prev = -1;
		this->elements[index].next = this->firstEmpty;
		this->firstEmpty = index;
		return oldValue;
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
	//delete[] this->elements;
}
