#include <iostream>
#include <thread>
#include <mutex> 
#include <chrono>
#include <stdlib.h>
#include <string.h>

#include "SelectionSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"

std::mutex mu;

string number_converter(long int m_number){
        string number;
        if (m_number < 1000000){
                number = std::to_string(m_number);
                number += " ns";
        }
        else if (m_number < 10000000){
                m_number /= 1000000;
                number = std::to_string(m_number);
                number += " ms";
        }
        else {
                m_number/=10000000;
                number = std::to_string(m_number);
                number += " ms";
        }
        return number;
}

void BubbleSortThread(int num, BubbleSort * bub_sort, double * data) { 
        int start, end, time;
        data = bub_sort->AlgSort(data, num);
        mu.lock();
        std::cout << "Bubble sort\n";  
        std::cout << "\t|----> time "  << bub_sort->getSortTime() << "\n"; 
        std::cout << "\t|----> iterations "  << bub_sort->getIterationCount() << "\n"; 
        std::cout << "\t|----> transpositions "  << bub_sort->getTranspositionCount() << "\n\n"; 
        mu.unlock();
} 

void InsertionSortThread(int num, InsertionSort * ins_sort, double * data) { 
        int start, end, time;
        data = ins_sort->AlgSort(data, num);
        mu.lock();
        std::cout << "Insertion sort\n";  
        std::cout << "\t|----> time "  << ins_sort->getSortTime() << "\n"; 
        std::cout << "\t|----> iterations "  << ins_sort->getIterationCount() << "\n"; 
        std::cout << "\t|----> transpositions "  << ins_sort->getTranspositionCount() << "\n\n"; 
        mu.unlock();
} 

void SelectionSortThread(int num, SelectionSort * sel_sort, double * data) { 
        int start, end, time;
        data = sel_sort->AlgSort(data, num);
        mu.lock();
        std::cout << "Selection sort\n";  
        std::cout << "\t|----> time "  << sel_sort->getSortTime() << "\n"; 
        std::cout << "\t|----> iterations "  << sel_sort->getIterationCount() << "\n"; 
        std::cout << "\t|----> transpositions "  << sel_sort->getTranspositionCount() << "\n\n";  
        mu.unlock();
} 

void QuickSortThread(int num, QuickSort * quick_sort, double * data){
        int start, end, time;
        data = quick_sort->AlgSort(data, num);
        time = quick_sort->getSortTime();
        mu.lock();
        std::cout << "Quick sort\n";  
        std::cout << "\t|----> time "  << quick_sort->getSortTime() << "\n"; 
        std::cout << "\t|----> iterations "  << quick_sort->getIterationCount() << "\n"; 
        std::cout << "\t|----> transpositions "  << quick_sort->getTranspositionCount() << "\n\n";  
        mu.unlock();
}

void MergeSortThread(int num, MergeSort * merge_sort, double * data){
        int start, end, time;
        data = merge_sort->AlgSort(data, num);
        mu.lock();
        std::cout << "Merge sort\n";  
        std::cout << "\t|----> time "  << merge_sort->getSortTime() << "\n"; 
        std::cout << "\t|----> iterations "  << merge_sort->getIterationCount() << "\n"; 
        std::cout << "\t|----> transpositions "  << merge_sort->getTranspositionCount() << "\n\n";  
        mu.unlock();
}

