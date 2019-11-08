#include "QuickSort.h"

using namespace std;

QuickSort::QuickSort(double m_array[], int m_size)
{
    SetSize(m_size);
    SetArray(m_array);
}

void QuickSort::SetSize(int m_size)
{
    size = m_size;
}

void QuickSort::SetArray(double m_array[])
{
    array[size];
    for (int i = 0; i < size; i++) {
        array[i] = m_array[i];    
    }
}

void QuickSort::AlgSort(double data[], int num)
{   
    iteration_count = 0;
    transposition_count = 0;
    int const lenD = num;
    int pivot = 0;
    int ind = lenD/2;
    int i,j = 0,k = 0;
    if(lenD>1){
        double* L = new double[lenD];
        double* R = new double[lenD];
        pivot = data[ind];
        for(i=0;i<lenD;i++){
            iteration_count+=1;
        if(i!=ind){
            if(data[i]<pivot){
                transposition_count+=1;
                L[j] = data[i];
                j++;
            }
            else{
                transposition_count+=1;
                R[k] = data[i];
                k++;
            }
        }
        }
        QuickSort::AlgSort(L,j);
        QuickSort::AlgSort(R,k);
        for(int cnt=0;cnt<lenD;cnt++){
            iteration_count+=1;
            if(cnt<j){
                transposition_count+=1;
                data[cnt] = L[cnt];
            }
            else if(cnt==j){
                transposition_count+=1;
                data[cnt] = pivot;
            }
            else{
                transposition_count+=1;
                data[cnt] = R[cnt-(j+1)];
            }
        }
    }
}


double * QuickSort::getSortArray() {
    AlgSort(array ,size);
    return array; 
}

int QuickSort::getIterationCount(){return iteration_count;}
int QuickSort::getTranspositionCount(){return transposition_count;}
 