#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

// Struktur data untuk menyimpan data mahasiswa
struct Mahasiswa
{
    int NIM;
    string nama;
    string tgl_lahir;
    char gender;
    string alamat;
    string jurusan;
    string fakultas;
};

// Struktur data untuk menyimpan data jurusan
struct Jurusan
{
    string nama;
    string fakultas;
};

// Fungsi untuk mendaftarkan mahasiswa baru
void daftarMahasiswaBaru(vector<Mahasiswa> &daftarMahasiswa)
{
    Mahasiswa mhs;
    cout << "Masukkan NIM : ";
    cin >> mhs.NIM;
    cout << "Masukkan nama mahasiswa: ";
    getline(cin >> ws, mhs.nama);
    cout << "Masukkan Gender P/L: ";
    cin >> mhs.gender;
    cout << "Masukkan Alamat: ";
    getline(cin >> ws, mhs.alamat);
    cout << "Masukkan Tanggal lahir mahasiswa DD/MM/YYYY: ";
    cin >> mhs.tgl_lahir;
    // Menambahkan mahasiswa ke daftar mahasiswa
    daftarMahasiswa.push_back(mhs);
}

// Fungsi untuk menambahkan jurusan baru
void tambahJurusan(vector<Jurusan> &daftarJurusan)
{
    Jurusan jur;
    cout << "Masukkan nama jurusan: ";
    cin >> jur.nama;
    cout << "Masukkan fakultas jurusan: ";
    cin >> jur.fakultas;

    // Menambahkan jurusan ke daftar jurusan
    daftarJurusan.push_back(jur);
}

// Fungsi untuk memilih jurusan oleh mahasiswa baru
void pilihJurusan(vector<Mahasiswa> &daftarMahasiswa, vector<Jurusan> daftarJurusan)
{
    string namaMhs;
    cout << "Masukkan nama mahasiswa: ";
    cin >> namaMhs;

    // Mencari mahasiswa yang akan memilih jurusan
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        if (daftarMahasiswa[i].nama == namaMhs)
        {
            cout << "Daftar jurusan: " << endl;

            // Menampilkan daftar jurusan
            for (int j = 0; j < daftarJurusan.size(); j++)
            {
                cout << j + 1 << ". " << daftarJurusan[j].nama << endl;
            }

            // Meminta input jurusan yang dipilih oleh mahasiswa
            int pilihan;
            cout << "Masukkan nomor jurusan yang dipilih: ";
            cin >> pilihan;

            // Mengupdate data mahasiswa dengan jurusan
            daftarMahasiswa[i].jurusan = daftarJurusan[pilihan - 1].nama;
            daftarMahasiswa[i].fakultas = daftarJurusan[pilihan - 1].fakultas;
        }
    }
}

// Fungsi untuk mengubah data mahasiswa
void ubahMahasiswa(vector<Mahasiswa> &daftarMahasiswa)
{
    string namaMhs;
    cout << "Masukkan nama mahasiswa: ";
    cin >> namaMhs;

    // Mencari mahasiswa yang akan diubah
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        if (daftarMahasiswa[i].nama == namaMhs)
        {
            cout << "Masukkan nama baru mahasiswa: ";
            getline(cin >> ws, daftarMahasiswa[i].nama);
            cout << "Masukkan Gender Baru Mahasiswa P/L: ";
            cin >> daftarMahasiswa[i].gender;
            cout << "Masukkan Alamat Baru Mahasiswa: ";
            getline(cin >> ws, daftarMahasiswa[i].alamat);
            cout << "Masukkan Tanggal Lahir baru mahasiswa: ";
            cin >> daftarMahasiswa[i].tgl_lahir;
        }
    }
}

// Fungsi untuk mengubah profile jurusan
// Mencari jurusan yang akan diubah
void ubahJurusan(vector<Jurusan> &daftarJurusan)
{
    string namaJur;
    cout << "Masukkan nama jurusan: ";
    cin >> namaJur;

    // Mencari jurusan yang akan diubah
    for (int i = 0; i < daftarJurusan.size(); i++)
    {
        if (daftarJurusan[i].nama == namaJur)
        {
            cout << "Masukkan nama baru jurusan: ";
            cin >> daftarJurusan[i].nama;
            cout << "Masukkan fakultas baru jurusan: ";
            cin >> daftarJurusan[i].fakultas;
        }
    }
}

// Fungsi untuk menampilkan daftar mahasiswa
void lihatMahasiswa(vector<Mahasiswa> daftarMahasiswa)
{
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        cout << i + 1 << "\t" << daftarMahasiswa[i].NIM << " , " << daftarMahasiswa[i].nama << " , " << daftarMahasiswa[i].tgl_lahir << ", " << daftarMahasiswa[i].gender << " , " << daftarMahasiswa[i].alamat << " , " << daftarMahasiswa[i].jurusan << "," << daftarMahasiswa[i].fakultas << endl;
    }
}

