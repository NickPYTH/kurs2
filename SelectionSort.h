#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H 
#include "BaseSort.h"

class SelectionSort : public BaseSort
{
public:
    virtual double * AlgSort(double array[], int num);
};
 
#endif