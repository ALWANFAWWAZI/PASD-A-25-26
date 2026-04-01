#include <iostream> 
#include <string>
using namespace std;

int main()	{
struct ALWANENDUT	{
	string NamaAlwan;
	string TempatAlwan;
	int TahunTerbitAlwan;
	string HargaBuku;	};
	
ALWANENDUT gd_;
gd_.NamaAlwan = "Pelangi";
gd_.TempatAlwan = "bogor";
gd_.TahunTerbitAlwan = 2007;
gd_.HargaBuku = "42rp";
cout<<endl;
cout<<endl;
cout<< "Judul Buku           	= " << gd_.NamaAlwan << endl;
cout<< "Pengarang 	    	= " << gd_.TempatAlwan << endl;
cout<< "TahunTerbit       	= " << gd_.TahunTerbitAlwan << endl;
cout<< "harga            	= " << gd_.HargaBuku << endl;

cin.get();	}
