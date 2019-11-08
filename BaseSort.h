#ifndef BASESORT_H
#define BASESORT_H

class BaseSort
{   
protected:
    int iteration_count;
    int transposition_count;
    int sort_time; 
    
    //double * getSortArray();
public:
    int getIterationCount();
    int getTranspositionCount();
    int getSortTime();
    virtual double* AlgSort(double array[], int num);
};

#endif