#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa
{
    string nim; // NIM mahasiswa
    string nama; // Nama mahasiswa
    int umur; // Umur mahasiswa
};

// Fungsi untuk menambahkan mahasiswa baru ke daftar
void daftarkanMahasiswa(vector<Mahasiswa>& daftarMahasiswa)
{
    // Membuat objek mahasiswa baru
    Mahasiswa mahasiswaBaru;

    // Menginput NIM mahasiswa
    cout << "Masukkan NIM mahasiswa: ";
    getline(cin, mahasiswaBaru.nim);

    // Generate NIM unik jika NIM yang dimasukkan sudah ada di daftar
    int counter = 1;
    string nimUnik = mahasiswaBaru.nim;
    while (find_if(daftarMahasiswa.begin(), daftarMahasiswa.end(), 
        [&](const Mahasiswa& m) { return m.nim == nimUnik; }) != daftarMahasiswa.end())
    {
        nimUnik = mahasiswaBaru.nim + to_string(counter);
        counter++;
    }

    mahasiswaBaru.nim = nimUnik;

    // Menginput nama mahasiswa
    cout << "Masukkan nama mahasiswa: ";
    getline(cin, mahasiswaBaru.nama);

    // Menginput umur mahasiswa
    cout << "Masukkan umur mahasiswa: ";
    cin >> mahasiswaBaru.umur;
    cin.ignore(); // Menghapus karakter baris baru setelah umur

    // Menambahkan mahasiswa ke daftar
    daftarMahasiswa.push_back(mahasiswaBaru);
}

// Fungsi untuk menampilkan daftar mahasiswa yang terdaftar
void tampilkanDaftarMahasiswa(const vector<Mahasiswa>& daftarMahasiswa)
{
    cout << endl;
    cout << "Daftar mahasiswa terdaftar:" << endl;
    cout << "-----------------------------" << endl;
    for (const Mahasiswa& m : daftarMahasiswa)
    {
        cout << "NIM: " << m.nim << endl;
        cout << "Nama: " << m.nama << endl;
