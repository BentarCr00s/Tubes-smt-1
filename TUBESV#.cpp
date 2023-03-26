#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Struktur data untuk menyimpan data mahasiswa
struct Mahasiswa
{
    string nama;
    string jurusan;
    int angkatan;
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
    cout << "Masukkan nama mahasiswa: ";
    cin >> mhs.nama;
    cout << "Masukkan jurusan mahasiswa: ";
    cin >> mhs.jurusan;
    cout << "Masukkan angkatan mahasiswa: ";
    cin >> mhs.angkatan;

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
            cin >> daftarMahasiswa[i].nama;
            cout << "Masukkan jurusan baru mahasiswa: ";
            cin >> daftarMahasiswa[i].jurusan;
            cout << "Masukkan angkatan baru mahasiswa: ";
            cin >> daftarMahasiswa[i].angkatan;
        }
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
            // Menghapus mahasiswa dari daftar mahasiswa
            daftarMahasiswa.erase(daftarMahasiswa.begin() + i);
            break;
        }
    }
}

// Fungsi untuk menyimpan data mahasiswa ke file external
void simpanDataMahasiswa(vector<Mahasiswa> daftarMahasiswa)
{
    // Membuka file external untuk menulis
    ofstream fileMahasiswa("daftar_mahasiswa.txt");

    // Menuliskan data mahasiswa ke file external
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        fileMahasiswa << daftarMahasiswa[i].nama << endl;
        fileMahasiswa << daftarMahasiswa[i].jurusan << endl;
        fileMahasiswa << daftarMahasiswa[i].angkatan << endl;
    }

    // Menutup file external
    fileMahasiswa.close();
}
// Fungsi untuk mengambil data mahasiswa dari file external
void ambilDataMahasiswa(vector<Mahasiswa> &daftarMahasiswa)
{
    // Membuka file external untuk membaca
    ifstream fileMahasiswa("daftar_mahasiswa.txt");

    // Membaca data mahasiswa dari file external
    while (fileMahasiswa.good())
    {
        Mahasiswa mhs;
        fileMahasiswa >> mhs.nama;
        fileMahasiswa >> mhs.jurusan;
        fileMahasiswa >> mhs.angkatan;

        // Menambahkan mahasiswa ke daftar mahasiswa
        daftarMahasiswa.push_back(mhs);
    }

    // Menutup file external
    fileMahasiswa.close();
}

int main()
{
    // Daftar mahasiswa dan jurusan
    vector<Mahasiswa> daftarMahasiswa;
    vector<Jurusan> daftarJurusan;

    // Mengambil data mahasiswa dari file external
    ambilDataMahasiswa(daftarMahasiswa);

    // Menampilkan menu
    int pilihan;
    do
    {
        cout << "1. Daftar mahasiswa baru" << endl;
        cout << "2. Tambah jurusan" << endl;
        cout << "3. Pilih jurusan oleh mahasiswa baru" << endl;
        cout << "4. Ubah data mahasiswa" << endl;
        cout << "5. Hapus data mahasiswa" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            // Mendaftarkan mahasiswa baru
            daftarMahasiswaBaru(daftarMahasiswa);
        }
        else if (pilihan == 2)
        { // Menambahkan jurusan baru
            tambahJurusan(daftarJurusan);
        }
        else if (pilihan == 3)
        {
            // Memilih jurusan oleh mahasiswa baru
            pilihJurusan(daftarMahasiswa, daftarJurusan);
        }
        else if (pilihan == 4)
        {
            // Mengubah data mahasiswa
            ubahMahasiswa(daftarMahasiswa);
        }
        else if (pilihan == 5)
        {
            // Menghapus data mahasiswa
            hapusMahasiswa(daftarMahasiswa);
        }
        else if (pilihan == 6)
        {
            // Menyimpan data mahasiswa ke file external
            simpanDataMahasiswa(daftarMahasiswa);
            cout << "Terima kasih telah menggunakan program ini!" << endl;
        }
    } while (pilihan != 6);

    return 0;
}