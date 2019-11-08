#include "BubbleSort.h"
#include "RandomGenerator.h"
#include "RandomGenerator.cpp"
#include <ctime>

using namespace std;

BubbleSort::BubbleSort()
{}

double * BubbleSort::AlgSort(double array[], int num)
{ 
    double *data = new double[num];
    for (int i=0; i<num; i++)
        data[i] = array[i];
    int start_time =  clock(); // начальное время
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
    int end_time = clock(); // конечное вре
    sort_time = end_time - start_time; // искомое время
    return data;
}

 