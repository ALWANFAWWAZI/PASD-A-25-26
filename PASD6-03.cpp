#include <iostream>
#include <iomanip>
using namespace std;

class QuickSortDescending {
private:
    int data[9] = {65, 2, 44, 26, 19, 22, 5, 3, 12};

    void q_sort(int kiri, int kanan) {
        int i = kiri, j = kanan;
        int pivot = data[(kiri + kanan) / 2];

        while (i <= j) {
            while (data[i] > pivot) i++;
            while (data[j] < pivot) j--;
            if (i <= j) {
                swap(data[i], data[j]);
                i++;
                j--;
            }
        }

        if (kiri < j) q_sort(kiri, j);
        if (i < kanan) q_sort(i, kanan);
    }

public:
    void tampilkan() {
        for (int i = 0; i < 9; i++) {
            cout << setw(4) << data[i];
        }
        cout << endl;
    }

    void proses() {
        cout << "Data SEBELUM diurutkan:" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        tampilkan();

        q_sort(0, 8);

        cout << "\nData SETELAH diurutkan (Descending):" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        tampilkan();
    }
};

int main() {
    QuickSortDescending obj;
    obj.proses();
    return 0;
}