// Fungsi untuk menampilkan daftar jurusan
void lihatJurusan(vector<Jurusan> daftarJurusan)
{
    for (int i = 0; i < daftarJurusan.size(); i++)
    {
        cout << i + 1 << ". " << daftarJurusan[i].nama << " (" << daftarJurusan[i].fakultas << ")" << endl;
    }
}

// Fungsi untuk menampilkan jurusan yang dipilih oleh mahasiswa
void lihatJurusanMhs(vector<Mahasiswa> daftarMahasiswa)
{
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        cout << daftarMahasiswa[i].nama << ": " << daftarMahasiswa[i].jurusan << "(" << daftarMahasiswa[i].fakultas << endl;
    }
}

// Fungsi untuk menghapus data mahasiswa
void hapusMahasiswa(vector<Mahasiswa> &daftarMahasiswa)
{
    string namaMhs;
    cout << "Masukkan nama mahasiswa: ";
    cin >> namaMhs;

    // Mencari mahasiswa yang akan dihapus
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        if (daftarMahasiswa[i].nama == namaMhs)
        {
            // Menghapus mahasiswa dari daftar
            daftarMahasiswa.erase(daftarMahasiswa.begin() + i);
        }
    }
}

// Fungsi untuk menghapus profile jurusan
void hapusJurusan(vector<Jurusan> &daftarJurusan)
{
    string namaJur;
    cout << "Masukkan nama jurusan: ";
    cin >> namaJur;

    // Mencari jurusan yang akan dihapus
    for (int i = 0; i < daftarJurusan.size(); i++)
    {
        if (daftarJurusan[i].nama == namaJur)
        {
            // Menghapus jurusan dari daftar
            daftarJurusan.erase(daftarJurusan.begin() + i);
        }
    }
}

// Fungsi untuk menghapus pilihan jurusan oleh mahasiswa
void hapusJurusanMhs(vector<Mahasiswa> &daftarMahasiswa)
{
    string namaMhs;
    cout << "Masukkan nama mahasiswa: ";
    cin >> namaMhs;

    // Mencari mahasiswa yang akan menghapus pilihan jurusan
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        if (daftarMahasiswa[i].nama == namaMhs)
        {
            // Menghapus pilihan jurusan mahasiswa
            daftarMahasiswa[i].jurusan = "";
            daftarMahasiswa[i].fakultas = "";
        }
    }
}

// Fungsi untuk mencari data mahasiswa
void cariMahasiswa(vector<Mahasiswa> daftarMahasiswa)
{
    string namaMhs;
    cout << "Masukkan nama mahasiswa: ";
    cin >> namaMhs;

    // Mencari mahasiswa
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        if (daftarMahasiswa[i].nama == namaMhs)
        {
            cout << daftarMahasiswa[i].NIM << " , " << daftarMahasiswa[i].nama << " , " << daftarMahasiswa[i].tgl_lahir << ", " << daftarMahasiswa[i].gender << " , " << daftarMahasiswa[i].alamat << " , " << daftarMahasiswa[i].jurusan << "," << daftarMahasiswa[i].fakultas << endl;
        }
    }
}

// Fungsi untuk mencari profile jurusan
void cariJurusan(vector<Jurusan> daftarJurusan)
{
    string namaJur;
    cout << "Masukkan nama jurusan: ";
    cin >> namaJur;

    // Mencari jurusan
    for (int i = 0; i < daftarJurusan.size(); i++)
    {
        if (daftarJurusan[i].nama == namaJur)
        {
            cout << daftarJurusan[i].nama << " (" << daftarJurusan[i].fakultas << ")" << endl;
        }
    }
}
// Fungsi untuk mengambil data dari file external
void bacaDariFile(vector<Mahasiswa> &daftarMahasiswa, vector<Jurusan> &daftarJurusan)
{
    ifstream fileMahasiswa("mahasiswa.txt"); // Membuka file mahasiswa
    ifstream fileJurusan("jurusan.txt");     // Membuka file jurusan

    // Membaca data mahasiswa dari file
    while (!fileMahasiswa.eof())
    {
        Mahasiswa mhs;
        fileMahasiswa >> mhs.NIM >> mhs.nama >> mhs.gender >> mhs.tgl_lahir >> mhs.alamat >> mhs.jurusan >> mhs.fakultas;
        daftarMahasiswa.push_back(mhs);
    }

    // Membaca data jurusan dari file
    while (!fileJurusan.eof())
    {
        Jurusan jur;
        fileJurusan >> jur.nama >> jur.fakultas;
        daftarJurusan.push_back(jur);
    }

    fileMahasiswa.close(); // Menutup file mahasiswa
    fileJurusan.close();   // Menutup file jurusan
}

