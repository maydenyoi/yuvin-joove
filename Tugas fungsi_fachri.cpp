#include <iostream>
#include <vector>
using namespace std;

double hitungRatarata(int n);
void cekLulus(double nilai);
char getIndeks(double nilai);

int main() {
    int pilih;
    char ulang;
    
    do {
	  cout << "1. Hitung Rata-rata dari 'N' Nilai." << endl;
	  cout << "2. Cek Status Kelulusan." << endl;
	  cout << "3. Menampilkan Indeks Nilai (A/B/C/D/E)." << endl;
	  cout << "4. Keluar." << endl;
	  cout << "Masukkan Pilihan : ";cin >> pilih;
	  
	  switch(pilih) {
		    case 1 : {
				 int n;
                 cout << "Berapa banyak data nilai yang ingin anda masukkan? "; cin >> n;
                 
                 if(n<= 0) {
					 cout << "Jumlah Data Harus Lebih Dari 0!" << endl;
				 } else {
		             double hasil = hitungRatarata(n);
		             cout << "rata-rata dari " << n << " nilai adalah " << hasil <<endl;
			 }
		         break;
			 }
		    case 2 : {
		         double nilai;
		         cout << "Syarat Nilai Kelulusan (KKM) adalah 70" << endl;
		         cout << "Masukkan Nilai Akhir (0-100) : "; cin >> nilai;
		         cekLulus(nilai);
		         break;
			 }
		    case 3 : {
		         double nilai;
		         cout << "Masukkan Nilai Akhir (0-100) : "; cin >> nilai;
		         
		         char indeks = getIndeks(nilai);
		         cout << "Indeks Nilai Anda Adalah: " << indeks << endl;
		         break;
			 }
		    case 4 : {
		        cout << "Terimakasih Telah Menggunakan Sistem." << endl;
		        break;
			}
		    default :{
			    cout << "Input Tidak Valid" << endl;
			}
		}
		cout << "Apakah Anda Ingin Memilih Lagi? (y/n) : "; cin >> ulang;
	} while ((ulang == 'y' || ulang == 'Y') && (pilih != 4));
}

double hitungRatarata(int n) {
   
    vector<double> nilai(n);
    cout << "Masukkan nilai: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    double total = 0;
    for (int i = 0; i < n; i++) {
        total += nilai[i];
    }

    double rata = total / n;
    return rata;  
}

void cekLulus(double nilai) {
	
     if(nilai >= 70)
       cout << "LULUS" << endl;
     else
       cout << "TIDAK LULUS" << endl; 
}

char getIndeks(double nilai) {
	 
     if(nilai >= 85 && nilai <= 100) 
		return 'A';
	 else if(nilai >= 75)
		return 'B';
	 else if(nilai >= 60)
		return 'C';
	 else if(nilai >= 40)
		return 'D';
	 else 
		return 'E';
}
