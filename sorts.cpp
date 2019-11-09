#include <iostream>
#include <thread>
#include <mutex> 
#include <chrono>

#include "SelectionSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"

std::mutex mu;

void BubbleSortThread(int num, BubbleSort * bub_sort, double * data) { 
        int start, end, time;
    
        data = bub_sort->AlgSort(data, num);
        time = bub_sort->getSortTime();

        //for (int i = 0; i < num; i++)
        //  std::cout << "Value of " << i << " element is " << data[i] << std::endl;
        mu.lock();
        std::cout << "Bub Sorting time:   "  << bub_sort->getSortTime() << " ns\n"; 
        mu.unlock();
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

void InsertionSortThread(int num, InsertionSort * ins_sort, double * data) { 
        int start, end, time;
        data = ins_sort->AlgSort(data, num);

        time = ins_sort->getSortTime();
        mu.lock();
        //for (int i = 0; i < num; i++)
          //std::cout << "Insertion Sort: Value of " << i << " element is " << data[i] << std::endl;
        std::cout << "Ins Sorting time:   "  << ins_sort->getSortTime() << " ns\n"; 
        mu.unlock();
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

void SelectionSortThread(int num, SelectionSort * sel_sort, double * data) { 
        int start, end, time;
    
        data = sel_sort->AlgSort(data, num);
        time = sel_sort->getSortTime();
        mu.lock();
        std::cout << "Sel Sorting time:   "  << sel_sort->getSortTime() << " ns\n"; 
        mu.unlock();
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

void QuickSortThread(int num, QuickSort * quick_sort, double * data){
        int start, end, time;

        data = quick_sort->AlgSort(data, num);
        time = quick_sort->getSortTime();
        mu.lock();
        //ios_base::sync_with_stdio(false);
        //for (int i = 0; i < num; i++)
          //std::cout << "Quick Sort: Value of " << i << " element is " << data[i] << std::endl;
        
        std::cout << "Quick Sorting time: "  << quick_sort->getSortTime() << " ns\n"; 
        mu.unlock();
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
}

void MergeSortThread(int num, MergeSort * merge_sort, double * data){
        int start, end, time;

        data = merge_sort->AlgSort(data, num);
        time = merge_sort->getSortTime();
        mu.lock();
        //ios_base::sync_with_stdio(false);
        //for (int i = 0; i < num; i++)
          //std::cout << "Quick Sort: Value of " << i << " element is " << data[i] << std::endl;
        
        std::cout << "Merge Sorting time: "  << merge_sort->getSortTime() << " ns\n"; 
        mu.unlock();
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
}

int main(){
    int num, start, end, time;

    std::cout << "Enter array size: ";
    std::cin >> num;  // array size
    std::cout << "enter start ";
    std::cin >> start;  // array size
    std::cout << "Enter max "; // на разных выборках упоряд ж обратно упоряд ж хаотично ж одинаковые значения
    std::cin >> end;  // array size

    double *data = new double[num];

    RandomGenerator *rand = new RandomGenerator(num, start, end, data);
    data = rand->getRandArray();
    BubbleSort *bub_sort = new BubbleSort();
    InsertionSort *ins_sort = new InsertionSort();
    SelectionSort *sel_sort = new SelectionSort();
    QuickSort *quick_sort = new QuickSort();
    MergeSort *merge_sort = new MergeSort();
    
    
    thread bubleSort_thread(BubbleSortThread, num, bub_sort, data);
    bubleSort_thread.detach();
    thread insertionSort_thread(InsertionSortThread, num, ins_sort, data);
    insertionSort_thread.detach();
    thread selectionSort_thread(SelectionSortThread, num, sel_sort, data);
    selectionSort_thread.detach();
    thread mergeSort_thread(MergeSortThread, num, merge_sort, data);
    mergeSort_thread.detach();
    thread quickSort_thread(QuickSortThread, num, quick_sort, data);
    quickSort_thread.detach();
    
    system("pause");
    return 0;
}