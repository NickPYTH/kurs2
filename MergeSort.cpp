#include "MergeSort.h"
#include "RandomGenerator.h"
#include <chrono>

using namespace std;

double * MergeSort::AlgSort(double data[], int num)
{   
    double *med_data = new double[num];
    auto begin = std::chrono::steady_clock::now();
    med_data = mergeSort(data, num);
    auto end = std::chrono::steady_clock::now();
    auto med_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    sort_time = med_time.count();
    return med_data;
}

double * MergeSort::mergeSort(double data[], int lenD)
{
  if(lenD>1){
    double *med_data = new double[lenD];
    int middle = lenD/2;
    int rem = lenD-middle;
    double* L = new double[middle];
    double* R = new double[rem];
    for(int i=0;i<lenD;i++){
      iteration_count+=1;
      if(i<middle){
        transposition_count+=1;
        L[i] = data[i];
      }
      else{
        transposition_count+=1;
        R[i-middle] = data[i];
      }
    }
    mergeSort(L,middle);
    mergeSort(R,rem);
    med_data = merge(data, lenD, L, middle, R, rem);
    return med_data;
  }
  return data;
}
 
double * MergeSort::merge(double merged[], int lenD, double L[], int lenL, double R[], int lenR){
  int i = 0;
  int j = 0;
  while(i<lenL||j<lenR){
    iteration_count+=1;
    if (i<lenL & j<lenR){
      if(L[i]<=R[j]){
        transposition_count+=1;
        merged[i+j] = L[i];
        i++;
      }
      else{
        transposition_count+=1;
        merged[i+j] = R[j];
        j++;
      }
    }
    else if(i<lenL){
      transposition_count+=1;
      merged[i+j] = L[i];
      i++;
    }
    else if(j<lenR){
      transposition_count+=1;
      merged[i+j] = R[j];
      j++;
    }
  }
  return merged;
}

 