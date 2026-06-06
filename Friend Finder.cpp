#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct User {
    string nama;
    string gender;
    string hobby;
    int usia;
};

User dataUser[MAX];
int similarity[MAX][MAX];
int jumlahUser = 0;

// ================= VALIDASI =================
bool isValidString(string str) {
    for (char c : str) {
        if (isdigit(c)) return false;
    }
    return true;
}

string inputString(string pesan) {
    string data;
    while (true) {
        cout << pesan;
        getline(cin, data);

        if (data.empty()) {
            cout << "Tidak boleh kosong!\n";
            continue;
        }

        if (isValidString(data)) return data;
        else cout << "Tidak boleh mengandung angka!\n";
    }
}

string inputGender() {
    string gender;
    while (true) {
        cout << "Gender (L/P): ";
        getline(cin, gender);

        if (gender == "L" || gender == "l") return "L";
        if (gender == "P" || gender == "p") return "P";

        cout << "Hanya boleh L atau P!\n";
    }
}

int inputUsia() {
    string input;
    while (true) {
        cout << "Usia   : ";
        getline(cin, input);

        try {
            int usia = stoi(input);
            if (usia > 0) return usia;
            else cout << "Usia harus > 0!\n";
        } catch (...) {
            cout << "Harus angka!\n";
        }
    }
}

int inputMenu() {
    string input;
    while (true) {
        cout << "Pilih: ";
        getline(cin, input);

        try {
            return stoi(input);
        } catch (...) {
            cout << "Harus angka!\n";
        }
    }
}

// ================= FILE =================
void saveData() {
    ofstream file("kaneki.txt");
    for (int i = 0; i < jumlahUser; i++) {
        file << dataUser[i].nama << "|"
             << dataUser[i].gender << "|"
             << dataUser[i].hobby << "|"
             << dataUser[i].usia << endl;
    }
    file.close();
}

void loadData() {
    ifstream file("kaneki.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string nama, gender, hobby, usiaStr;

        getline(ss, nama,       '|');
        getline(ss, gender,     '|');
        getline(ss, hobby,      '|');
        getline(ss, usiaStr,    '|');

        if (nama.empty() || gender.empty() || hobby.empty() || usiaStr.empty()) continue;

        try {
            int usia = stoi(usiaStr);

            dataUser[jumlahUser].nama = nama;
            dataUser[jumlahUser].gender = gender;
            dataUser[jumlahUser].hobby = hobby;
            dataUser[jumlahUser].usia = usia;

            jumlahUser++;
        } catch (...) {
            continue;
        }
    }

    file.close();
}

// ================= RECURSIVE =================
void tampilRecursive(int i) {
    if (i >= jumlahUser) return;

    cout<< left
        << setw(5)  << i + 1
        << setw(20) << dataUser[i].nama
        << setw(10) << dataUser[i].gender
        << setw(15) << dataUser[i].hobby
        << setw(5) << dataUser[i].usia
        << endl;

    tampilRecursive(i + 1);
}

// ================= SEARCH =================
int cariUser(string nama) {
    for (int i = 0; i < jumlahUser; i++) {
        if (dataUser[i].nama == nama) return i;
    }
    return -1;
}

// ================= SORT =================
void sortNama() {
    for (int i = 0; i < jumlahUser - 1; i++) {
        for (int j = 0; j < jumlahUser - i - 1; j++) {
            if (dataUser[j].nama > dataUser[j+1].nama) {
                swap(dataUser[j], dataUser[j+1]);
            }
        }
    }
}

// ================= TAMBAH =================
void tambahUser(User *u) {
    u->nama   = inputString("Nama   : ");
    u->gender = inputGender();
    u->hobby  = inputString("Hobby  : ");
    u->usia   = inputUsia();
}

