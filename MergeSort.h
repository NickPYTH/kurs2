#ifndef MERGESORT_H
#define MERGESORT_H 
#include "BaseSort.h"

class MergeSort : public BaseSort
{
public:
    virtual double * AlgSort(double array[], int num);
protected:
    double * mergeSort(double data[], int lenD);
    double * merge(double merged[], int lenD, double L[], int lenL, double R[], int lenR);
};
 
#endif