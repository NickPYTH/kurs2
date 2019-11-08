#include <iostream>
#include <thread>

#include "SelectionSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
//#include "MergeSort.cpp"
//#include "QuickSort.cpp"

using namespace std;

void BubbleSortThread(int num, BubbleSort * bub_sort, double * data) { 
        int start, end, time;
    
        data = bub_sort->AlgSort(data, num);
        time = bub_sort->getSortTime();

        //for (int i = 0; i < num; i++)
        //  std::cout << "Value of " << i << " element is " << data[i] << std::endl;
        cout << "Bub Sorting time: "  << bub_sort->getSortTime() << "ms" << endl; 
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

void InsertionSortThread(int num, InsertionSort * ins_sort, double * data) { 
        int start, end, time;
    
        data = ins_sort->AlgSort(data, num);
        time = ins_sort->getSortTime();

        //for (int i = 0; i < num; i++)
        //  std::cout << "Value of " << i << " element is " << data[i] << std::endl;
    
        cout << "Ins Sorting time: "  << ins_sort->getSortTime() << "ms" << endl; 
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

void SelectionSortThread(int num, SelectionSort * sel_sort, double * data) { 
        int start, end, time;
    
        data = sel_sort->AlgSort(data, num);
        time = sel_sort->getSortTime();

        //for (int i = 0; i < num; i++)
        //  std::cout << "Value of " << i << " element is " << data[i] << std::endl;
    
        cout << "Ins Sorting time: "  << sel_sort->getSortTime() << "ms" << endl; 
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

int main(){
    int num, start, end, time;

    cout << "Enter array size: ";
    cin >> num;  // array size
    cout << "enter start ";
    cin >> start;  // array size
    cout << "Enter max "; // на разных выборках упоряд ж обратно упоряд ж хаотично ж одинаковые значения
    cin >> end;  // array size

    double *data = new double[num];

    RandomGenerator *rand = new RandomGenerator(num, start, end, data);
    data = rand->getRandArray();
    BubbleSort *bub_sort = new BubbleSort();
    InsertionSort *ins_sort = new InsertionSort();
    SelectionSort *sel_sort = new SelectionSort();
    
    ios_base::sync_with_stdio(false);
    thread func_thread(BubbleSortThread, num, bub_sort, data);
    func_thread.detach();
    thread func_thread2(InsertionSortThread, num, ins_sort, data);
    func_thread2.detach();
    thread func_thread3(SelectionSortThread, num, sel_sort, data);
    func_thread3.detach();

    system("pause");
    return 0;
}