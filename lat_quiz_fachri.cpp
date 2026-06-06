#include <iostream>
using namespace std;

int main() {
    int kesempatan = 3;
    string username_benar = "Fachri";
    string pass_benar = "139";
    
    while (kesempatan > 0) {
        string pass, usn;
        cout << "Masukkan Username : "; cin >> usn;
        cout << "Masukkan PIN ATM  : "; cin >> pass;
        if (pass == pass_benar && usn == username_benar) {
            cout << "PIN Benar!" << endl;
            break;
        } else {
            kesempatan--;
            cout << "PIN Salah, Coba lagi" << endl;
            cout << "Sisa Kesempatan : " << kesempatan << endl;
        }
    }

    if (kesempatan == 0) {
        cout << "Goodbye" << endl;
        exit(0);
    } else {
        int menu, kopi, cappuccino, teh;
        int stokKopi = 40, stokCappuccino = 25, stokTeh = 35;
        int harga, totalPendapatan = 0, totalJual = 0;
        char ulang;

        do {
            system("cls");
            cout << "=================================================" << endl;
            cout << "|          === WARUNG KOPI MAS BUDI ===         |" << endl;
            cout << "=================================================" << endl;
            cout << "| 1. Kopi Hitam (KH)     - Rp 7000  | Stok : " << stokKopi << " |" << endl;
            cout << "| 2. Cappuccino (CP)     - Rp 10000 | Stok : " << stokCappuccino << " |" << endl;
            cout << "| 3. Es Teh Manis (KH)   - Rp 5000  | Stok : " << stokTeh << " |" << endl;
            cout << "| 4. Keluar dan Tampilkan Laporan               |" << endl;
            cout << "=================================================" << endl;
            cout << "Pilih Menu (1-4): "; cin >> menu;

            switch (menu) {
                case 1:
                    cout << "Masukkan Jumlah Kopi Hitam : "; cin >> kopi;
                    if (kopi > stokKopi) {
                        cout << "Stok tidak cukup! Stok tersisa: " << stokKopi << endl;
                    } else if (kopi <= 0) {
                        cout << "Jumlah tidak valid!" << endl;
                    } else {
                        harga = kopi * 7000;
                        stokKopi -= kopi;
                        totalPendapatan += harga;
                        totalJual += kopi;
                        cout << "Pesanan berhasil! Harga = Rp " << harga << endl;
                    }
                    break;

                case 2:
                    cout << "Masukkan Jumlah Cappuccino: "; cin >> cappuccino;
                    if (cappuccino > stokCappuccino) {
                        cout << "Stok tidak cukup! Stok tersisa: " << stokCappuccino << endl;
                    } else if (cappuccino <= 0) {
                        cout << "Jumlah tidak valid!" << endl;
                    } else {
                        harga = cappuccino * 10000;
                        stokCappuccino -= cappuccino;
                        totalPendapatan += harga;
                        totalJual += cappuccino;
                        cout << "Pesanan berhasil! Harga = Rp " << harga << endl;
                    }
                    break;

                case 3:
                    cout << "Masukkan Jumlah Es Teh Manis: "; cin >> teh;
                    if (teh > stokTeh) {
                        cout << "Stok tidak cukup! Stok tersisa: " << stokTeh << endl;
                    } else if (teh <= 0) {
                        cout << "Jumlah tidak valid!" << endl;
                    } else {
                        harga = teh * 5000;
                        stokTeh -= teh;
                        totalPendapatan += harga;
                        totalJual += teh;
                        cout << "Pesanan berhasil! Harga = Rp " << harga << endl;
                    }
                    break;

                case 4:
                    cout << "=== Laporan Akhir Penjualan ===" << endl;
                    cout << "Total minuman terjual = " << totalJual << endl;
                    cout << "Total pendapatan = Rp " << totalPendapatan << endl;
                    cout << "Terima kasih!" << endl;
                    return 0;

                default:
                    cout << "Pilihan tidak valid!" << endl;
            }

            cout << "\nApakah ingin memesan minuman lagi (y/n)? ";
            cin >> ulang;

        } while (ulang == 'y' || ulang == 'Y');

        cout << "=== Laporan Akhir Penjualan ===" << endl;
        cout << "Total minuman terjual = " << totalJual << endl;
        cout << "Total pendapatan = Rp " << totalPendapatan << endl;
        cout << "Terima kasih!" << endl;
    }

    return 0;
}
