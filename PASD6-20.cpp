#include <iostream>
using namespace std;

struct MergeSortAscending {
    int arr[9] = {65, 2, 44, 26, 19, 22, 5, 3, 12};

    void merge(int kiri, int tengah, int kanan) {
        int n1 = tengah - kiri + 1;
        int n2 = kanan - tengah;

        int L[50], R[50];

        for (int i = 0; i < n1; i++) L[i] = arr[kiri + i];
        for (int j = 0; j < n2; j++) R[j] = arr[tengah + 1 + j];

        int i = 0, j = 0, k = kiri;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int kiri, int kanan) {
        if (kiri < kanan) {
            int tengah = kiri + (kanan - kiri) / 2;
            mergeSort(kiri, tengah);
            mergeSort(tengah + 1, kanan);
            merge(kiri, tengah, kanan);
        }
    }

    void tampilkan() {
        for (int i = 0; i < 9; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MergeSortAscending obj;

    cout << "Data SEBELUM diurutkan:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    obj.tampilkan();

    obj.mergeSort(0, 8);

    cout << "Data SETELAH diurutkan (Ascending):" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    obj.tampilkan();

    return 0;
} 