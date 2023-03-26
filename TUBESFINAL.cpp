#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// deklarasi variabel
struct Mahasiswa
{
    int nim;
    string nama;
    string jenis_kelamin;
    string tanggal_lahir;
    string jurusan;
    string alamat;
    string ukt;
};

struct Jurusan
{
    string nama_jurusan;
    string fakultas;
};

vector<Mahasiswa> data_mahasiswa;
vector<Jurusan> data_jurusan;

// fungsi tambah mahasiswa
int tambahMahasiswaBaru()
{
    Mahasiswa m;
    int cek;
    cout << "Masukkan NIM           : ";
    cin >> m.nim;
    cek = log10(m.nim) + 1;
    if (cek != 7)
    {
        cout << "NIM TIDAK VALID\n";
        return tambahMahasiswaBaru();
    }
    cout << "Masukkan Nama          : ";
    cin.ignore();
    getline(cin, m.nama);
    cout << "Masukkan Jenis Kelamin (L/P): ";
    cin >> m.jenis_kelamin;
    cout << "Masukkan Tanggal Lahir : ";
    cin >> m.tanggal_lahir;
    cout << "Masukkan Jurusan       : ";
    cin.ignore();
    getline(cin, m.jurusan);
    cout << "Masukkan Alamat        : ";
    getline(cin, m.alamat);
    cout << "Masukkan UKT           : ";
    cin >> m.ukt;
    data_mahasiswa.push_back(m);
    cout << " " << endl;
    cout << "[Keterangan]           :" << endl;
    cout << "=======================================" << endl;
    cout << "Data Mahasiswa Berhasil Ditambahkan..." << endl;
    cout << "=======================================" << endl;
}

void tambahJurusanBaru()
{
    Jurusan j;
    cout << "Masukkan Nama Jurusan  : ";
    cin.ignore();
    getline(cin, j.nama_jurusan);
    cout << "Masukkan Fakultas      : ";
    getline(cin, j.fakultas);
    data_jurusan.push_back(j);
    cout << " " << endl;
    cout << "[Keterangan]           :" << endl;
    cout << "=======================================" << endl;
    cout << "Data Jurusan Berhasil Ditambahkan..." << endl;
    cout << "=======================================" << endl;
}

void urutkanDataMahasiswa()
{
    int n = data_mahasiswa.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data_mahasiswa[j].nim > data_mahasiswa[j + 1].nim)
            {
                // Menukar elemen j dan j + 1
                Mahasiswa temp = data_mahasiswa[j];
                data_mahasiswa[j] = data_mahasiswa[j + 1];
                data_mahasiswa[j + 1] = temp;
            }
        }
    }
    cout << " " << endl;
    cout << "[Keterangan]           :" << endl;
    cout << "=======================================" << endl;
    cout << "Data Mahasiswa Berhasil Diurutkan..." << endl;
    cout << "=======================================" << endl;
}
void ubahDataMahasiswa()
{
    int nim;
    cout << "---------------Ubah Data Mahasiswa---------------" << endl;
    cout << "Masukkan NIM Mahasiswa yang akan diubah: " << endl;
    cout << "-------------------------------------------------" << endl;
    cin >> nim;
    for (int i = 0; i < data_mahasiswa.size(); i++)
    {
        if (data_mahasiswa[i].nim == nim)
        {
            cout << "Masukkan Nama          : ";
            cin.ignore();
            getline(cin, data_mahasiswa[i].nama);
            cout << "Masukkan Jenis Kelamin : ";
            cin >> data_mahasiswa[i].jenis_kelamin;
            cout << "Masukkan Tanggal Lahir : ";
            cin >> data_mahasiswa[i].tanggal_lahir;
            cout << "Masukkan Jurusan       : ";
            cin.ignore();
            getline(cin, data_mahasiswa[i].jurusan);
            cout << "Masukkan Alamat        : ";
            getline(cin, data_mahasiswa[i].alamat);
            cout << "Masukkan UKT           : ";
            cin >> data_mahasiswa[i].ukt;
            cout << " " << endl;
            cout << "[Keterangan]           :" << endl;
            cout << "=======================================" << endl;
            cout << "Data Mahasiswa Berhasil Diubah..." << endl;
            cout << "=======================================" << endl;
            break;
        }
    }
}

