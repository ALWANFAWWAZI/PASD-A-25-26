#include <iostream>
using namespace std;

struct AlwanStruk {
    int data[10];
    int n;
};

void Alwan(const AlwanStruk &d) {
    for(int i=0;i<d.n;i++) cout<<d.data[i]<<" ";
    cout<<endl;
}

void tukar(AlwanStruk &d,int a,int b) {
    int t = d.data[b];
    d.data[b] = d.data[a];
    d.data[a] = t;
}

void SAlwan(AlwanStruk &d) {
    for(int i=0;i<d.n-1;i++) {
        for(int j=d.n-1;j>i;j--) {
            if(d.data[j] < d.data[j-1]) tukar((AlwanStruk&)d,j,j-1);
        }
    }
}

int main() {
    cout<<"* Program Ascending  *"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    AlwanStruk d;
    int temp[10] = {64, 34, 25, 12, 22, 11, 90, 55, 41, 78};
    d.n = 10;
    for(int i=0;i<d.n;i++) d.data[i]=temp[i];

    cout<<"Sebelum pengurutan: ";
    Alwan(d);
    SAlwan(d);
    cout<<"Setelah pengurutan: ";
    Alwan(d);
    return 0;
}
