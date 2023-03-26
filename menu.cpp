#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Global Variable disini
int pilihan, n = 0;

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
    int nomor_induk[50];
    char nama_Mahasiswa[50];

    char gender[50];
    jurusan jrsfl;
    tgl tglfl;
};
typedef struct Mahasiswa fl;
fl a[50];

void menu_utama();

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
    menu:
        cout << "\n\t|==========================================|";
        cout << "\n\t|              SELAMAT DATANG              |";
        cout << "\n\t|==========================================|";
        cout << "\n\t|  1. Daftarkan Mahasiswa                  |";
        cout << "\n\t|  2. Tampilkan Mahasiswa terdaftar        |";
        cout << "\n\t|  3. Cari Mahasiswa                       |";
        cout << "\n\t|  4. Edit Mahasiswa                       |";
        cout << "\n\t|  5. Urutkan Mahasiswa                    |";
        cout << "\n\t|  6. Keluar                               |";
        cout << "\n\t|==========================================|";
        cout << "\n\tMasukkan pilihan menu (1-6)= ";
        cin >> pilihan;
        system("cls");

        switch (pilihan)
        {
        case 1:
        {
            system("cls");
            // tambah_data();
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
            cout << "             T E R I M A  K A S I H                 ";
            exit(0);
            break;
        }
        default:
        {
            cout << "\n\n[Keterangan] :";
            cout << "\n ======================================================";
            cout << "\n| Pilihan menu tidak ditemukan...                      |";
            cout << "\n|======================================================|";
            cout << "\nPress [ANY KEY] to back to menu\n";
            system("cls");
            menu_utama();
        }
        }
    } while (pilihan >= 1 && pilihan <= 6);
}

void input(int i)
{
    cout << "[Mahasiswa ke-"<< i <<"] \n", i + 1;
    cout << "Masukan Nomor Induk      : ";
    cin >> a[i].nomor_induk;
    cout << "Masukan Nama Mahasiswa   : ";
    cin >> a[i].nama_Mahasiswa;
    cout << "Masukan Jenis Kelamin    : ";
    cin >> a[i].gender;
    cout << "Masukan Jurusan          : ";
    cin >> a[i].jrsfl.jurusan;
    cout << "Masukan Alamat           : ";
    cin >> a[i].jrsfl.alamat;
    cout << "Masukan Tanggal Lahir    : ";
    cin >> a[i].tglfl.tanggal;
    cout << "Masukan Bulan Lahir      : ";
    cin >> a[i].tglfl.bulan;
    cout << "Masukan Tahun Lahir      : ";
    cin >> a[i].tglfl.tahun;
}