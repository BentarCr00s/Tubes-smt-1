#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <vector>


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

// Declare void disini
void menu_utama();
void tambah_data();
void view_data();
void cari_data();
void ubah_data();
void urutkan_data();

// MAIN PROGRAMNYA
int main()
{
    menu_utama();
    return 0;
}

// Menu Utama
void menu_utama()
{
    do
    {
    menu:
        cout << "\n\t ===========================================";
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
            tambah_data();
            break;
        }
        case 2:
        {
            system("cls");
            view_data();
            break;
        }
        case 3:
        {
            system("cls");
            cari_data();
            break;
        }
        case 4:
        {
            system("cls");
            ubah_data();
            break;
        }
        case 5:
        {
            system("cls");
            urutkan_data();
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
            getch();
            system("cls");
            menu_utama();
        }
        }
    } while (pilihan >= 1 && pilihan <= 6);
}

// Input Data
void input(int i)
{
    cout << ("[Mahasiswa ke-%d] \n", i + 1);
    cout << ("Masukan Nomor Induk      : ");
    fflush(stdin);
    gets(a[i].nomor_induk);
    cout << ("Masukan Nama Mahasiswa       : ");
    fflush(stdin);
    gets(a[i].nama_Mahasiswa);
    cout << ("Masukan Jenis Kelamin    : ");
    fflush(stdin);
    gets(a[i].gender);
    cout << ("Masukan Jurusan          : ");
    fflush(stdin);
    gets(a[i].jrsfl.jurusan);
    cout << ("Masukan Alamat           : ");
    fflush(stdin);
    gets(a[i].jrsfl.alamat);
    cout << ("Masukan Tanggal Lahir    : ");
    fflush(stdin);
    scanf("%d", &a[i].tglfl.tanggal);
    cout << ("Masukan Bulan Lahir      : ");
    fflush(stdin);
    gets(a[i].tglfl.bulan);
    cout << ("Masukan Tahun Lahir      : ");
    fflush(stdin);
    scanf("%d", &a[i].tglfl.tahun);
}

// Tampilkan Data
void view(int i)
{
    cout << ("\n[Mahasiswa ke-%d]", i + 1);
    cout << ("\nNomor Induk       : %s", a[i].nomor_induk);
    cout << ("\nNama Mahasiswa    : %s", a[i].nama_Mahasiswa);
    cout << ("\nJenis Kelamin     : %s", a[i].gender);
    cout << ("\nJurusan           : %s", a[i].jrsfl.jurusan);
    cout << ("\nAlamat            : %s", a[i].jrsfl.alamat);
    cout << ("\nTanggal Lahir     : %d", a[i].tglfl.tanggal);
    cout << ("\nBulan Lahir       : %s", a[i].tglfl.bulan);
    cout << ("\nTahun Lahir       : %d", a[i].tglfl.tahun);
    cout << ("\n");
}

// Update Data
void updateMahasiswa(int i)
{
    cout << ("\n[Mahasiswa ke-%d] \n", i + 1);
    cout << ("Ganti Nama         	 : ");
    fflush(stdin);
    gets(a[i].nama_Mahasiswa);
    cout << ("Ganti Jenis Kelamin  : ");
    fflush(stdin);
    gets(a[i].gender);
    cout << ("Ganti Jurusan        : ");
    fflush(stdin);
    gets(a[i].jrsfl.jurusan);
    cout << ("Ganti Alamat    	 : ");
    fflush(stdin);
    gets(a[i].jrsfl.alamat);
    cout << ("Ganti Tanggal Lahir  : ");
    fflush(stdin);
    scanf("%d", &a[i].tglfl.tanggal);
    cout << ("Ganti Bulan Lahir	 : ");
    fflush(stdin);
    gets(a[i].tglfl.bulan);
    cout << ("Ganti Tahun Lahir	 : ");
    fflush(stdin);
    scanf("%d", &a[i].tglfl.tahun);
}

// Binary Search (nomor induk Mahasiswa)
int binary_search(fl arr[], char cari[], int n)
{
    int t, hasil;
    int k = n - 1;
    int l = 0;

    while (l <= k)
    {
        t = (l + k) / 2;
        hasil = strcmp(arr[t].nomor_induk, cari);

        if (hasil == -1)
            l = t + 1;
        else if (hasil == 1)
            k = t - 1;
        else
            return t;
    }
    return -1;
}

// Insertion Sort Jika nama, nomor_induk diganti nama_Mahasiswa

void InsertionSort(fl arr[], int n) // id
{
    int i, j;
    fl key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; (j >= 0) && (strcmp(arr[j + 1].nama_Mahasiswa, arr[j].nama_Mahasiswa) < 0); j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

// Daftarkan Mahasiswa
void tambah_data()
{
    system("cls");
    cout << ("\n--- Input data Mahasiswa ---\n\n");
    input(n);
    n++;
    cout << ("\n\n[Keterangan] :");
    cout << ("\n ====================================================== ");
    cout << ("\n| Data berhasil ditambahkan...                         |");
    cout << ("\n========================================================");
    cout << ("\n>> Press [ANY KEY] to back to menu\n");
    getch();
    system("cls");
}

// Tampilkan Data
void view_data()
{
    int i;
    system("cls");
    cout << ("\n--- data Mahasiswa terdaftar ---\n");
    if (n == 0)
    {
        cout << ("\n\n[Keterangan] :");
        cout << ("\n ====================================================== ");
        cout << ("\n| Masukan data terlebih dahulu...                      |");
        cout << ("\n========================================================");
        cout << ("\n>> Press [ANY KEY] to back to menu\n");
        getch();
        system("cls");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            view(i);
        }
        cout << ("\n\n[Keterangan] :");
        cout << ("\n ====================================================== ");
        cout << ("\n| Data berhasil ditampilkan...                         |");
        cout << ("\n========================================================");
        cout << ("\n>> Press [ANY KEY] to back to menu\n");
        getch();
        system("cls");
    }
}

