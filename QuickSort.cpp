#include "QuickSort.h"
#include "RandomGenerator.h"
#include <ctime>

double * QuickSort::AlgSort(double data[], int num){
    double *med_data = new double[num];
    auto begin = std::chrono::steady_clock::now();
    med_data = RekursSort(data, num);
    auto end = std::chrono::steady_clock::now();
    auto med_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    sort_time = med_time.count();
    return med_data;
}

double * QuickSort::RekursSort(double data[], int num)
{ 
  int const lenD = num;
  double pivot = 0;
  int ind = lenD/2;
  int i,j = 0,k = 0;
  if(lenD>1){
    double* L = new double[lenD];
    double* R = new double[lenD];
    pivot = data[ind];
    for(i=0;i<lenD;i++){
      if(i!=ind){
        if(data[i]<pivot){
          L[j] = data[i];
          j++;
        }
        else{
          R[k] = data[i];
          k++;
        }
      }
    }
    RekursSort(L,j);
    RekursSort(R,k);
    for(int cnt=0;cnt<lenD;cnt++){
      if(cnt<j){
        data[cnt] = L[cnt];;
      }
      else if(cnt==j){
        data[cnt] = pivot;
      }
      else{
        data[cnt] = R[cnt-(j+1)];
      }
    }
  }
  return data;
}
 