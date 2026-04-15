#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void BUAT_SIMPUL (int X);
void AWAL();
void CETAK();
void INSERTKANAN();

struct Node {
	int INFO;
	struct Node *LINK; };
typedef struct Node Simpul;
Simpul *P, *FIRST, *LAST, *Q; 
int x;
int main() {
	int A[6] = {101,102,103,104,105};
	int I;
	FIRST = NULL;
	I = 0;
	x = A[I];
	BUAT_SIMPUL(x);
	AWAL();
	for (I=1; I<=4; I++)
{
	x=A[I];
	BUAT_SIMPUL(x);
	INSERTKANAN(); }
cout<<"Daftar Nomor Antrian Saat Ini         : ";
CETAK();
x=999;
BUAT_SIMPUL(x);
INSERTKANAN();
cout << endl;
cout<<"Daftar ANtrian Setelah Pelanggan Baru : ";
CETAK();
cout << endl;
cin.get(); }

void BUAT_SIMPUL (int X)
{
	P = (Simpul *) malloc(sizeof(Simpul));
	if(P != NULL){
	P -> INFO = x;}
	else {		
	cout<<"Pembuatan Simpul Tidak Berhasil"<<endl;
	cin.get();
	exit(1); }}


void AWAL()
{
	FIRST = P;
	LAST = P;
	P -> LINK = NULL; }

void INSERTKANAN()
{
	LAST -> LINK = P;
	LAST = P;
	P -> LINK = NULL; }

void CETAK()
{
	int X;
	Q = FIRST;
	while(Q != NULL){
		X = Q -> INFO;
		cout<<" "<< X;
		Q = Q -> LINK; } }