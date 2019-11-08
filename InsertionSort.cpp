#include "InsertionSort.h"
#include "RandomGenerator.h"
#include <ctime>

using namespace std;

double * InsertionSort::AlgSort(double array[], int num)
{ 
    double *data = new double[num];
    for (int i=0; i<num; i++)
        data[i] = array[i];
    int start_time =  clock(); // начальное время
    iteration_count = 0;
    transposition_count = 0;
    int lenD = num;
    double key = 0;
    int i = 0;
    for(int j = 1;j<lenD;j++){
        key = data[j];
        i = j-1;
        while(i>=0 && data[i]>key){
            iteration_count+=1;
            transposition_count+=1;
            data[i+1] = data[i];
            i = i-1;
            data[i+1]=key;
        }
    }
  
    int end_time = clock(); // конечное вре
    sort_time = end_time - start_time; // искомое время
    return data;
}
 