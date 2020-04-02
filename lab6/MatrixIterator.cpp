#include "MatrixIterator.h"



void MatrixIterator::first()
{
	this->currentCol = 0;
}

void MatrixIterator::next()
{
	if (this->valid())
		this->currentCol++;
	else
		throw std::exception();
}

TElem MatrixIterator::getCurrent()
{
	return this->mat.element(this->line, this->currentCol + 1);
}

bool MatrixIterator::valid()
{
	return this->currentCol < this->mat.nrColumns();
}

MatrixIterator::~MatrixIterator()
{
}
