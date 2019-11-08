#ifndef QUICKSORT_H
#define QUICKSORT_H 
#include "BaseSort.h"

class QuickSort : public BaseSort
{
public:
    virtual double * AlgSort(double array[], int num);
};
 
#endif