// ================= EDIT =================
void editData() {
    string nama;
    cout << "Masukkan nama: ";
    getline(cin, nama);

    int idx = cariUser(nama);

    if (idx != -1) {
        tambahUser(&dataUser[idx]);
        cout << "Data berhasil diupdate!\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}

// ================= HAPUS =================
void hapusData() {
    string nama;
    cout << "Masukkan nama: ";
    getline(cin, nama);

    int idx = cariUser(nama);

    if (idx != -1) {
        for (int i = idx; i < jumlahUser - 1; i++) {
            dataUser[i] = dataUser[i+1];
        }
        jumlahUser--;
        cout << "Data berhasil dihapus!\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}

// ================= HITUNG SKOR =================
int hitungSkor(User a, User b) {
    int skor = 0;

    if (a.gender == b.gender) skor += 20;
    if (a.hobby == b.hobby) skor += 40;

    int selisih = abs(a.usia - b.usia);
    if (selisih <= 2) skor += 40;
    else if (selisih <= 5) skor += 20;

    return skor;
}

// ================= DETAIL MATCH =================
void tampilDetail(User a, User b) {
    // Gender
    cout << "- Gender: " << a.gender << " vs " << b.gender;
    if (a.gender == b.gender)
        cout << " (sama +20)\n";
    else
        cout << " (berbeda)\n";

    // Hobby
    cout << "- Hobby: " << a.hobby << " vs " << b.hobby;
    if (a.hobby == b.hobby)
        cout << " (sama +40)\n";
    else
        cout << " (berbeda)\n";

    // Usia
    int selisih = abs(a.usia - b.usia);
    cout << "- Selisih usia: " << selisih;
    if (selisih <= 2)
        cout << " (+40)\n";
    else if (selisih <= 5)
        cout << " (+20)\n";
    else
        cout << " (0)\n";
}

// ================= FRIEND FINDER =================
void friendFinder() {
    if (jumlahUser < 2) {
        cout << "Minimal 2 user!\n";
        return;
    }

    cout << "\n===== DAFTAR USER =====\n";
    for (int i = 0; i < jumlahUser; i++) {
        cout << i + 1 << ". " << dataUser[i].nama << endl;
    }

    int pilih;
    while (true) {
        cout << "Pilih nomor user: ";
        string input;
        getline(cin, input);

        try {
            pilih = stoi(input);

            if (pilih >= 1 && pilih <= jumlahUser)
                break;
            else
                cout << "Nomor tidak valid!\n";

        } catch (...) {
            cout << "Harus angka!\n";
        }
    }

    int i = pilih - 1;

    cout << "\n===== HASIL UNTUK "
         << dataUser[i].nama
         << " =====\n";

    int maxSkor = -1;

    // Hitung semua skor
    for (int j = 0; j < jumlahUser; j++) {
        if (i == j) continue;

        similarity[i][j] = hitungSkor(dataUser[i], dataUser[j]);

        cout << "\nDengan "
             << dataUser[j].nama
             << " = "
             << similarity[i][j]
             << "%\n";

        tampilDetail(dataUser[i], dataUser[j]);

        if (similarity[i][j] > maxSkor) {
            maxSkor = similarity[i][j];
        }
    }

    // Tampilkan semua best match
    if (maxSkor != -1) {
        cout << "\n===== BEST MATCH =====\n";

        for (int j = 0; j < jumlahUser; j++) {
            if (i == j) continue;

            if (similarity[i][j] == maxSkor) {
                cout << dataUser[i].nama
                     << " cocok dengan "
                     << dataUser[j].nama
                     << " ("
                     << maxSkor
                     << "%)\n";
            }
        }
    }
}

// ================= MAIN =================
int main() {
    loadData();

    int pilihan;

    do {
        cout << "\n===== FRIEND FINDER SYSTEM =====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Edit Data\n";
        cout << "3. Hapus Data\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Friend Finder\n";
        cout << "6. Exit\n";

        pilihan = inputMenu();

        switch (pilihan) {
            case 1:
                if (jumlahUser < MAX) {
                    tambahUser(&dataUser[jumlahUser]);
                    jumlahUser++;
                    saveData();
                } else {
                    cout << "Data penuh!\n";
                }
                break;

            case 2:
                editData();
                saveData();
                break;

            case 3:
                hapusData();
                saveData();
                break;

            case 4:
                sortNama();

                cout << left
                     << setw(5)<<"No"
                     << setw(20)<<"Nama"
                     << setw(10)<<"Gender"
                     << setw(15)<<"Hobi"
                     << setw(5)<<"Usia"
                     << endl;
                
                cout<<"------------------------------------------------------\n";

                tampilRecursive(0);
                break;

            case 5:
                friendFinder();
                break;

            case 6:
                cout << "Keluar...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}
