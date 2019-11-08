#include "SelectionSort.h"
#include "RandomGenerator.h"
#include <ctime>

using namespace std;

double * SelectionSort::AlgSort(double array[], int num)
{ 
    double *data = new double[num];
    for (int i=0; i<num; i++)
        data[i] = array[i];
    int start_time =  clock(); // начальное время
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
    
    int end_time = clock(); // конечное вре
    sort_time = end_time - start_time; // искомое время
    return data;
}
 