// Fungsi untuk menyimpan data ke file external
void simpanKeFile(vector<Mahasiswa> daftarMahasiswa, vector<Jurusan> daftarJurusan)
{
    ofstream fileMahasiswa("mahasiswa.txt"); // Membuka file mahasiswa
    ofstream fileJurusan("jurusan.txt");     // Membuka file jurusan

    // Menyimpan data mahasiswa ke file
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        fileMahasiswa << daftarMahasiswa[i].NIM << " ";
        fileMahasiswa << daftarMahasiswa[i].nama << " ";
        fileMahasiswa << daftarMahasiswa[i].gender << " ";
        fileMahasiswa << daftarMahasiswa[i].tgl_lahir << " ";
        fileMahasiswa << daftarMahasiswa[i].alamat << " ";
        fileMahasiswa << daftarMahasiswa[i].jurusan << " ";
        fileMahasiswa << daftarMahasiswa[i].fakultas << endl;
    }

    // Menyimpan data jurusan ke file
    for (int i = 0; i < daftarJurusan.size(); i++)
    {
        fileJurusan << daftarJurusan[i].nama << " ";
        fileJurusan << daftarJurusan[i].fakultas << endl;
    }

    fileMahasiswa.close(); // Menutup file mahasiswa
    fileJurusan.close();   // Menutup file jurusan
}

int main()
{
    // Inisialisasi daftar mahasiswa dan daftar jurusan
    vector<Mahasiswa> daftarMahasiswa;
    vector<Jurusan> daftarJurusan;
    string sebelum;
    int pilihan;
    bool exit = false;
    bacaDariFile(daftarMahasiswa, daftarJurusan);
    while (!exit)
    {
        // Menampilkan menu
        cout << "==================================================" << endl;
        cout << "        Aplikasi Penerimaan Mahasiswa Baru        " << endl;
        cout << "==================================================" << endl;
        cout << " -- INPUT --" << endl;
        cout << "1. Pendaftaran Mahasiswa Baru" << endl;
        cout << "2. Tambah Jurusan Baru" << endl;
        cout << "3. Pemilihan Jurusan Mahasiswa Baru" << endl;
        cout << " -- EDIT --" << endl;
        cout << "4. Ubah Data Mahasiswa" << endl;
        cout << "5. Ubah Profile Jurusan" << endl;
        cout << " -- VIEW --" << endl;
        cout << "6. Lihat Mahasiswa yang telah terdaftar" << endl;
        cout << "7. Lihat Jurusan" << endl;
        cout << "8. Lihat Jurusan yang dipilih Mahasiswa Baru" << endl;
        cout << " -- DELETE --" << endl;
        cout << "9. Hapus Data Mahasiswa" << endl;
        cout << "10. Hapus Profile Jurusan" << endl;
        cout << "11. Hapus Pilihan Jurusan Mahasiswa" << endl;
        cout << " -- SEARCHING --" << endl;
        cout << "12. Cari Data Mahasiswa" << endl;
        cout << "13. Cari Profile Jurusan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> sebelum;
        // jika x tidak dapat diubah menjadi tipe data numerik, berarti input bukanlah angka
        if (!(stringstream(sebelum) >> pilihan))
        {
            return main();
        }
        stringstream(sebelum) >> pilihan;
        switch (pilihan)
        {
        case 1:
            // Memanggil fungsi pendaftaran mahasiswa baru
            daftarMahasiswaBaru(daftarMahasiswa);
            break;
        case 2:
            // Memanggil fungsi penambahan jurusan baru
            tambahJurusan(daftarJurusan);
            break;
        case 3:
            // Memanggil fungsi pemilihan jurusan oleh mahasiswa
            pilihJurusan(daftarMahasiswa, daftarJurusan);
            break;
        case 4:
            // Memanggil fungsi ubah data mahasiswa
            ubahMahasiswa(daftarMahasiswa);
            break;
        case 5:
            // Memanggil fungsi ubah profile jurusan
            ubahJurusan(daftarJurusan);
            break;
        case 6:
            // Memanggil fungsi menampilkan daftar mahasiswa
            lihatMahasiswa(daftarMahasiswa);
            break;
        case 7:
            // Memanggil fungsi menampilkan daftar jurusan
            lihatJurusan(daftarJurusan);
            break;
        case 8:
            // Memanggil fungsi menampilkan jurusan yang dipilih oleh mahasiswa
            lihatJurusanMhs(daftarMahasiswa);
            break;
        case 9:
            // Memanggil fungsi menghapus data mahasiswa
            hapusMahasiswa(daftarMahasiswa);
            break;
        case 10:
            // Memanggil fungsi menghapus profile jurusan
            hapusJurusan(daftarJurusan);
            break;
        case 11:
            // Memanggil fungsi menghapus pilihan jurusan oleh mahasiswa
            hapusJurusanMhs(daftarMahasiswa);
            break;
        case 12:
            // Memanggil fungsi mencari data mahasiswa
            cariMahasiswa(daftarMahasiswa);
            break;
        case 13:
            // Memanggil fungsi mencari profile jurusan
            cariJurusan(daftarJurusan);
            break;
        case 0:
            simpanKeFile(daftarMahasiswa, daftarJurusan);
            // Keluar dari program
            return 0;
            break;
        default:
            cout << "Pilihan salah!" << endl;
            break;
        }
    }
    return main();
}