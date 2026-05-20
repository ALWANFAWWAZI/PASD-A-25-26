#include <iostream>
#include <string>
using namespace std;

struct Node {
    string info;
    Node* next;
};

struct Stack {
    Node* top;
};

void buatKosong(Stack *s) {
    s->top = NULL;
}

void pushDepan(string x, Stack *s) {
    Node* baru = new Node;
    baru->info = x;
    baru->next = s->top;
    s->top = baru;
}

void tampil(Stack s) {
    Node* bantu = s.top;
    while (bantu != NULL) {
        cout << bantu->info << endl;
        bantu = bantu->next;
    }
}

Node* cari(string x, Stack s) {
    Node* bantu = s.top;
    while (bantu != NULL) {
        if (bantu->info == x) return bantu;
        bantu = bantu->next;
    }
    return NULL;
}

void sisipSetelah(string setelah, string dataBaru, Stack *s) {
    Node* p = cari(setelah, *s);
    if (p != NULL) {
        Node* baru = new Node;
        baru->info = dataBaru;
        baru->next = p->next;
        p->next = baru;
    }
}

void tambahPalingBawah(string dataBaru, Stack *s) {
    Node* baru = new Node;
    baru->info = dataBaru;
    baru->next = NULL;

    if (s->top == NULL) {
        s->top = baru;
        return;
    }

    Node* bantu = s->top;
    while (bantu->next != NULL) {
        bantu = bantu->next;
    }
    bantu->next = baru;
}

int main() {
    Stack S;
    buatKosong(&S);

    pushDepan("Maemo", &S);
    pushDepan("Symbian", &S);
    pushDepan("Mac", &S);
    pushDepan("Windows", &S);
    pushDepan("Iphone", &S);

    sisipSetelah("Iphone", "Iphone 5", &S);
    sisipSetelah("Windows", "Windows Phone", &S);
    sisipSetelah("Mac", "SnowLeopard", &S);
    sisipSetelah("Symbian", "Symbian Belle", &S);
    tambahPalingBawah("Maemo 4", &S);

    tampil(S);
    return 0;
} 
