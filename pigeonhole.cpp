#include <iostream>
using namespace std;

int main() {
    int s, k;
    cout << "Siswa: "; cin >> s;
    cout << "Kelompok: "; cin >> k;
    
    int min = s / k;
    int sisa = s % k;
    
    cout << "Minimal: " << min << " siswa" << endl;
    
    if (sisa > 0) {
    cout << sisa << " Kelompok mendapat " << min + 1 << " siswa" << endl;
	} else {
			cout << "Tidak ada kelompok yang mendapat " << (min + 1) << " siswa" << endl;
		}
    if(s > k) {
        if (sisa > 0 ) {
          cout << "Pasti ada kelompok yang >= " << min << " siswa" << endl;
        } else {
            cout <<"Tidak ada kelompok yang > " << min << " siswa" << endl;
        }
    } else {
		cout << "Bukan termasuk Prinsip Pigeonhole"; 
	}
    
    return 0;
}
