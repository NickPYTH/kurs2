#include <iostream>
#include <thread>
#include <mutex> 
#include <chrono>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "SelectionSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"

std::mutex mu;

string number_converter(long int m_number){ // todo double
        string number;
        m_number = abs(m_number);
        if (m_number < 1000){
                number = std::to_string(m_number);
                number += " nano-seconds";
        }
        else if (m_number >= 1000 && m_number < 1000000){
                m_number /= 1000;
                number = std::to_string(m_number);
                number += " micro-seconds";
        }
        else if (m_number >= 1000000 && m_number < 1000000000) {
                m_number/=1000000;
                number = std::to_string(m_number);
                number += " milly-seconds";
        }
        else {
                m_number/=1000000000;
                number = std::to_string(m_number);
                number += " seconds";
        }
        return number;
}

int main(){
    system("cls");
    int num, start, end, choise, time;
    bool status;
    string data_name="empty now :)";
    string time_str;
    double *data;

    while(!status){
        std::cout << "<~~~~~~~~~~Main menu~~~~~~~~~~>" << "\t\t\tStatus\n";
        std::cout << "<1-Create new file for sorting>" << "\t\tCurrent file is " << data_name << "\n";
        std::cout << "<2-Going to sort!>\n";
        std::cout << "<0-Quit program>\n";
        std::cout << "----> ";
        std::cin >> choise;
        //todo rus
        //name==filename
        //не удалять файлы
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
                                //todo создавать массив внутри генератора
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
        case 2:{
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
                                BubbleSort *bub_sort = new BubbleSort();
                                data = bub_sort->AlgSort(data, num);
                                time_str = number_converter(bub_sort->getSortTime());
                                std::cout << "Bubble sorting time:   "  << time_str << "\n"; 
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
                                time_str = number_converter(sel_sort->getSortTime());
                                std::cout << "Selection sorting time:   "  << time_str << "\n"; 
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
                                time_str = number_converter(ins_sort->getSortTime());
                                std::cout << "Insertion sorting time:   "  << time_str << "\n"; 
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
                                time_str = number_converter(quick_sort->getSortTime());
                                std::cout << "Quick sorting time:   "  << time_str << "\n"; 
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
                                ofstream f("txtAfterSorting/MergeSort.txt");
                                for(int i = 0; i < num; i++)
                                        f << data[i] << "\n";
                                time_str = number_converter(merge_sort->getSortTime());
                                std::cout << "Merge sorting time:   "  << time_str << "\n"; 
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
                                bub_sort->AlgSort(data, num);
                                string time;
                                time = number_converter(bub_sort->getSortTime());
                                cout << time << endl;
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