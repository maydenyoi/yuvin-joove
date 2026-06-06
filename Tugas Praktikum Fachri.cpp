#include <iostream>
#include <iomanip>
using namespace std;

      int main () {
          float celsius, fahrenheit, kelvin, reamur;
          
          cout << setfill('=') << setw(21) << " " << endl;
          cout << "PROGRAM KONVERSI SUHU" << endl;
          cout << setfill ('=') << setw(21) << " " << endl;
          cout << endl;
          
          cout << "Masukkan suhu dalam Celsius (C): "; cin >> celsius;
          cout << endl;
          
          cout << setfill ('-') << setw(35) << " " << endl;
          fahrenheit = (9.0 / 5.0 * celsius) + 32;
          kelvin     = 273 + celsius;
          reamur     = 4.0 / 5.0 * celsius;
          cout << "Hasil Konversi: " << endl;
          cout << "Suhu dalam Celsius    : " << celsius    << " C"  << endl;                           
          cout << "Suhu dalam Fahrenheit : " << fahrenheit << " F"  << endl;
          cout << "Suhu dalam Kelvin     : " << kelvin     << " K"  << endl;
          cout << "Suhu dalam Reamur     : " << reamur     << " Re" << endl;
          cout << setfill ('-') << setw(35) << " " << endl;
          
           return 0; 

}
