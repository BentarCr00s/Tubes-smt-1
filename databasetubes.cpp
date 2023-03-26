#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int nim[25];
    string nama[25], prodi[25];

    for (int i = 0; i <= 1; i++)
    {
        cout << "Input NIM = ";
        cin >> nim[i];
        cout << "Input Nama = ";
        cin >> nama[i];
        cout << "Input Prodi = ";
        cin >> prodi[i];
    }
    ofstream myFile("test.csv");

    for (int i = 0; i <= 1; i++)
    {
        myFile << nim[i] << "," << nama[i] << "," << prodi[i] << endl;
    }

    myFile.close();
    return 0;
}