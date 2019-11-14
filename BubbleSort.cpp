#include "BubbleSort.h"
#include "RandomGenerator.h"
#include "RandomGenerator.cpp"
#include <chrono>
#include <fstream>

using namespace std;

BubbleSort::BubbleSort()
{}

double * BubbleSort::AlgSort(double array[], int num)
{ 
    double *data = new double[num];
    for (int i=0; i<num; i++)
        data[i] = array[i];
    auto begin = std::chrono::steady_clock::now();
    iteration_count = 0;
    transposition_count = 0;
    int lenD = num; // 5 = 10 6 = 15(5) 7 = 21(6) 8 = 28(7)
    double tmp = 0;
    for(int i = 0;i<lenD;i++){
        for(int j = (lenD-1);j>=(i+1);j--){
            iteration_count+=1;
            if(data[j]<data[j-1]){
                transposition_count+=1;
                tmp = data[j];
                data[j]=data[j-1];
                data[j-1]=tmp;
            }
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto med_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    sort_time = med_time.count();

    ofstream f("txtAfterSorting/BubbleSort.txt");
    for(int i = 0; i < num; i++)
            f << data[i] << "\n";
    return data;
}

 