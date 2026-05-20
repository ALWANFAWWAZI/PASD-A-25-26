#include <iostream>
using namespace std;

class CAlwan {
public:
    int data[10];
    int n;
    CAlwan() {
        int temp[10] = {64, 34, 25, 12, 22, 11, 90, 55, 41, 78};
        n = 10;
        for(int i=0;i<n;i++) data[i]=temp[i];
    }
    void Alwan() {
        for(int i=0;i<n;i++) cout<<data[i]<<" ";
        cout<<endl;
    }
    void tukar(int a,int b) {
        int t = data[b];
        data[b] = data[a];
        data[a] = t;
    }
    void SAlwan() {
        for(int i=0;i<n-1;i++) {
            for(int j=n-1;j>i;j--) {
                if(data[j] < data[j-1]) tukar(j,j-1);
            }
        }
    }
};

int main() {
    cout<<"* Program Ascending *"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    CAlwan ALW;
    cout<<"Sebelum pengurutan: ";
    ALW.Alwan();
    ALW.SAlwan();
    cout<<"Setelah pengurutan: ";
    ALW.Alwan();
    return 0;
}
