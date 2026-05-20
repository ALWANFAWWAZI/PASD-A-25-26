#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct elm *alamatelm;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelm next;
} elemen;

typedef struct {
    elemen *first;
    elemen *last;
} Queue;

void buatQUkosong(Queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isKosong(Queue Q) {
    bool hasil = false;

    if(Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

int jmlElemen(Queue Q) {
    int hasil = 0;

    if(Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;

        while(bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu -> next;
        }
    }
    return hasil;
}

void add(string npm, string nama_mhs, double nilai, Queue *Q) {
    elemen *info;
    info = new elemen;
    info -> Kontainer.npm = npm;
    info -> Kontainer.nama_mhs = nama_mhs;
    info -> Kontainer.nilai = nilai;
    info -> next = NULL;

    if((*Q).first == NULL) {
        (*Q).first = info;
    }
    else {
        (*Q).last -> next = info;
    }
    (*Q).last = info;
    info = NULL;
}

void del(Queue *Q) {
    if((*Q).first != NULL) {
        elemen *hapus = (*Q).first;

        if(jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else {
            (*Q).first = (*Q).first -> next;
            hapus -> next = NULL;
        }
        delete hapus;
    }
}

void CetakQueue(Queue Q)
{
    if(Q.first != NULL)
    {
        cout << " MENAMPILKAN QUEUE " << endl;
        elemen *bantu = Q.first;
        int i = 1;
        while(bantu != NULL)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke           : " << i << endl;
            cout << "Kode Barang         : " << bantu -> Kontainer.npm << endl;
            cout << "Nama Barang         : " << bantu -> Kontainer.nama_mhs << endl;
            cout << "Jumlah stok         : " << bantu -> Kontainer.nilai << endl;
        bantu = bantu -> next;
        i = i + 1;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    else
    {
        cout << "Queue Kosong " << endl;
    }
}

int main() {
    Queue Q;
    buatQUkosong(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    add("45232112", "Bembeng", 88, &Q);
    add("45232107", "Taro", 78, &Q);
    add("45232108", "Kukis", 98, &Q);
    add("45232109", "Coklat", 68, &Q);
    add("45232105", "Vanilla	", 78, &Q);
    CetakQueue(Q);
    cout << "=====================" << endl;
    cout << endl;
    cout << endl;
    del(&Q);
	del(&Q);
    CetakQueue(Q);
    cout << "=====================" << endl;
    return 0;
}