#include "MergeSort.h"

using namespace std;

MergeSort::MergeSort(double m_array[], int m_size)
{
    SetSize(m_size);
    SetArray(m_array);
}

void MergeSort::SetSize(int m_size)
{
    size = m_size;
}

void MergeSort::SetArray(double m_array[])
{
    array[size];
    for (int i = 0; i < size; i++) {
        array[i] = m_array[i];    
    }
}

void MergeSort::AlgSort(double data[], int num)
{   
    
}

void MergeSort::Merge(double merged[], int lenD, double L[], int lenL, double R[], int lenR){
  int i = 0;
  int j = 0;
  while(i<lenL||j<lenR){
    if (i<lenL & j<lenR){
      if(L[i]<=R[j]){
        merged[i+j] = L[i];
        i++;
      }
      else{
        merged[i+j] = R[j];
        j++;
      }
    }
    else if(i<lenL){
      merged[i+j] = L[i];
      i++;
    }
    else if(j<lenR){
      merged[i+j] = R[j];
      j++;
    }
  }
}

double * MergeSort::getSortArray() {
    AlgSort(array ,size);
    return array; 
}

int MergeSort::getIterationCount(){return iteration_count;}
int MergeSort::getTranspositionCount(){return transposition_count;}
 