#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    int start, end, num;
    double *array;
    double math_f = 0;
    double summall = 0;
    double dispers = 0;
    double gausse = 0;
    cin >> num;
    cin >> start;
    cin >> end;
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
}