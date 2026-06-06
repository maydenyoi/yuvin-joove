   #include <iostream>
   using namespace std;
   
         int main() {
             int n;
             bool prima = true;
             
             cout << "Masukkan Angka : "; cin >> n;
             
             if (n <= 1){
                cout << "Angka harus lebih besar dari 1" << endl;
                }
             for (int i = 2; i * i <= n; i++) {
                 if (n % i == 0) {
                    prima = false;
                    break;
                    }
             }
             if (prima) {
                cout << "Bilangan Prima" << endl;}
             else
                cout << "Bukan Bilangan Prima" << endl;
             
             return 0;
    }               
