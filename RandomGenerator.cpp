#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int num, int start, int end, double data[]){
    setNum(num);
    setStart(start);
    setEnd(end);
    SetArray(data);
    Randomizer(num, start, end);
};

void RandomGenerator::SetArray(double m_array[])
{
   //todo remove?
    array = (double *)malloc(num * sizeof(double));
    for (int i = 0; i < num; i++) {
        array[i] = m_array[i];
    }
}

double * RandomGenerator::getRandArray(){
    return array;
}

void RandomGenerator::Randomizer(int num, int start, int end){     
    double *array;
    double math_f = 0;
    double summall = 0;
    double dispers = 0;
    double gausse = 0;
    array = (double *)malloc(num * sizeof(double));

    fstream fout("RandomNumbers.txt", std::ios::out);
    if (!fout)
    {
        cout << "File not found\n";
    }
    else{
        for(int i=0; i<num; i++){
            array[i] = start + rand() % (end - start);
        }
    }

    cout << endl;

    for (int i=0;i<num;i++)
    {
        summall+=array[i];
        math_f+=array[i]*i;
    }
    math_f=math_f/summall;
    printf("Expected value = %3.5f\n",math_f);

    for (int i=0;i<num;i++)
    {
        dispers+=(i-math_f)*(i-math_f)*(array[i]);
    }
    dispers=dispers/summall;
    cout << "Dispers value = " << dispers << "\n";

    for (int i=0;i<num;i++)
    {
        gausse=(long double)summall*exp(-((i-math_f)*(i-math_f))/(2*dispers))/(sqrt(2*3.14159265*dispers));
        fout << gausse << "\n";
    }

    fout.close();
};
