#include <iostream>
#include <cmath>
using namespace std;

// fungsi trigonometri
double sin(double x)
{
    return sin(x);
}
double cos(double x)
{
    return cos(x);
}
double tan(double x)
{
    return tan(x);
}

// fungsi untuk menyelesaikan turunan
double turunanSin(double x)
{
    return cos(x);
}

double turunanCos(double x)
{
    return -sin(x);
}

double turunanTan(double x)
{
    return 1 / (cos(x) * cos(x));
}

int main()
{
    double x;

    cout << "Masukkan nilai x: ";
    cin >> x;

    cout << "Turunan sin(x): " << turunanSin(x) << endl;
    cout << "Turunan cos(x): " << turunanCos(x) << endl;
    cout << "Turunan tan(x): " << turunanTan(x) << endl;

    return 0;
}