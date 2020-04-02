#pragma once
#include <vector>

using namespace std;

typedef int TElem;

//computes the sum of the largest k elements from the vector
//if k is less than or equal to 0, it throws an exception
long computeSum(vector<TElem> vector, int k);