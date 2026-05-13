#include <iostream>
#include <string>
using namespace std;

struct alwan1 {
    string os;
    alwan1 *next;
};

struct alwan2 {
    alwan1 *first;
    alwan1 *last;
};

void alwan3(alwan2 *Q) {
    Q->first = NULL;
    Q->last = NULL;
}

alwan1* alwan4(string nama) {
    alwan1* node = new alwan1;
    node->os = nama;
    node->next = NULL;
    return node;
}

void tambahBelakang(alwan2 *Q, string nama) {
    alwan1* node = alwan4(nama);
    if (Q->first == NULL) {
        Q->first = Q->last = node;
    } else {
        Q->last->next = node;
        Q->last = node;
    }
}

void tampil(alwan2 Q) {
    alwan1* bantu = Q.first;
    while (bantu != NULL) {
        cout << bantu->os;
        if (bantu->next != NULL) cout << " -> ";
        bantu = bantu->next;
    }
    cout << endl;
}

void sisipSebelum(alwan2 *Q, string target, string baru) {
    alwan1 *baruNode = alwan4(baru);
    if (Q->first == NULL) return;
    if (Q->first->os == target) {
        baruNode->next = Q->first;
        Q->first = baruNode;
        return;
    }
    alwan1 *prev = Q->first;
    while (prev->next != NULL && prev->next->os != target) prev = prev->next;
    if (prev->next != NULL) {
        baruNode->next = prev->next;
        prev->next = baruNode;
    }
}

void sisipSesudah(alwan2 *Q, string target, string baru) {
    alwan1 *temp = Q->first;
    while (temp != NULL && temp->os != target) temp = temp->next;
    if (temp != NULL) {
        alwan1 *baruNode = alwan4(baru);
        baruNode->next = temp->next;
        temp->next = baruNode;
        if (temp == Q->last) Q->last = baruNode;
    }
}

void tambahPalingBawah(alwan2 *Q, string baru) {
    tambahBelakang(Q, baru);
}

int main() {
    alwan2 Q;
    alwan3(&Q);

    tambahBelakang(&Q, "Maemo");
    tambahBelakang(&Q, "Symbian");
    tambahBelakang(&Q, "Mac");
    tambahBelakang(&Q, "Windows");
    tambahBelakang(&Q, "Iphone");

    cout << "Awal: ";
    tampil(Q);

    alwan2 A = Q;

    cout << "a. ";
    sisipSebelum(&A, "Iphone", "Iphone 5");
    tampil(A);

    A = Q;
    cout << "b. ";
    sisipSebelum(&A, "Windows", "Windows Phone");
    tampil(A);

    A = Q;
    cout << "c. ";
    sisipSesudah(&A, "Mac", "SnowLeopard");
    tampil(A);

    A = Q;
    cout << "d. ";
    sisipSesudah(&A, "Symbian", "Symbian Belle");
    tampil(A);

    A = Q;
    cout << "e. ";
    tambahPalingBawah(&A, "Maemo 4");
    tampil(A);

    return 0;
}