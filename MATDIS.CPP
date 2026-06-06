// #include <iostream>
// using namespace std;

// // Fungsi untuk memeriksa apakah ada dua bilangan dengan selisih tertentu
// bool adaSelisih(const int angka[], int ukuran, int selisih) {
//     bool angkaTerlihat[101] = {false};

//     for (int i = 0; i < ukuran; i++) {
//         int num = angka[i];

//         // Memeriksa apakah ada angka dengan selisih yang diinginkan
//         if (num - selisih > 0 && angkaTerlihat[num - selisih]) {
//             return true;
//         }
//         if (num + selisih <= 100 && angkaTerlihat[num + selisih]) {
//             return true;
//         }

//         // Tandai bahwa angka ini sudah pernah dilihat
//         angkaTerlihat[num] = true;
//     }
//     return false;
// }

// int main() 
 
// {
//        system("CLS");
//     int ukuran, selisih;

//     // Meminta jumlah minimal bilangan yang ingin diinput
//     cout << "Masukkan jumlah minimal bilangan yang ingin diinput: ";
//     cin >> ukuran;

//     if (ukuran < 1 || ukuran > 100) {
//         cout << "Jumlah bilangan harus antara 1 hingga 100.\n";
//         return 1;
//     }

//     // Meminta nilai selisih yang diinginkan
//     cout << "Masukkan nilai selisih yang diinginkan: ";
//     cin >> selisih;

//     if (selisih < 1 || selisih > 100) {
//         cout << "Nilai selisih harus antara 1 hingga 100.\n";
//         return 1;
//     }

//     int angkaDipilih[ukuran];
//     cout << "Masukkan " << ukuran << " bilangan yang dipilih (antara 1 hingga 100):\n";
//     for (int i = 0; i < ukuran; i++) {
//         cout << "Bilangan ke-" << (i + 1) << ": ";
//         cin >> angkaDipilih[i];

//         if (angkaDipilih[i] < 1 || angkaDipilih[i] > 100) {
//             cout << "Bilangan harus berada dalam rentang 1 hingga 100.\n";
//             return 1;
//         }
//     }

//     // Menampilkan bilangan yang diinput dan selisih yang dicari
//     cout << "\nBilangan yang Anda masukkan:\n";
//     for (int i = 0; i < ukuran; i++) {
//         cout << angkaDipilih[i] << " ";
//     }
//     cout << "\nSelisih yang dicari: " << selisih << endl;

//     // Menampilkan hasil pemeriksaan berdasarkan prinsip pigeonhole
//     if (adaSelisih(angkaDipilih, ukuran, selisih)) {
//         cout << "Ditemukan dua bilangan dengan selisih " << selisih << "." << endl;
//     } else {
//         cout << "Tidak ditemukan dua bilangan dengan selisih " << selisih << "." << endl;
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

// Fungsi untuk memeriksa apakah ada dua bilangan dengan selisih tertentu
bool adaSelisih(const int angka[], int ukuran, int selisih) {
    bool angkaTerlihat[101] = {false}; // Array untuk menandai angka yang sudah dilihat

    // Melakukan iterasi pada setiap angka yang ada
    for (int i = 0; i < ukuran; i++) {
        int num = angka[i];

        // Memeriksa apakah ada angka dengan selisih yang diinginkan (num - selisih)
        // Jika ada angka sebelumnya dengan selisih yang sesuai, kembalikan true
        if (num - selisih > 0 && angkaTerlihat[num - selisih]) {
            return true;
        }

        // Memeriksa apakah ada angka dengan selisih yang diinginkan (num + selisih)
        // Jika ada angka sebelumnya dengan selisih yang sesuai, kembalikan true
        if (num + selisih <= 100 && angkaTerlihat[num + selisih]) {
            return true;
        }

        // Tandai bahwa angka ini sudah pernah dilihat
        angkaTerlihat[num] = true;
    }

    // Jika tidak ada pasangan angka dengan selisih yang sesuai, kembalikan false
    return false;
}

int main() {
    int ukuran, selisih;

    // Meminta jumlah minimal bilangan yang ingin diinput oleh pengguna
    cout << "Masukkan jumlah minimal bilangan yang ingin diinput: ";
    cin >> ukuran;

    // Mengecek apakah jumlah bilangan yang dimasukkan valid (antara 1 dan 100)
    if (ukuran < 1 || ukuran > 100) {
        cout << "Jumlah bilangan harus antara 1 hingga 100.\n";
        return 1; // Keluar dari program jika input tidak valid
    }

    // Meminta nilai selisih yang diinginkan untuk dicari
    cout << "Masukkan nilai selisih yang diinginkan: ";
    cin >> selisih;

    // Mengecek apakah nilai selisih yang dimasukkan valid (antara 1 dan 100)
    if (selisih < 1 || selisih > 100) {
        cout << "Nilai selisih harus antara 1 hingga 100.\n";
        return 1; // Keluar dari program jika input tidak valid
    }

    int angkaDipilih[ukuran]; // Array untuk menyimpan angka yang dipilih pengguna
    cout << "Masukkan " << ukuran << " bilangan yang dipilih (antara 1 hingga 100):\n";
    
    // Meminta pengguna untuk memasukkan angka sesuai jumlah yang diminta
    for (int i = 0; i < ukuran; i++) {
        cout << "Bilangan ke-" << (i + 1) << ": ";
        cin >> angkaDipilih[i];

        // Mengecek apakah angka yang dimasukkan berada dalam rentang yang valid (1 hingga 100)
        if (angkaDipilih[i] < 1 || angkaDipilih[i] > 100) {
            cout << "Bilangan harus berada dalam rentang 1 hingga 100.\n";
            return 1; // Keluar dari program jika input tidak valid
        }
    }

    // Menampilkan bilangan yang telah dimasukkan oleh pengguna
    cout << "\nBilangan yang Anda masukkan:\n";
    for (int i = 0; i < ukuran; i++) {
        cout << angkaDipilih[i] << " ";
    }
    cout << "\nSelisih yang dicari: " << selisih << endl;

    // Menampilkan hasil pemeriksaan apakah ada dua bilangan dengan selisih yang dicari
    if (adaSelisih(angkaDipilih, ukuran, selisih)) {
        cout << "Ditemukan dua bilangan dengan selisih " << selisih << "." << endl;
    } else {
        cout << "Tidak ditemukan dua bilangan dengan selisih " << selisih << "." << endl;
    }

    return 0; // Program selesai
}
