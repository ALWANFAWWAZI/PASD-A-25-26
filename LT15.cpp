#include <iostream>
using namespace std;

int Search01(int A[], int, int);

int main() {
    const int JmlElemenArray = 11;
    int tika[JmlElemenArray] = {20225,20235,20345,20123,20654,20234,21234,23198,24321,24234,29756};

    int pilihan;
    int SearchElemen;
    int flag;

    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~        PROGRAM SEQUENTIAL SEARCH     ~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Pencarian Nomor Kendaraan :" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Input Data kendaraan" << endl;
        cout << "2. Cari Kendaraan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Input data kendaraan:" << endl;
            for (int count = 0; count < JmlElemenArray; count++) {
                cout << "Masukkan data kendaraan ke-" << count << " : ";
                cin >> tika[count];
            }

            cout << "Data kendaraan berhasil diinput." << endl;
            cout << endl;
        }
        else if (pilihan == 2) {
            cout << "Data kendaraan yang tersimpan:" << endl;
            for (int count = 0; count < JmlElemenArray; count++) {
                cout << "CAR [" << count << "] --> " << tika[count] << endl;
            }

            cout << "Masukkan nomor kendaraan yang akan ANDA cari? ";
            cin >> SearchElemen;

            flag = Search01(tika, JmlElemenArray, SearchElemen);

            if (flag != -1)
                cout << "Nomor kendaraan yang dicari ditemukan pada posisi: Data[" << flag << "]" << endl;
            else
                cout << "Nomor kendaraan yang ANDA cari tidak ditemukan" << endl;

            cout << endl;
        }
        else if (pilihan == 3) {
            cout << "Program selesai." << endl;
        }
        else {
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 3);

    return 0;
}

int Search01(int tika[], int JmlElemenArray, int Elemen) {
    int flag = -1;
    for (int count = 0; count < JmlElemenArray; count++) {
        if (Elemen == tika[count]) {
            flag = count;
            break;
        }
    }
    return flag;
}