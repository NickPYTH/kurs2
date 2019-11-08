#ifndef MERGESORT_H
#define MERGESORT_H 

class MergeSort
{
private:
    int size;
    int iteration_count;
    int transposition_count;
    double array[];

    void SetArray(double array[]);
    void SetSize(int size);
    void AlgSort(double array[], int size);
    void Merge(double merged[], int lenD, double L[], int lenL, double R[], int lenR);
 
public:
    MergeSort(double array[], int size);
    double * getSortArray();
    int getIterationCount();
    int getTranspositionCount();

};
 
#endif