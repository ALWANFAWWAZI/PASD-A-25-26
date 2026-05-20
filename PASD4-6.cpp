#include <iostream>
#include <string>
using namespace std;

string antrian[20];
int n = 0;

void reset_antrian() {
    string awal[] = {"Maemo", "Symbian", "Mac", "Windows", "Iphone"};
    for(int i=0; i<5; i++) antrian[i] = awal[i];
    n = 5;
}

void display(string label) {
    cout << label << ": ";
    for(int i=0; i<n; i++) cout << antrian[i] << (i<n-1 ? " -> " : "");
    cout << endl;
}

void hapus_elemen(string target) {
    int pos = -1;
    for(int i=0; i<n; i++) if(antrian[i] == target) pos = i;
    if(pos != -1) {
        for(int i=pos; i<n-1; i++) antrian[i] = antrian[i+1];
        n--;
    }
}

void tambah_bawah(string baru) {
    antrian[n++] = baru;
}

void tambah_setelah(string acuan, string baru) {
    int pos = -1;
    for(int i=0; i<n; i++) if(antrian[i] == acuan) pos = i;
    if(pos != -1) {
        for(int i=n; i>pos+1; i--) antrian[i] = antrian[i-1];
        antrian[pos+1] = baru;
        n++;
    }
}

int main() {
    reset_antrian();
    hapus_elemen("Mac");
    tambah_bawah("Maemo 4");
    display("a");

    reset_antrian();
    hapus_elemen("Iphone");
    tambah_setelah("Windows", "Windows Mobile");
    display("b");

    reset_antrian();
    hapus_elemen("Maemo");
    tambah_setelah("Symbian", "Java Midlet");
    display("c");

    reset_antrian();
    hapus_elemen("Maemo");
    tambah_setelah("Mac", "Lion OS X");
    display("d");
	
    reset_antrian();
    hapus_elemen("Maemo");
    tambah_setelah("Iphone", "Android");
    display("e");

    return 0;
} 
