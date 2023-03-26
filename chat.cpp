#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
  // minta input dari pengguna
  cout << "Enter a value: ";
  int x;
  cin >> x;

  // cek tipe data dari input dengan typeid() dan name()
  cout << "The type of the value you entered is "
            << typeid(x).name() << endl;

  return 0;
}
