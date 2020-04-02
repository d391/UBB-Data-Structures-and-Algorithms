#pragma once
#include <exception>

typedef int TElem;

#define NULL_TELEM 0

/*2. ADT Matrix – represented as a sparse matrix where <line, column, value> triples (value ≠ 0) 
are memorized, ordered lexicographically considering the line and column of every element.
The elements are stored in a hashtable with coalesced chaining.
*/

struct MatrixElement
{
	int line;
	int column;
	TElem value;
};

class Matrix 
{
private:

	/*representation of the matrix*/
	int nrLin, nrCol;
	int firstEmpty;
	int *next;
	int m;
	MatrixElement *elems;
	double alpha = 1.6;
	int size;

	void resizeAndRehash();
	void changeFirstEmpty(MatrixElement*& auxM);
	TElem insert(int i, int j, TElem e);
	void remove(int i, int j, TElem e);

public:
	//constructor
	//throws exception if nrLines or nrCols is negative or zero
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	int h(int k) const { return k % this->m; };

	~Matrix();

};