void ubahProfilJurusan()
{
    string fakultas;
    cout << "Masukkan Fakultas yang akan diubah : ";
    cin.ignore();
    getline(cin, fakultas);
    for (int i = 0; i < data_jurusan.size(); i++)
    {
        if (data_jurusan[i].fakultas == fakultas)
        {
            cout << "Masukkan Nama Jurusan      : ";
            getline(cin, data_jurusan[i].nama_jurusan);
            cout << "Masukkan Fakultas          : ";
            getline(cin, data_jurusan[i].fakultas);
            cout << " " << endl;
            cout << "[Keterangan]           :" << endl;
            cout << "=======================================" << endl;
            cout << "Data Jurusan Berhasil Diubah..." << endl;
            cout << "=======================================" << endl;
            break;
        }
    }
}

void lihatMahasiswa()
{
    cout << "Data Mahasiswa     :\n";
    for (int i = 0; i < data_mahasiswa.size(); i++)
    {
        cout << "NIM            : " << data_mahasiswa[i].nim << endl;
        cout << "Nama           : " << data_mahasiswa[i].nama << endl;
        cout << "Jenis Kelamin  : " << data_mahasiswa[i].jenis_kelamin << endl;
        cout << "Tanggal Lahir  : " << data_mahasiswa[i].tanggal_lahir << endl;
        cout << "Jurusan        : " << data_mahasiswa[i].jurusan << endl;
        cout << "Alamat         : " << data_mahasiswa[i].alamat << endl;
        cout << "UKT            : " << data_mahasiswa[i].ukt << endl;
        cout << endl;
    }
}

void lihatJurusan()
{
    cout << "Data Jurusan       :" << endl;
    for (int i = 0; i < data_jurusan.size(); i++)
    {
        cout << "Nama Jurusan   : " << data_jurusan[i].nama_jurusan << endl;
        cout << "Fakultas       : " << data_jurusan[i].fakultas << endl;
        cout << endl;
    }
}

void lihatJurusanMahasiswaBaru()
{
    cout << "Jurusan yang dipilih Mahasiswa Baru    :" << endl;
    for (int i = 0; i < data_mahasiswa.size(); i++)
    {
        cout << data_mahasiswa[i].jurusan << endl;
    }
}

void hapusDataMahasiswa()
{
    int nim;
    cout << "Masukkan NIM Mahasiswa yang akan dihapus   : ";
    cin >> nim;
    for (int i = 0; i < data_mahasiswa.size(); i++)
    {
        if (data_mahasiswa[i].nim == nim)
        {
            data_mahasiswa.erase(data_mahasiswa.begin() + i);
            cout << " " << endl;
            cout << "[Keterangan]           :" << endl;
            cout << "=======================================" << endl;
            cout << "Data Mahasiswa Berhasil Dihapus" << endl;
            cout << "=======================================" << endl;
            break;
        }
    }
}

void hapusProfilJurusan()
{
    string fakultas;
    cout << "Masukkan Fakultas yang akan dihapus    : ";
    cin.ignore();
    getline(cin, fakultas);
    for (int i = 0; i < data_jurusan.size(); i++)
    {
        if (data_jurusan[i].fakultas == fakultas)
        {
            data_jurusan.erase(data_jurusan.begin() + i);
            cout << " " << endl;
            cout << "[Keterangan]           :" << endl;
            cout << "=======================================" << endl;
            cout << "Data Jurusan Berhasil Dihapus..." << endl;
            cout << "=======================================" << endl;
            break;
        }
    }
}

void cariDataMahasiswa()
{
    int nim;
    cout << "Masukkan NIM Mahasiswa yang akan dicari    : ";
    cin >> nim;
    for (int i = 0; i < data_mahasiswa.size(); i++)
    {
        if (data_mahasiswa[i].nim == nim)
        {
            cout << "NIM            : " << data_mahasiswa[i].nim << endl;
            cout << "Nama           : " << data_mahasiswa[i].nama << endl;
            cout << "Jenis Kelamin  : " << data_mahasiswa[i].jenis_kelamin << endl;
            cout << "Tanggal Lahir  : " << data_mahasiswa[i].tanggal_lahir << endl;
            cout << "Jurusan        : " << data_mahasiswa[i].jurusan << endl;
            cout << "Alamat         : " << data_mahasiswa[i].alamat << endl;
            cout << "UKT            : " << data_mahasiswa[i].ukt << endl;
            cout << endl;
            break;
        }
    }
}

