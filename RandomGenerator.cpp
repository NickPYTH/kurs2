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
    array = (double *)malloc(num * sizeof(double));
    for (int i = 0; i < num; i++) {
        array[i] = m_array[i];
    }
}

double * RandomGenerator::getRandArray(){
    return array;
}

void RandomGenerator::Randomizer(int num, int start, int end){     

    double r=0;              //uniform distributed random in [0:1]
    double alpha=-2;         //power of spectra

    double p0=0, p1=0;       //temporary var for powers
    double E=0;              //generated random

    fstream fout("RandomNumbers.txt", std::ios::out); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
    if (!fout)
    {
        cout << "File not found\n";
    }
    else{
        p0 = pow(start, alpha + 1);
        p1 = pow(end, alpha + 1);

        for(int i=0; i<num; i++){
        r = (double)rand()/RAND_MAX;
        if(r==0){                    //awoid to take log(0)
            continue;
        }
        E = pow(r * (p1 - p0) + p0, 1.0/(alpha + 1.0));
        fout << E << "\n";
        array[i] = E;
        }
        fout.close(); // закрываем файл
    }
};