int main(){
    system("cls");
    int num, start, end, choise, time;
    bool status;
    string data_name="empty now :)";
    double *data;

    while(!status){
        std::cout << "<~~~~~~~~~~Main menu~~~~~~~~~~>" << "\t\t\tStatus\n";
        std::cout << "<1-Create new file for sorting>" << "\t\tCurrent file is " << data_name << "\n";;
        std::cout << "<2-Open file from folder>\n";
        std::cout << "<3-Going to sort!>\n";
        std::cout << "<0-Quit program>\n";
        std::cout << "----> ";
        std::cin >> choise;

        switch (choise)
        {
        case 0:
                status = true;
                break;
        case 1:{
                status = true;
                while(status){
                system("cls");
                        std::cout << "<~~~~~~~~~~New file menu~~~~~~~~~~>\n";
                        std::cout << "<1-Generate random numbers>\n";
                        std::cout << "<2-Scan from keyboard>\n";
                        if (data_name != "empty now :)")
                                std::cout << "<3-Delete file " << data_name << ">\n";
                        std::cout << "<0-Go back>\n";
                        std::cout << "----> ";
                        std::cin >> choise;

                        switch (choise)
                        {
                        case 0:
                                system("cls");
                                status = false;
                                break;
                        case 1:{
                                system("cls");
                                std::cout << "Enter data name----> ";
                                std::cin >> data_name; 
                                std::cout << "Enter data size----> ";
                                std::cin >> num;
                                std::cout << "Enter min----> ";
                                std::cin >> start;  // array size
                                std::cout << "Enter max----> "; // на разных выборках упоряд ж обратно упоряд ж хаотично ж одинаковые значения
                                std::cin >> end;
                                data = new double[num];
                                RandomGenerator *rand = new RandomGenerator(num, start, end, data);
                                data = rand->getRandArray();
                                data_name = "*"+data_name+"*";
                                break;}
                        case 2:{
                                system("cls");
                                std::cout << "Enter data name----> ";
                                std::cin >> data_name;
                                std::cout << "Enter data size----> ";
                                std::cin >> num;
                                data = new double[num];
                                for (int i=0; i<num; i++){
                                        std::cout << "Enter the " << i+1 << " ellement ----> ";
                                        std::cin >> data[i];
                                }
                                data_name = "*"+data_name+"*";
                                break;
                        }
                        case 3:{
                                data_name="empty now :)";
                                break;
                        }
                        default:
                                system("cls");
                                std::cout << "<Something went wrong, try again...>\n";
                                break;
                        }
                }
                break;
        }
        case 3:{
                system("cls");
                if (data_name != "empty now :)"){
                        std::cout << "<~~~~~~~~~~Sort menu~~~~~~~~~~>\n";
                        std::cout << "<1-Use bubble sort>\n";
                        std::cout << "<2-Use selection sort>\n";
                        std::cout << "<3-Use insertion sort>\n";
                        std::cout << "<4-Use quick sort>\n";
                        std::cout << "<5-Use merge sort>\n";
                        std::cout << "<6-Use all for comparing>\n";
                        std::cout << "<0-Go back>\n";
                        std::cout << "----> ";
                        std::cin >> choise;
                        switch (choise)
                        {
                        case 0:{
                                system("cls");
                                break;
                        }
                        case 1:{
                                system("cls");
                                char choise_c;
                                string time_str;
                                BubbleSort *bub_sort = new BubbleSort();
                                data = bub_sort->AlgSort(data, num);
                                time_str = number_converter(bub_sort->getSortTime());
                                std::cout << "Bubble sorting time:   "  << time_str << " ns\n"; 
                                std::cout << "Number of iterations: " << bub_sort->getIterationCount() << "\n";
                                std::cout << "Number of transpositions: " << bub_sort->getTranspositionCount() << "\n";
                                std::cout << "Do u want see array after sorting?(y/n): ";
                                std::cin >> choise_c;
                                if (choise_c == 'y'){
                                        for (int i = 0; i < num; i++)
                                                std::cout << "Value of " << i << " element is " << data[i] << std::endl;
                                }
                                data_name = "empty now :)";
                                system("pause");
                                system("cls");
                                break;
                        }
                         case 2:{
                                system("cls");
                                char choise_c;
                                SelectionSort *sel_sort = new SelectionSort();
                                data = sel_sort->AlgSort(data, num);
                                time = sel_sort->getSortTime();
                                std::cout << "Selection sorting time:   "  << sel_sort->getSortTime() << " ns\n"; 
                                std::cout << "Number of iterations: " << sel_sort->getIterationCount() << "\n";
                                std::cout << "Number of transpositions: " << sel_sort->getTranspositionCount() << "\n";
                                std::cout << "Do u want see array after sorting?(y/n): ";
                                std::cin >> choise_c;
                                if (choise_c == 'y'){
                                        for (int i = 0; i < num; i++)
                                                std::cout << "Value of " << i << " element is " << data[i] << std::endl;
                                }
                                data_name = "empty now :)";
                                system("pause");
                                system("cls");
                                break;
                        }
                         case 3:{
                                system("cls");
                                char choise_c;
                                InsertionSort *ins_sort = new InsertionSort();
                                data = ins_sort->AlgSort(data, num);
                                time = ins_sort->getSortTime();
                                std::cout << "Insertion sorting time:   "  << ins_sort->getSortTime() << " ns\n"; 
                                std::cout << "Number of iterations: " << ins_sort->getIterationCount() << "\n";
                                std::cout << "Number of transpositions: " << ins_sort->getTranspositionCount() << "\n";
                                std::cout << "Do u want see array after sorting?(y/n): ";
                                std::cin >> choise_c;
                                if (choise_c == 'y'){
                                        for (int i = 0; i < num; i++)
                                                std::cout << "Value of " << i << " element is " << data[i] << std::endl;
                                }
                                data_name = "empty now :)";
                                system("pause");
                                system("cls");
                                break;
                        }
                         case 4:{
                                system("cls");
                                char choise_c;
                                QuickSort *quick_sort = new QuickSort();
                                data = quick_sort->AlgSort(data, num);
                                time = quick_sort->getSortTime();
                                std::cout << "Quick sorting time:   "  << quick_sort->getSortTime() << " ns\n"; 
                                std::cout << "Number of iterations: " << quick_sort->getIterationCount() << "\n";
                                std::cout << "Number of transpositions: " << quick_sort->getTranspositionCount() << "\n";
                                std::cout << "Do u want see array after sorting?(y/n): ";
                                std::cin >> choise_c;
                                if (choise_c == 'y'){
                                        for (int i = 0; i < num; i++)
                                                std::cout << "Value of " << i << " element is " << data[i] << std::endl;
                                }
                                data_name = "empty now :)";
                                system("pause");
                                system("cls");
                                break;
                        }
                         case 5:{
                                system("cls");
                                char choise_c;
                                MergeSort *merge_sort = new MergeSort();
                                data = merge_sort->AlgSort(data, num);
                                time = merge_sort->getSortTime();
                                std::cout << "Merge sorting time:   "  << merge_sort->getSortTime() << " ns\n"; 
                                std::cout << "Number of iterations: " << merge_sort->getIterationCount() << "\n";
                                std::cout << "Number of transpositions: " << merge_sort->getTranspositionCount() << "\n";
                                std::cout << "Do u want see array after sorting?(y/n): ";
                                std::cin >> choise_c;
                                if (choise_c == 'y'){
                                        for (int i = 0; i < num; i++)
                                                std::cout << "Value of " << i << " element is " << data[i] << std::endl;
                                }
                                data_name = "empty now :)";
                                system("pause");
                                system("cls");
                                break;
                        }
                        case 6:{
                                system("cls");
                                BubbleSort *bub_sort = new BubbleSort();
                                SelectionSort *sel_sort = new SelectionSort();
                                InsertionSort *ins_sort = new InsertionSort();
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
                                getchar();getchar();
                                system("cls");
                                data_name = "empty now :)";
                                break;
                        }
                        default:
                                break;
                        }
                }
                break;
        }
        
        default:
                system("cls");
                std::cout << "<Something went wrong, try again...>\n";
                break;
        }
    }
    system("cls");
    return 0;
}