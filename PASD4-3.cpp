#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct {
    int first;
    int last;
    NilaiMK Dat[10];
} queueAlwan;

void AlwanQUkosong(queueAlwan *Q) {
    (*Q).first = -1;
    (*Q).last = -1;
}

bool AlwanKosong(queueAlwan Q) { return (Q.first == -1); }
bool AlwanPenuh(queueAlwan Q) { return (Q.last == 9); }

void ADD(string npm, string nama_mhs, double nilai, queueAlwan *Q) {
    if (AlwanKosong(*Q)) {
        (*Q).first = 0; (*Q).last = 0;
        (*Q).Dat[0] = {npm, nama_mhs, nilai};
    } else if (!AlwanPenuh(*Q)) {
        (*Q).last++;
        (*Q).Dat[(*Q).last] = {npm, nama_mhs, nilai};
    } else cout << "queue PENUH" << endl;
}

void CetakqueueAlwan(queueAlwan Q) {
    if (!AlwanKosong(Q)) {
        for (int i = Q.first; i <= Q.last; i++) {
            cout << "NPM: " << Q.Dat[i].npm << ", Nama: " << Q.Dat[i].nama_mhs 
                 << ", Nilai: " << Q.Dat[i].nilai << endl;
        }
    } else cout << "queue Kosong" << endl;
}

int main() {
    queueAlwan Q;
    AlwanQUkosong(&Q);
    ADD("111", "Andi", 90.0, &Q);
    ADD("222", "Budi", 85.0, &Q);
    CetakqueueAlwan(Q);
    return 0;
}