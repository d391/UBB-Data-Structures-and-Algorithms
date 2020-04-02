#include "Matrix.h"
#include <iostream>

//complexity: Theta(m)
Matrix::Matrix(int nrLines, int nrCols)
{
	if (nrLines <= 0 || nrCols <= 0)
		throw std::exception();
	this->nrCol = nrCols;
	this->nrLin = nrLines;
	this->elems = new MatrixElement[13];
	this->next = new int[13];
	this->m = 13;
	this->firstEmpty = 0;
	for (int i = 0; i < m; i++)
	{
		this->next[i] = -1;
		this->elems[i].line = -1;
		this->elems[i].column = -1;
		this->elems[i].value = -1;
	}
}

//complexity: Theta(1)
int Matrix::nrLines() const
{
	return this->nrLin;
}

//complexity: Theta(1)
int Matrix::nrColumns() const
{
	return this->nrCol;
}

//complexity: O(m)
TElem Matrix::element(int i, int j) const
{
	if (i > this->nrLin || j > this->nrCol || i < 0 || j < 0)
		throw std::exception();
	int index = this->h(i);
	while (index != -1)
	{
		if (this->elems[index].line == i && this->elems[index].column == j)
			return this->elems[index].value;
		index = this->next[index];
	}	
	return 0;
}

//complexity: O(m)
TElem Matrix::modify(int i, int j, TElem e)
{
	if (i > this->nrLin || j > this->nrCol || i < 0 || j < 0)
		throw std::exception();
	if (e != 0)
		return this->insert(i, j, e);
	else
		this->remove(i, j, this->element(i,j));
}

Matrix::~Matrix()
{
	delete[] this->elems;
	delete[] this->next;
}


//complexity: Theta(m*2)
void Matrix::resizeAndRehash()
{
	int oldM = this->m;
	this->m = this->m * 2 + 1;
	this->alpha = this->alpha * 2;
	MatrixElement *newElems = new MatrixElement[this->m];
	int *newNext = new int[this->m];
	this->firstEmpty = 0;
	for (int i = 0; i < this->m; i++)
	{
		newNext[i] = -1;
		newElems[i].line = -1;
		newElems[i].column = -1;
		newElems[i].value = -1;
	}

	int index;
	for (int i = 0; i < oldM; i++)
		if (this->elems[i].line != -1)
		{
			index = this->h(this->elems[i].line);
			if (newElems[index].line == -1)
			{
				newElems[index].line = this->elems[i].line;
				newElems[index].column = this->elems[i].column;
				newElems[index].value = this->elems[i].value;
				newNext[index] = -1;
				if (index == this->firstEmpty)
					this->changeFirstEmpty(newElems);
			}
			else
			{
				while (newNext[index] != -1)
					index = newNext[index];
				newElems[this->firstEmpty].line = this->elems[i].line;
				newElems[this->firstEmpty].column = this->elems[i].column;
				newElems[this->firstEmpty].value = this->elems[i].value;
				newNext[index] = this->firstEmpty;
				newNext[this->firstEmpty] = -1;
				this->changeFirstEmpty(newElems);
			}
		}
	delete[] this->elems;
	delete[] this->next;
	this->elems = newElems;
	this->next = newNext;
}


//complexity: O(m)
void Matrix::changeFirstEmpty(MatrixElement*& auxM)
{
	this->firstEmpty++;
	while (this->firstEmpty < this->m && auxM[this->firstEmpty].line != -1)
		this->firstEmpty++;
}


//complexity: O(m)
TElem Matrix::insert(int i, int j, TElem e)
{
	int index = this->h(i);
	if (this->elems[index].line == -1)
	{
		this->elems[index].line = i;
		this->elems[index].column = j;
		this->elems[index].value = e;
		this->next[index] = -1;
		this->size++;
		if (index == this->firstEmpty)
			this->changeFirstEmpty(this->elems);
		return 0;
	}
	if (this->firstEmpty == this->m || this->alpha < (double)this->size/this->m)
		this->resizeAndRehash();
	while (this->next[index] != -1)
	{
		if (this->elems[index].line == i && this->elems[index].column == j)
		{
			TElem oldValue = this->elems[index].value;
			this->elems[index].value = e;
			return oldValue;
		}
		index = this->next[index];
	}
	this->elems[this->firstEmpty].line = i;
	this->elems[this->firstEmpty].column = j;
	this->elems[this->firstEmpty].value = e;
	this->next[index] = this->firstEmpty;
	this->next[this->firstEmpty] = -1;
	this->changeFirstEmpty(this->elems);
	this->size++;
	return 0;
}


//complexity: O(m)
void Matrix::remove(int i, int j, TElem e)
{
	int index = this->h(i);
	int aux = -1;
	int counter = 0;
	while (counter < this->m && this->next[counter] != index)
		counter++;
	if (counter < this->m)
		aux = counter;
	while (index != -1 && this->elems[index].value != e)
	{
		aux = index;
		index = this->next[index];
	}
	if (index != -1)
	{
		bool over = false;
		int p, pp;
		do
		{
			p = this->next[index];
			pp = index;
			while (p != -1 && this->h(this->elems[p].line) != index)
			{
				pp = p;
				p = this->next[p];
			}
			if (p == -1)
				over = true;
			else
			{
				this->elems[index].line = this->elems[p].line;
				this->elems[index].column = this->elems[p].column;
				this->elems[index].value = this->elems[p].value;
				index = p;
				aux = pp;
			}
		} while (!over);

		if (aux != -1)
		{
			this->elems[index].line = -1;
			this->elems[index].column = -1;
			this->elems[index].value = -1;
			this->next[index] = -1;
		}
		else
		{
			this->next[aux] = this->next[index];
			this->elems[index].line = -1;
			this->elems[index].column = -1;
			this->elems[index].value = -1;
			this->next[index] = -1;
		}
		
		if (index < this->firstEmpty)
			this->firstEmpty = index;

		this->size--;
	}
}