// Cari Data Nomor Induk
void cari_data()
{
    int i, hasil;
    system("cls");
    cout << ("\n--- Cari nomor induk Mahasiswa ---\n");
    char cariid[50];
    if (n == 0)
    {
        cout << ("\n\n[Keterangan] :");
        cout << ("\n ______________________________________________________ ");
        cout << ("\n| Masukan data terlebih dahulu...                      |");
        cout << ("\n|______________________________________________________|");
        cout << ("\n>> Press [ANY KEY] to back to menu\n");
        getch();
        system("cls");
        cari_data();
    }
    else
    {
        InsertionSort(a, n);
        cout << ("\n\n<--------------------------------->");
        cout << ("\n Data yang terdaftar :");
        cout << ("\n<--------------------------------->\n");
        for (i = 0; i < n; i++)
        {
            view(i);
        }
        cout << ("\n\n<--------------------------------->");
        cout << ("\nCari nomor induk Mahasiswa : ");
        fflush(stdin);
        gets(cariid);
        cout << ("<--------------------------------->\n\n");
        // hasil=binary_search1(a,n,cariid);
        hasil = binary_search(a, cariid, n);
        if (hasil == -1)
        {
            cout << ("[Keterangan] :");
            cout << ("\n ================================================ ");
            cout << ("\n| Tidak ditemukan ID Mahasiswa %s                    |", cariid);
            cout << ("\n==================================================");
            cout << ("\n>> Press [ANY KEY] to back to menu\n");
            getch();
            system("cls");
            cari_data();
        }
        else
        {
            cout << ("[Hasil Pencarian] :\n");
            for (i = hasil; i <= hasil; i++)
            {
                view(i);
            }
            cout << ("\n[Keterangan] :");
            cout << ("\n ======================== ");
            cout << ("\n| Data Ditemukan...      |");
            cout << ("\n==========================");
            cout << ("\n>> Press [ANY KEY] to back to menu\n");
            cout << ("\n\n");
            getch();
            system("cls");
            menu_utama();
        }
    }
}

// Ubah Data
void ubah_data()
{
    int i;
    system("cls");
    if (n == 0)
    {
        cout << ("\n\n[Keterangan] :");
        cout << ("\n ====================================================== ");
        cout << ("\n| Masukan data terlebih dahulu...                      |");
        cout << ("\n========================================================");
        cout << ("\n>> Press [ANY KEY] to back to menu\n");
        getch();
        system("cls");
    }
    else
    {
        cout << ("\n\n<--------------------------------->");
        cout << ("\n Data Mahasiswa sebelum dirubah");
        cout << ("\n<--------------------------------->\n");
        for (i = 0; i < n; i++)
        {
            view(i);
        }
        int flag = 0;
        cout << ("\n--- Ubah data Mahasiswa ---\n");
        cout << ("Masukan nomor induk Mahasiswa yang ingin diubah : ");
        char cariID[10];
        fflush(stdin);
        gets(cariID);
        for (i = 0; i < n; i++)
        {
            if (!strcmp(a[i].nomor_induk, cariID))
            {
                cout << ("\n\n<--------------------------------->");
                cout << ("\n Data Mahasiswa yang ingin dirubah");
                cout << ("\n<--------------------------------->\n");
                updateMahasiswa(i);

                cout << ("\n\n<--------------------------------->");
                cout << ("\n Hasil ubah data Mahasiswa");
                cout << ("\n<--------------------------------->\n");
                view(i);

                cout << ("\n\n[Keterangan] :");
                cout << ("\n ==================================================== ");
                cout << ("\n| Ubah data Mahasiswa berhasil...                        |");
                cout << ("\n=======================================================");
                cout << ("\n>> Press [ANY KEY] to back to menu\n");
                getch();
                system("cls");
                flag++;
                break;
            }
        }
        if (flag == 0)
        {
            cout << ("[Keterangan] :");
            cout << ("\n ================================================ ");
            cout << ("\n| Tidak ditemukan Nama Mahasiswa %s                  |", cariID);
            cout << ("\n==================================================");
            cout << ("\n>> Press [ANY KEY] to back to menu\n");
            getch();
            system("cls");
        }
    }
}

// Urutkan Data
void urutkan_data()
{
    int i;
    system("cls");
    cout << ("\n--- Pengurutan Berdasarkan Nomor Induk ---\n");
    if (n == 0)
    {
        cout << ("\n\n[Keterangan] :");
        cout << ("\n ====================================================== ");
        cout << ("\n| Masukan data Mahasiswa terlebih dahulu...                |");
        cout << ("\n========================================================");
        cout << ("\n>> Press [ANY KEY] to back to menu\n");
        getch();
        system("cls");
        urutkan_data();
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            InsertionSort(a, n);
        }

        cout << ("\n\n<--------------------------------->");
        cout << ("\n Data setelah diurutkan");
        cout << ("\n<--------------------------------->\n");
        for (i = 0; i < n; i++)
        { // jika descending, i=n-1; i>=0; i--
            view(i);
        }
        getch();
        system("cls");
        menu_utama();
    }
}