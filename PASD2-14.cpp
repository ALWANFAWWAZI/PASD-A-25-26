#include <iostream>
using namespace std;

class Stack {
private:
    string data[20];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string x) {
        top++;
        data[top] = x;
    }

    void tampil() {
        int i = 0;
        while (i <= top) {
            cout << data[i] << endl;
            i++;
        }
    }
};

int main() {
    Stack os;

    os.push("Iphone");
    os.push("Windows");
    os.push("Mac");
    os.push("Symbian");
    os.push("Maemo");
	os.push("~~~~Mengubah nama~~~~");

    // a. Menambahkan "Iphone 5" di atas "Iphone"
    os.push("Iphone 5");

    // b. Menambahkan "Windows Phone" di atas "Windows"
    os.push("Windows Phone");

    // c. Menambahkan "SnowLeopard" setelah "Mac"
    os.push("SnowLeopard");

    // d. Menambahkan "Symbian Belle" setelah "Symbian"
    os.push("Symbian Belle");

    // e. Menambahkan "Maemo 4" paling bawah tanpa menghilangkan data lain
    os.push("Maemo 4");

    cout << "Isi tumpukan OS:" << endl;
    os.tampil();

    cin.get();
}