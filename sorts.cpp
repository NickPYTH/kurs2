#include <iostream>
#include <thread>
#include <mutex> 
#include <chrono>

#include "SelectionSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
//#include "MergeSort.cpp"
#include "QuickSort.cpp"

std::mutex mu;

void BubbleSortThread(int num, BubbleSort * bub_sort, double * data) { 
        int start, end, time;
    
        data = bub_sort->AlgSort(data, num);
        time = bub_sort->getSortTime();

        //for (int i = 0; i < num; i++)
        //  std::cout << "Value of " << i << " element is " << data[i] << std::endl;
        mu.lock();
        std::cout << "Bub Sorting time: "  << bub_sort->getSortTime() << " ms\n"; 
        mu.unlock();
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

void InsertionSortThread(int num, InsertionSort * ins_sort, double * data) { 
        int start, end, time;
    
       

        auto begin = std::chrono::steady_clock::now();
        data = ins_sort->AlgSort(data, num);
        auto finish = std::chrono::steady_clock::now();
        auto med_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - begin);
        cout<< "--INS: " << med_time.count() << " \n";

        time = ins_sort->getSortTime();
        mu.lock();
        //for (int i = 0; i < num; i++)
          //std::cout << "Insertion Sort: Value of " << i << " element is " << data[i] << std::endl;
        //std::cout << "Ins Sorting time:   "  << ins_sort->getSortTime() << " ns\n"; 
        mu.unlock();
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

void SelectionSortThread(int num, SelectionSort * sel_sort, double * data) { 
        int start, end, time;
    
        data = sel_sort->AlgSort(data, num);
        time = sel_sort->getSortTime();
        mu.lock();
        std::cout << "Sel Sorting time: "  << sel_sort->getSortTime() << " ns\n"; 
        mu.unlock();
        //cout << "Number of iterations: " << sort->getIterationCount() << endl;
        //cout << "Number of transpositions: " << sort->getTranspositionCount() << endl;
} 

void QuickSortThread(int num, QuickSort * quick_sort, double * data){
        int start, end, time;

        auto begin = std::chrono::steady_clock::now();
        data = quick_sort->AlgSort(data, num);
        auto finish = std::chrono::steady_clock::now();
        auto med_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - begin);
        cout<< "QUICK: " << med_time.count() << " \n";

        time = quick_sort->getSortTime();
        mu.lock();
        //ios_base::sync_with_stdio(false);
        //for (int i = 0; i < num; i++)
          //std::cout << "Quick Sort: Value of " << i << " element is " << data[i] << std::endl;
        
        //std::cout << "Quick Sorting time: "  << quick_sort->getSortTime() << " ns\n"; 
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
    
    thread quickSort_thread(QuickSortThread, num, quick_sort, data);
    quickSort_thread.join();
    //thread func_thread(BubbleSortThread, num, bub_sort, data);
    //func_thread.detach();
    thread func_thread2(InsertionSortThread, num, ins_sort, data);
    func_thread2.detach();
    //thread func_thread3(SelectionSortThread, num, sel_sort, data);
    //func_thread3.detach();
    
    system("pause");
    return 0;
}