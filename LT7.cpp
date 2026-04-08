#include <iostream>
using namespace std;

class Barang{
	public:
	char kodebarang[9];
	char namabarang[30];
	float harga;
};

int main(){
	Barang Toko;
	cout << "Kode Barang                = "; cin >> Toko.kodebarang;
	cout << "Nama Barang                = "; cin >> Toko.namabarang;
	cout << "harga                      = "; cin >> Toko.harga;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      Data Anda " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Kode Barang                = " << Toko.kodebarang << endl;
	cout << "Nama Barang                = " << Toko.namabarang << endl;
	cout << "harga                      = " << Toko.harga << endl;
	cin.get();
}