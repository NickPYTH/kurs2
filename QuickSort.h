#ifndef QUICKSORT_H
#define QUICKSORT_H 

class QuickSort
{
private:
    int size;
    int iteration_count;
    int transposition_count;
    double array[];

    void SetArray(double array[]);
    void SetSize(int size);
    void AlgSort(double array[], int size);
 
public:
    QuickSort(double array[], int size);
    double * getSortArray();
    int getIterationCount();
    int getTranspositionCount();

};
 
#endif