   #include <iostream>
   using namespace std;
   
         int main() {
             int angka;
             
             cout << "Masukkan Angka (1-7) : "; cin >> angka;
             
             switch (angka){
                    case 1: cout << "Hari Senin"  3<< endl; break;
                    case 2: cout << "Hari Selasa" << endl; break;
                    case 3: cout << "Hari Rabu"   << endl; break;
                    case 4: cout << "Hari Kamis"  << endl; break;
                    case 5: cout << "Hari Jumat"  << endl; break;
                    case 6: cout << "Hari Sabtu"  << endl; break;
                    case 7: cout << "Hari Minggu" << endl; break;
              default: cout << "Angka yang dimasukkan tidak sesuai range" << endl; break;
              }
         return 0;
   }       
                    
