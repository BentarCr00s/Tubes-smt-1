#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int nomor_induk[50];
struct Mahasiswa
{
    string jurusan[50];
    string nama_Mahasiswa[50];
    string gender[50];
    string kota[50];
    string tgllahir[50];
} mhs[50];

int x = 0;
int nimgen;

void menu_utama();
int tambah_data();
void nim();
void view();

int main()
{
    nim();
    menu_utama();
    return 0;
}

void nim()
{
    int nimgen = 220000;
    for (int i = 0; i < 50; i++)
    {
        nomor_induk[i] = nimgen;
        nimgen++;
    }
}

void menu_utama()
{
    int pilihan;
    do
    {
        cout << "\n\t|==========================================|";
        cout << "\n\t|              SELAMAT DATANG              |";
        cout << "\n\t|==========================================|";
        cout << "\n\t|  1. Input Data Mahasiswa                 |";
        cout << "\n\t|  2. Tampilkan Mahasiswa terdaftar        |";
        cout << "\n\t|  3. Cari Mahasiswa                       |";
        cout << "\n\t|  4. Edit Mahasiswa                       |";
        cout << "\n\t|  5. Urutkan Mahasiswa                    |";
        cout << "\n\t|  6. Export to CSV                        |";
        cout << "\n\t|  7. Keluar                               |";
        cout << "\n\t|  1. Daftarkan Mahasiswa                  |";
        cout << "\n\t|  2. Tampilkan Mahasiswa terdaftar        |";
        cout << "\n\t|  3. Cari Mahasiswa                       |";
        cout << "\n\t|  4. Edit Mahasiswa                       |";
        cout << "\n\t|  5. Urutkan Mahasiswa                    |";
        cout << "\n\t|  6. Export to CSV                        |";
        cout << "\n\t|  7. Keluar                               |";
        cout << "\n\t|==========================================|";
        cout << "\n\tMasukkan pilihan menu (1 - 6) = ";
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
            view();
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
void view()
{
    for (int i = 0; i < x; i++)
    {
        cout << "NIM              : " << nomor_induk[i] << endl;
        cout << "Nama Mahasiswa   : " << mhs[i].nama_Mahasiswa[i] << endl;
        cout << "Jenis Kelamin    : " << mhs[i].gender << endl;
        cout << "Jurusan          : " << mhs[i].jurusan << endl;
        cout << "Asal Kota        : " << mhs[i].kota << endl;
        cout << "Tanggal Lahir    : " << mhs[i].tgllahir << endl
             << endl;
    }
}
int tambah_data()
{
    int m;
    int y;
    cout << "Masukan Nama Mahasiswa              : ";
    cin >> mhs[x].nama_Mahasiswa;
    cout << "Masukan Jenis Kelamin               : ";
    cin >> mhs[x].gender;
    cout << "Masukan Jurusan                     : ";
    cin >> mhs[x].jurusan;
    cout << "Masukan Asal Kota                   : ";
    cin >> mhs[x].kota;
    cout << "Masukan Tanggal Lahir (DD/MM/YY)    : ";
    cin >> mhs[x].tgllahir;
    x++;
}