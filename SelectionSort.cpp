#include "SelectionSort.h"
#include "RandomGenerator.h"
#include <chrono>

using namespace std;

double * SelectionSort::AlgSort(double array[], int num)
{ 
    double *data = new double[num];
    for (int i=0; i<num; i++)
        data[i] = array[i];
    auto begin = std::chrono::steady_clock::now();
    iteration_count = 0;
    transposition_count = 0;
    int lenD = num;
    int j = 0;
    double tmp = 0;
    for(int i=0; i<lenD; i++){
      j = i;
      for(int k = i; k<lenD; k++){
        iteration_count+=1;
        if(data[j]>data[k]){
          j = k;
          transposition_count+=1;
        }
      }
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
    }
    
    auto end = std::chrono::steady_clock::now();
    auto med_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    sort_time = med_time.count();
    return data;
}
 