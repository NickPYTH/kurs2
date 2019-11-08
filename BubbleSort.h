#ifndef BUBBLESORT_H
#define BUBBLESORT_H 
#include "BaseSort.h"
#include "BaseSort.cpp"
class BubbleSort : public BaseSort
{
public:
    BubbleSort();
    virtual double * AlgSort(double array[], int num);
};
 
#endif