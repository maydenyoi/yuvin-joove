#include <iostream>
using namespace std;

int main () {
string jurusan, nim;
nim = "123240001";
switch(nim[2]) {
case '1' : jurusan = "Teknik Kimia"; break;
case '2' : jurusan = "Teknik Industri"; break;
case '3' : jurusan = "Informatika"; break;
case '4' : jurusan = "Sistem Informasi"; break;
default : cout << "Coba periksa lagi!";
}
cout << "Jurusan anda adalah : " << jurusan;
return 0;
}
