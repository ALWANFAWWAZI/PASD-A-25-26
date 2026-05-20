#include <iostream>
#include <string>
using namespace std;

struct Data {
    string nama;
    int umur;
};

struct Node {
    Data info;
    Node* next;
};

struct Stack {
    Node* top;
};

void buatStackKosong(Stack *s) {
    s->top = NULL;
}

bool isKosong(Stack s) {
    return s.top == NULL;
}

void push(string nama, int umur, Stack *s) {
    Node* baru = new Node;
    baru->info.nama = nama;
    baru->info.umur = umur;
    baru->next = s->top;
    s->top = baru;
}

void tampil(Stack s) {
    if (isKosong(s)) {
        cout << "Stack kosong\n";
        return;
    }

    Node* bantu = s.top;
    while (bantu != NULL) {
        cout << bantu->info.nama << " --" << bantu->info.umur << endl;
        bantu = bantu->next;
    }
}

void hapusTiara(Stack *s) {
    Node *bantu = s->top, *prev = NULL;

    while (bantu != NULL) {
        if (bantu->info.nama == "Tiara" && bantu->info.umur == 63) {
            if (prev == NULL) {
                s->top = bantu->next;
            } else {
                prev->next = bantu->next;
            }
            delete bantu;
            return;
        }
        prev = bantu;
        bantu = bantu->next;
    }
}

int main() {
    Stack S;
    buatStackKosong(&S);

    push("Candra", 22, &S);
    push("Cinthya", 66, &S);
    push("Ilham", 28, &S);
    push("Tiara", 63, &S);
    push("Fanny", 10, &S);

    cout << "Sebelum penghapusan:\n";
    tampil(S);

    hapusTiara(&S);

    cout << "\nSetelah penghapusan Tiara --63:\n";
    tampil(S);

    return 0;
} 
