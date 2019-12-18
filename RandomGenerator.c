#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream fs("RandomNumbers.txt");
    if (!fs)
    {
        cout << "File not found\n";
        system("pause");
    }
    int count = 0;
    int a;
    char ch;
 
    while (!(fs.fail() || fs.eof()))
    {
        fs >> a; 
        fs >> ch;
        count++;
    }
 
 
    fs.clear();
    fs.seekg(0);
    int *mas = new int[count];
    for (int i = 0; i<count; i++)
        fs >> mas[i],
        fs >> ch;
    for (int i = 0; i<count; i++)
        cout << mas[i] << ' ';
    cout << "\n";
    fs.close();
    system("pause");
}