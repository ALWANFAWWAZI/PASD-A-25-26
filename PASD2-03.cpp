#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char data[5]; 
    int top;

public:
    Stack() {
        top = -1;
    }
    void push(char n) {
        data[++top] = n;
    }
    void pop() {
        top--;
    }
    char peek() {
        return data[top];
    }
    void cetak() {
        while (top >= 0) {
            char n = peek();
            if (n == 'A') cout << "Nilai A = \"Sangat baik\"" << endl;
            else if (n == 'B') cout << "Nilai B = \"Baik\"" << endl;
            else if (n == 'C') cout << "Nilai C = \"cukup\"" << endl;
            else if (n == 'D') cout << "Nilai D = \"Kurang\"" << endl;
            else if (n == 'E') cout << "Nilai E = \"Gagal\"" << endl;
            pop();
        }
    }
};
int main() {
    Stack s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    cout << "Mencetak apabila Nilai:" << endl;
    s.cetak();
    
cin.get();  
}