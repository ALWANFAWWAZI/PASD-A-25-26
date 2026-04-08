#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct pelanggan_toko {
    string nama[7], alamat[7], kelamin[7], telp[7];
    int umur[7];
};

int main() {
    pelanggan_toko data;
    
    data.nama[0] = "Budi Santoso"; data.alamat[0] = "Jl. Merdeka 1"; data.kelamin[0] = "Laki-laki"; data.telp[0] = "081234567890"; data.umur[0] = 25;
    data.nama[1] = "Siti Aminah"; data.alamat[1] = "Jl. Sudirman 10"; data.kelamin[1] = "Perempuan"; data.telp[1] = "081298765432"; data.umur[1] = 30;
    data.nama[2] = "Ahmad Fauzi"; data.alamat[2] = "Jl. Gatot Subroto 5"; data.kelamin[2] = "Laki-laki"; data.telp[2] = "081345678901"; data.umur[2] = 28;
    data.nama[3] = "Rina Kartika"; data.alamat[3] = "Jl. Thamrin 20"; data.kelamin[3] = "Perempuan"; data.telp[3] = "081456789012"; data.umur[3] = 22;
    data.nama[4] = "Eko Prasetyo"; data.alamat[4] = "Jl. Palmerah 15"; data.kelamin[4] = "Laki-laki"; data.telp[4] = "081567890123"; data.umur[4] = 35;
    data.nama[5] = "Dewi Sartika"; data.alamat[5] = "Jl. Kebayoran 8"; data.kelamin[5] = "Perempuan"; data.telp[5] = "081678901234"; data.umur[5] = 27;
    data.nama[6] = "Joko Widodo"; data.alamat[6] = "Jl. Suryo 3"; data.kelamin[6] = "Laki-laki"; data.telp[6] = "081789012345"; data.umur[6] = 32;
    
    cout << "=======================================================" << endl;
    cout << "             DATA PELANGGAN TOKO                      " << endl;
    cout << "=======================================================" << endl;
    cout << "| Nama          | Alamat              | Umur | Kelamin    | Telp         |" << endl;
    cout << "=======================================================" << endl;
    
    for(int i = 0; i < 7; i++) {
        cout << "| " << left << setw(14) << data.nama[i] 
             << "| " << left << setw(20) << data.alamat[i] 
             << "| " << left << setw(5) << data.umur[i] 
             << "| " << left << setw(11) << data.kelamin[i] 
             << "| " << left << setw(10) << data.telp[i] << " |" << endl;
    }
    
    cout << "=======================================================" << endl;
    cout << endl;
    
    cin.get();
}