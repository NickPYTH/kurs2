#include "BaseSort.h"
//array = (double *)malloc(size * sizeof(double));

int BaseSort::getSortTime(){
    return sort_time;
}

double * BaseSort::AlgSort(double array[], int num){return NULL;};

int BaseSort::getIterationCount(){return iteration_count;}
int BaseSort::getTranspositionCount(){return transposition_count;}