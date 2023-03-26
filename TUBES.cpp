// Fungsi untuk mengambil data dari file external
void bacaDariFile(vector<Mahasiswa> &daftarMahasiswa, vector<Jurusan> &daftarJurusan)
{
    ifstream fileMahasiswa("mahasiswa.csv"); // Membuka file mahasiswa
    ifstream fileJurusan("jurusan.csv");     // Membuka file jurusan

    string line;

    // Membaca data mahasiswa dari file
    while (getline(fileMahasiswa, line))
    {
        Mahasiswa mhs;
        stringstream ss(line);

        getline(ss, mhs.NIM, ',');
        getline(ss, mhs.nama, ',');
        getline(ss, mhs.jurusan, ',');
        getline(ss, mhs.tgl_lahir, ',');

        daftarMahasiswa.push_back(mhs);
    }

    // Membaca data jurusan dari file
    while (getline(fileJurusan, line))
    {
        Jurusan jur;
        stringstream ss(line);

        getline(ss, jur.nama, ',');
        getline(ss, jur.fakultas, ',');

        daftarJurusan.push_back(jur);
    }

    fileMahasiswa.close(); // Menutup file mahasiswa
    fileJurusan.close();   // Menutup file jurusan
}

// Fungsi untuk menyimpan data ke file external
void simpanKeFile(vector<Mahasiswa> daftarMahasiswa, vector<Jurusan> daftarJurusan)
{
    ofstream fileMahasiswa("mahasiswa.csv"); // Membuka file mahasiswa
    ofstream fileJurusan("jurusan.csv");     // Membuka file jurusan

    // Menyimpan data mahasiswa ke file
    for (int i = 0; i < daftarMahasiswa.size(); i++)
    {
        fileMahasiswa << daftarMahasiswa[i].NIM << ",";
        fileMahasiswa << daftarMahasiswa[i].nama << ",";
        fileMahasiswa << daftarMahasiswa[i].jurusan << ",";
        fileMahasiswa << aftarMahasiswa[i].tgl_lahir << endl;
    }
    // Menyimpan data jurusan ke file
    for (int i = 0; i < daftarJurusan.size(); i++)
    {
        fileJurusan << daftarJurusan[i].nama << ",";
        fileJurusan << daftarJurusan[i].fakultas << endl;
    }

    fileMahasiswa.close(); // Menutup file mahasiswa
    fileJurusan.close();   // Menutup file jurusan
}