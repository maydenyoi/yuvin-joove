#include <iostream>
using namespace std;

int main() {
    string user, pass, nim;
    int kesempatan = 3;

    cout << "Masukkan NIM anda: ";
    cin >> nim;

    // Ambil 3 digit terakhir dari NIM untuk password
    string passwordNIM = nim.substr(nim.length() - 3);

    // Login
    while (kesempatan > 0) {
        cout << "\nUsername: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (user == "admin" && pass == passwordNIM) {
            cout << "\nLogin berhasil!\n";

            int menu, jumlah, total = 0;
            char ulang;

            do {
                cout << "\n=== MENU TIKET ===\n";
                cout << "1. Regular (35000)\n";
                cout << "2. Deluxe  (50000)\n";
                cout << "3. Premium (75000)\n";
                cout << "4. VIP     (100000)\n";
                cout << "Pilih jenis tiket (1-4): ";
                cin >> menu;

                cout << "Masukkan jumlah tiket: ";
                cin >> jumlah;

                int harga = 0;
                if (menu == 1) harga = 35000;
                else if (menu == 2) harga = 50000;
                else if (menu == 3) harga = 75000;
                else if (menu == 4) harga = 100000;
                else {
                    cout << "Pilihan tidak valid!\n";
                    continue; // balik ke atas do-while
                }

                int bayar = harga * jumlah;
                int diskonPersen = 0;

                // Aturan diskon
                if (jumlah >= 10) diskonPersen = 20;
                else if (jumlah >= 5) diskonPersen = 10;
                if (menu == 4 && jumlah >= 3) diskonPersen += 5;

                int potongan = bayar * diskonPersen / 100;
                int totalBayar = bayar - potongan;

                cout << "\nTotal harga sebelum diskon : Rp " << bayar;
                cout << "\nDiskon : " << diskonPersen << "%";
                cout << "\nTotal bayar : Rp " << totalBayar << endl;

                total += totalBayar;

                cout << "\nBeli lagi? (y/n): ";
                cin >> ulang;

            } while (ulang == 'y' || ulang == 'Y');

            cout << "\nTotal semua transaksi: Rp " << total << endl;
            cout << "Terima kasih sudah membeli!\n";
            break;
        } 
        else {
            kesempatan--;
            cout << "Username atau password salah! Kesempatan tersisa: " << kesempatan << endl;
            if (kesempatan == 0) {
                cout << "Kesempatan habis, login gagal.\n";
            }
        }
    }

    return 0;
}
