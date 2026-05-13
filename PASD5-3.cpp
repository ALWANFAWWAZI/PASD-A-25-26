#include <iostream>
#include <string>
using namespace std;

struct NilaiMK {
    string npm;
    string nama_mhs;
    double nilai;
};

class elm {
public:
    NilaiMK Kontainer;
    elm *next;
    elm() {
        next = NULL;
    }
};

class queue {
public:
    elm *first;
    elm *last;

    queue() {
        first = NULL;
        last = NULL;
    }

    void buatQkosong() {
        first = NULL;
        last = NULL;
    }

    bool isKosong() {
        return first == NULL;
    }

    int jmlelemen() {
        int hasil = 0;
        elm *bantu = first;
        while (bantu != NULL) {
            hasil++;
            bantu = bantu->next;
        }
        return hasil;
    }

    void add(string npm, string nama_mhs, double nilai) {
        elm *info = new elm;
        info->Kontainer.npm = npm;
        info->Kontainer.nama_mhs = nama_mhs;
        info->Kontainer.nilai = nilai;
        info->next = NULL;

        if (first == NULL) {
            first = info;
        } else {
            last->next = info;
        }
        last = info;
    }

    void del() {
        if (first != NULL) {
            elm *hapus = first;
            if (jmlelemen() == 1) {
                first = NULL;
                last = NULL;
            } else {
                first = first->next;
                hapus->next = NULL;
            }
            delete hapus;
        }
    }

    void CetakQueue() {
        if (first != NULL) {
            cout << "MENAMPILKAN QUEUE" << endl;
            elm *bantu = first;
            int i = 1;
            while (bantu != NULL) {
                cout << "-------------------------------" << endl;
                cout << "Elemen ke            : " << i << endl;
                cout << "Nomor Pokok Mahasiswa : " << bantu->Kontainer.npm << endl;
                cout << "Nama Mahasiswa        : " << bantu->Kontainer.nama_mhs << endl;
                cout << "Nilai Mahasiswa       : " << bantu->Kontainer.nilai << endl;
                bantu = bantu->next;
                i++;
            }
            cout << "-------------------------------" << endl;
        } else {
            cout << "Queue Kosong" << endl;
        }
    }
};

int main() {
    queue Q;
    Q.buatQkosong();

    int n;
    string npm, nama;
    double nilai;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << endl;
        cout << "NPM  : ";
        cin >> npm;
        cout << "Nama : ";
        cin >> nama;
        cout << "Nilai: ";
        cin >> nilai;
        Q.add(npm, nama, nilai);
    }

    cout << endl;
    Q.CetakQueue();

    return 0;
}