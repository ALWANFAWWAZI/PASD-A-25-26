#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
	int A;
	char *AlwanNM, Nama[6]= {'a','A','L','W','A','N'};
	cout << "    Nama AKU	" << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;
	for(A=6; A>0; A--)
	{
		AlwanNM = &Nama[A];
		cout << " " << *AlwanNM << endl;
	}
	cin.get();
}