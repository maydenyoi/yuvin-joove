#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <iomanip>
#include <string>
#pragma comment(lib, "winmm.lib")

using namespace std;

int error(string suruh, string eror, long long int lim) {
    int x;
    do{
        cout << suruh << " ";
        cin >> x;
        if(cin.fail()||x>lim||x<=0){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << eror << endl;
        } else {
            return x;
        }
    } while (true);
}

char error1(string s, string pesan) {
    while (true) {
        cout << pesan << endl;
        getline(cin >> ws, s);

        if (s.length() != 1) {
            cout << "Invalid option!\n";
            continue;
        }

        if (!isalpha(s[0])) {
            cout << "Invalid option!\n";
            continue;
        }
        if (s == "y" || s== "Y" || s == "n" || s== "N") {
            return s[0];
        } else {
            cout << "Invalid option!\n";
            continue;
        }
    }
}

bool validateMemberCode() {
    string kodeMember;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;
    
    cout << "\n=== VERIFIKASI MEMBER ===\n";
    
    while (attempts < MAX_ATTEMPTS) {
        cout << "Masukkan kode member (Attempt " << attempts + 1 << "/" << MAX_ATTEMPTS << "): ";
        getline(cin >> ws, kodeMember);
        
        if (kodeMember == "fizi2025") {
            cout << "Kode member benar! Diskon 5% diterapkan.\n";
            return true;
        } else {
            attempts++;
            cout << "Kode member salah! ";
            
            if (attempts >= MAX_ATTEMPTS) {
                cout << "Kesempatan habis. Tidak mendapatkan diskon member.\n";
                return false;
            } else {
                cout << "Coba lagi.\n";
            }
        }
    }
    return false;
}

int main() {
    mciSendString("open \"Graze.mp3\" type mpegvideo alias musik", NULL, 0, NULL);
    mciSendString("play musik repeat", NULL, 0, NULL);
    
    const int JUMLAH_BARANG = 40;

    string namaBarang[JUMLAH_BARANG] = {
        "Beras 5kg", "Minyak Goreng 1L", "Gula Pasir 1kg", "Teh Celup", "Kopi Sachet",
        "Susu Kotak", "Mie Instan", "Roti Tawar", "Air Mineral 600ml", "Telur Ayam 1kg",
        "Sabun Mandi", "Shampoo", "Sikat Gigi", "Odol", "Detergen",
        "Pewangi Pakaian", "Kain Pel", "Sapu Lantai", "Tisu", "Tisu Basah",
        "Baterai AA", "Lampu LED", "Pulpen", "Pensil", "Buku Tulis",
        "Kertas A4", "Lakban", "Gunting", "Piring", "Gelas",
        "Sendok", "Garpu", "Nasi Kotak", "Ayam Goreng", "Sosis",
        "Keju Slice", "Mentega", "Saus Sambal", "Kecap Manis", "Kerupuk"
    };

    int hargaBarang[JUMLAH_BARANG] = {
        60000, 14000, 13000, 4000, 2000,
        7000, 3000, 10000, 3500, 26000,
        4000, 12000, 7000, 5000, 18000,
        9000, 5000, 12000, 8000, 10000,
        15000, 18000, 4000, 3000, 5000,
        35000, 6000, 10000, 8000, 6000,
        3000, 3000, 15000, 12000, 10000,
        17000, 8000, 6000, 7000, 5000
    };

    int pilih, qty;
    char ulang, member;
    int total = 0;
    bool udahan = true;
    int menu;
    
    do{    
        cout << "=============================================\n";
        cout << "           MENU TOKO FIZI MAKMUR\n";
        cout << "=============================================\n";
        cout << "1. Beli barang\n";
        cout << "2. exit\n";	
        menu = error("Pilih menu (1-2):", "Invalid option!", 2);

        if (menu == 1) {
            cout << "=============================================\n";
            cout << "              TOKO FIZI MAKMUR\n";
            cout << "=============================================\n\n";
            
            total = 0; // Reset total setiap transaksi baru

            do {
                // Tampilkan semua barang
                cout << "DAFTAR BARANG (1 - 40)\n";
                cout << "---------------------------------------------\n";
                for (int i = 0; i < JUMLAH_BARANG; i++) {
                    cout << setw(2) << i + 1 << ". "
                         << left << setw(20) << namaBarang[i]
                         << "Rp " << hargaBarang[i] << endl;
                }
                cout << "---------------------------------------------\n";

                // Input barang
                pilih = error("Pilih barang (1-40):", "Invalid option!", 40);
                qty = error("Jumlah barang:", "Invalid option!", 100);

                int subtotal = hargaBarang[pilih - 1] * qty;
                total += subtotal;

                cout << "Subtotal: Rp " << subtotal << endl;
                cout << "Total sementara: Rp " << total << endl;
            
                string b;
                ulang = error1(b, "Tambah barang lain? (y/n):");
                    
            } while (ulang == 'y' || ulang == 'Y');
            
            // CEK MEMBER DENGAN KODE
            string a;
            member = error1(a, "Apakah pelanggan member? (y/n):");

            double diskon = 0;
            bool isMemberValid = false;

            if (member == 'y' || member == 'Y') {
                isMemberValid = validateMemberCode();
                if (isMemberValid) {
                    diskon = total * 0.05;
                    cout << "Diskon yang didapat: Rp " << diskon << endl;
                }
            }

            double totalBayar = total - diskon;

            // Tampilkan summary sebelum bayar
            cout << "\n=============================================\n";
            cout << "             RINGKASAN BELANJA\n";
            cout << "=============================================\n";
            cout << "Total Belanja    : Rp " << total << endl;
            if (isMemberValid) {
                cout << "Status Member    : ✓ AKTIF (Diskon 5%)\n";
                cout << "Diskon Member    : Rp " << diskon << endl;
            } else {
                cout << "Status Member    : ✗ TIDAK AKTIF\n";
                cout << "Diskon Member    : Rp 0" << endl;
            }
            cout << "Total Bayar      : Rp " << totalBayar << endl;
            cout << "=============================================\n";

            int bayar = error("Masukkan uang bayar: Rp ", "Invalid amount!", 1000000000);
            
            if (bayar >= totalBayar) {
                int kembalian = bayar - totalBayar;

                // CETAK STRUK
                cout << "\n\n=============================================\n";
                cout << "                TOKO FIZI MAKMUR\n";
                cout << "=============================================\n";
                cout << "Total Belanja   : Rp " << total << endl;
                if (isMemberValid) {
                    cout << "Diskon Member   : Rp " << diskon << " (5%)" << endl;
                }
                cout << "Total Bayar     : Rp " << totalBayar << endl;
                cout << "Uang Diterima   : Rp " << bayar << endl;
                cout << "Kembalian       : Rp " << kembalian << endl;
                cout << "=============================================\n";
                cout << "       Terima kasih telah berbelanja!\n";
                cout << "=============================================\n";
            } else {
                cout << "Uang tidak cukup!! Silahkan berikan uang yang pas.\n";
            }

            system("pause");
            system("cls");
        }
        else if (menu == 2) {
            cout << "Terima kasih telah berbelanja di TOKO FIZI MAKMUR\n";
            udahan = false;
        }
    } while(udahan);

    // Cleanup musik
    mciSendString("stop musik", NULL, 0, NULL);
    mciSendString("close musik", NULL, 0, NULL);
    
    return 0;
}
