#include "InsertionSort.h"
#include "RandomGenerator.h"
#include <chrono>

using namespace std;

double * InsertionSort::AlgSort(double array[], int num)
{ 
    double *data = new double[num];
    for (int i=0; i<num; i++)
        data[i] = array[i];
    auto begin = std::chrono::steady_clock::now();
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
    auto end = std::chrono::steady_clock::now();
    auto med_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    sort_time = med_time.count();
    ofstream f("txtAfterSorting/InsertionSort.txt");
    for(int i = 0; i < num; i++)
            f << data[i] << "\n";
    return data;
}
 