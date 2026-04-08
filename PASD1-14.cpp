#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct MataKuliah {
    string namaMK;
    int sks;
    char nilaiHuruf;
    float nilaiAngka;
};

struct Mahasiswa {
    string nama;
    string nim;
    int jumlahMK;
    MataKuliah mk[50];
    int totalSKS;
    float ipk;
};

int main() {
    int jumlahMahasiswa;
	int i ,j;

    cout << "Masukkan Jumlah Mahasiswa: ";
    cin >> jumlahMahasiswa;

    Mahasiswa mhs[jumlahMahasiswa];

    for (i = 0; i < jumlahMahasiswa; i++) {
        cout << "\n--- Data Mahasiswa ke-" << i + 1 << " ---" << endl;
        
        cout << "Nama Mahasiswa (Gunakan _ untuk spasi): ";
        cin >> mhs[i].nama; 
        
        cout << "Nomor Induk Mahasiswa (NIM): ";
        cin >> mhs[i].nim;
        
        cout << "Banyaknya Mata Kuliah: ";
        cin >> mhs[i].jumlahMK;

        mhs[i].totalSKS = 0;
        float totalBobot = 0;

        for (j = 0; j < mhs[i].jumlahMK; j++) {
            cout << "\n  Mata Kuliah ke-" << j + 1 << endl;
            cout << "  Nama Mata Kuliah (Gunakan _ untuk spasi): ";
            cin >> mhs[i].mk[j].namaMK;
            
            cout << "  SKS: ";
            cin >> mhs[i].mk[j].sks;
            
            cout << "  Nilai Huruf (A/B/C/D/E): ";
            cin >> mhs[i].mk[j].nilaiHuruf;

            if (mhs[i].mk[j].nilaiHuruf == 'A' || mhs[i].mk[j].nilaiHuruf == 'a') mhs[i].mk[j].nilaiAngka = 4.0;
            else if (mhs[i].mk[j].nilaiHuruf == 'B' || mhs[i].mk[j].nilaiHuruf == 'b') mhs[i].mk[j].nilaiAngka = 3.0;
            else if (mhs[i].mk[j].nilaiHuruf == 'C' || mhs[i].mk[j].nilaiHuruf == 'c') mhs[i].mk[j].nilaiAngka = 2.0;
            else if (mhs[i].mk[j].nilaiHuruf == 'D' || mhs[i].mk[j].nilaiHuruf == 'd') mhs[i].mk[j].nilaiAngka = 1.0;
            else mhs[i].mk[j].nilaiAngka = 0.0;

            mhs[i].totalSKS += mhs[i].mk[j].sks;
            totalBobot += (mhs[i].mk[j].nilaiAngka * mhs[i].mk[j].sks);
        }

        if (mhs[i].totalSKS > 0) 
            mhs[i].ipk = totalBobot / mhs[i].totalSKS;
        else 
            mhs[i].ipk = 0;
    }

    for (i = 0; i < jumlahMahasiswa; i++) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                     KARTU HASIL STUDI [KHS]                     " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Nama Mahasiswa             : " << mhs[i].nama << endl;
        cout << "Nomor Induk Mahasiswa      : " << mhs[i].nim << endl;
        cout << "Mata Kuliah Yang Ditempuh  : " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << left << setw(4) << "No" 
             << setw(25) << "Mata Kuliah" 
             << setw(6) << "SKS" 
             << setw(15) << "Nilai Huruf" 
             << "Nilai Angka" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        for (j = 0; j < mhs[i].jumlahMK; j++) {
            cout << left << setw(4) << j + 1 
                 << setw(25) << mhs[i].mk[j].namaMK 
                 << setw(6) << mhs[i].mk[j].sks 
                 << setw(15) << mhs[i].mk[j].nilaiHuruf 
                 << fixed << setprecision(1) << mhs[i].mk[j].nilaiAngka << endl;
        }

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Jumlah Mata Kuliah Yang Diambil = " << mhs[i].jumlahMK << endl;
        cout << "Jumlah SKS                      = " << mhs[i].totalSKS << endl;
        cout << "Indeks Prestasi Komulatif [IPK] = " << fixed << setprecision(2) << mhs[i].ipk << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    cin.get();
}