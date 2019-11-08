#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
class RandomGenerator
{   
private:
    int num;
    int start;
    int end;
    double *array;

public:
    RandomGenerator(int num, int start, int end, double data[]);
    void setStart(int start_m){start = start_m;};
    void setEnd(int end_m){end = end_m;};
    void setNum(int num_m){num = num_m;};
    void SetArray(double array[]);
    void Randomizer(int num, int star, int end);
    double * getRandArray();
};

#endif