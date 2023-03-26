#include <iostream> // Standar Input Output
#include <cstdlib>  // Standar Library
#include <cstring>  // String
#include <fstream>  // Input Output Stream
#include <ctime>    // Time

using namespace std; // namespace

// Global Variable disini
int pilihan,n;

// Declare struct disini
struct tanggallahir
{
    int tanggal;
    char bulan[50];
    int tahun;
    char cari;
};
typedef struct tanggallahir tgl;

struct jurusan
{
    char alamat[50];
    char jurusan[50];
};
typedef struct jurusan jurusan;

struct Mahasiswa
{
    int nomor_induk;
    char nama_Mahasiswa[50];

    char gender[50];
    jurusan jrsfl;
    tgl tglfl;
};
typedef struct Mahasiswa fl;
fl a[50];

void menu_utama();
void tambah_data();

    int main()
{
    menu_utama();
    return 0;
}

void menu_utama()
{
    int pilihan;
    do
    {
        |==========================================|
        |              SELAMAT DATANG              |
        |==========================================|
        |  1. Daftarkan Mahasiswa                  |
        |  2. Tampilkan Mahasiswa terdaftar        |
        |  3. Cari Mahasiswa                       |
        |  4. Edit Mahasiswa                       |
        |  5. Urutkan Mahasiswa                    |
        |  6. Keluar                               |
        |==========================================|
        Masukkan pilihan menu (1-6)= 
        cin >> pilihan;
        system("cls");

        switch (pilihan)
        {
        case 1:
        {
            system("cls");
            tambah_data();
            break;
        }
        case 2:
        {
            system("cls");
            // view_data();
            break;
        }
        case 3:
        {
            system("cls");
            // cari_data();
            break;
        }
        case 4:
        {
            system("cls");
            // ubah_data();
            break;
        }
        case 5:
        {
            system("cls");
            // urutkan_data();
            break;
        }
        case 6:
        {
            cout << "             T E R I M A  K A S I H                 
            exit(0);
            break;
        }
        default:
        {
            cout << "\n\n[Keterangan] :
            cout << "\n ======================================================
            cout << "\n| Pilihan menu tidak ditemukan...                      |
            cout << "\n|======================================================|
            cout << "\nPress [ANY KEY] to back to menu\n
            system("cls");
            menu_utama();
        }
        }
    } while (pilihan >= 1 && pilihan <= 6);
}

void tambah_data()
{ 
    cout << "Masukan Nomor Induk      : 
    cin >> a[n].nomor_induk;
    cout << "Masukan Nama Mahasiswa   : 
    cin >> a[n].nama_Mahasiswa;
    cout << "Masukan Jenis Kelamin    : 
    cin >> a[n].gender;
    cout << "Masukan Jurusan          : 
    cin >> a[n].jrsfl.jurusan;
    cout << "Masukan Alamat           : 
    cin >> a[n].jrsfl.alamat;
    cout << "Masukan Tanggal Lahir    : 
    cin >> a[n].tglfl.tanggal;
    cout << "Masukan Bulan Lahir      : 
    cin >> a[n].tglfl.bulan;
    cout << "Masukan Tahun Lahir      : 
    cin >> a[n].tglfl.tahun;
}