void cariDataJurusan()
{
    string fakultas;
    cout << "Masukkan Fakultas yang akan dicari     : ";
    cin.ignore();
    getline(cin, fakultas);
    for (int i = 0; i < data_jurusan.size(); i++)
    {
        if (data_jurusan[i].fakultas == fakultas)
        {
            cout << "Nama Jurusan       : " << data_jurusan[i].nama_jurusan << endl;
            cout << "Fakultas           : " << data_jurusan[i].fakultas << endl;
            cout << endl;
            break;
        }
    }
}

void simpanDataKeCsv()
{
    ofstream outfile;
    outfile.open("data.csv");
    outfile << "NIM,Nama,Jenis Kelamin,Tanggal Lahir,Jurusan,Alamat,UKT" << endl;
    for (int i = 0; i < data_mahasiswa.size(); i++)
    {
        outfile << data_mahasiswa[i].nim << ",";
        outfile << data_mahasiswa[i].nama << ",";
        outfile << data_mahasiswa[i].jenis_kelamin << ",";
        outfile << data_mahasiswa[i].tanggal_lahir << ",";
        outfile << data_mahasiswa[i].jurusan << ",";
        outfile << data_mahasiswa[i].alamat << ",";
        outfile << data_mahasiswa[i].ukt << endl;
    }
    outfile.close();
    cout << " " << endl;
    cout << "[Keterangan]           :" << endl;
    cout << "=======================================" << endl;
    cout << "Data Berhasil Disimpan ke CSV" << endl;
    cout << "=======================================" << endl;
}

int main()
{
    string pilihan;
    int pilihanint;
    cout << "==============================================" << endl;
    cout << "Aplikasi Penerimaan Mahasiswa Baru" << endl;
    cout << "==============================================" << endl;
    cout << "--------------------INPUT---------------------" << endl;
    cout << "1. Pendaftaran Mahasiswa Baru" << endl;
    cout << "2. Tambah Jurusan Baru" << endl;
    cout << "3. Urutkan Data Mahasiswa" << endl;
    cout << "--------------------EDIT----------------------" << endl;
    cout << "4. Ubah Data Mahasiswa" << endl;
    cout << "5. Ubah Profile Jurusan" << endl;
    cout << "--------------------VIEW----------------------" << endl;
    cout << "6.  Lihat Mahasiswa yang telah terdaftar" << endl;
    cout << "7.  Lihat Jurusan" << endl;
    cout << "8.  Lihat Jurusan yang dipilih Mahasiswa Baru" << endl;
    cout << "-------------------DELETE---------------------" << endl;
    cout << "9.  Hapus Data Mahasiswa" << endl;
    cout << "10. Hapus Profile Jurusan" << endl;
    cout << "11. Hapus Pilihan Jurusan Mahasiswa" << endl;
    cout << "------------------SEARCHING-------------------" << endl;
    cout << "11. Cari Data Mahasiswa" << endl;
    cout << "12. Cari Profile Jurusan" << endl;
    cout << "13. Simpan Data ke CSV" << endl;
    cout << "14. Exit" << endl;
    cout << "Masukkan Pilihan       : ";
    cin >> pilihan;
    try
    {
        pilihanint = stoi(pilihan);
    }
    catch (const std::invalid_argument &e)
    {
        cout << "Pilihan tidak valid\n";
        system("pause");
        return main();
    }

    switch (pilihanint)
    {
    case 1:
        tambahMahasiswaBaru();
        break;
    case 2:
        tambahJurusanBaru();
        break;
    case 3:
        urutkanDataMahasiswa();
        break;
    case 4:
        ubahDataMahasiswa();
        break;
    case 5:
        ubahProfilJurusan();
        break;
    case 6:
        lihatMahasiswa();
        break;
    case 7:
        lihatJurusan();
        break;
    case 8:
        lihatJurusanMahasiswaBaru();
        break;
    case 9:
        hapusDataMahasiswa();
        break;
    case 10:
        hapusProfilJurusan();
        break;
    case 11:
        cariDataMahasiswa();
        break;
    case 12:
        cariDataJurusan();
        break;
    case 13:
        simpanDataKeCsv();
        break;
    case 14:
        break;
    default:
        cout << "Pilihan tidak valid" << endl;
        return main();
    }
    return main();
}