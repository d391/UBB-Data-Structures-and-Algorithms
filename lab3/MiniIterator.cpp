#include "MiniIterator.h"

MiniIterator::MiniIterator(SideNode *mh)
{
	this->miniHead = mh;
	this->miniHeadAux = mh;
}

void MiniIterator::first()
{
	this->miniHead = this->miniHeadAux;
}

void MiniIterator::next()
{
	this->miniHead = this->miniHead->next;
	if (this->valid())
		this->cValue = this->miniHead->info;
	//else
		//trow std::exception();
}

bool MiniIterator::valid() const
{
	if (this->miniHead == NULL)
		return false;
	return true;
}

int MiniIterator::getCurrent() const
{
	if (this->valid())
		return this->cValue;
	//else
		//throw std::exception();
}

MiniIterator::~MiniIterator()
{

}
