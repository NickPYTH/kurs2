#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H 
#include "BaseSort.h"

class InsertionSort : public BaseSort
{
public:
    virtual double * AlgSort(double array[], int num);
};
 
#endif