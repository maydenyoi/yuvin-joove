#include <iostream>
using namespace std;

int main() {
    string username, password;
    int loginAttempts = 0;
    string correctUsername = "admin";
    string correctPassword = "admin1234";
    
    while (loginAttempts < 3) {
        cout << "=== LOGIN ===" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        
        if (username == correctUsername && password == correctPassword) {
            cout << "\nLogin success!\n" << endl;
            break;
        } else {
            cout << "Login failed! Try again.\n" << endl;
            loginAttempts++;
        }
    }
    
    if (loginAttempts == 3) {
        cout << "Too many attempts. Program terminated." << endl;
        return 0;
    }
    
    string nama[100];
    float nilai[100][3];
    int jumlahSiswa = 0;
    int pilihan;
    
    while (true) {
        cout << "=== MAIN MENU ===" << endl;
        cout << "1. Input student data" << endl;
        cout << "2. View student data" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            int n;
            cout << "\nHow many students do you want to input?" << endl;
            cout << "=> ";
            cin >> n;
            
            if (jumlahSiswa + n > 100) {
                cout << "Error: Cannot add more than 100 students!" << endl;
                continue;
            }
            
            for (int i = 0; i < n; i++) {
                cout << "\nStudent number " << (jumlahSiswa + 1) << endl;
                cout << "Name: ";
                cin >> nama[jumlahSiswa];
                cout << "Score 1: ";
                cin >> nilai[jumlahSiswa][0];
                cout << "Score 2: ";
                cin >> nilai[jumlahSiswa][1];
                cout << "Score 3: ";
                cin >> nilai[jumlahSiswa][2];
                jumlahSiswa++;
            }
            
            cout << "\nData successfully added!\n" << endl;
            
        } else if (pilihan == 2) {
            if (jumlahSiswa == 0) {
                cout << "\nNo student data available.\n" << endl;
            } else {
                cout << "\n| No | Name | Score 1 | Score 2 | Score 3 | Average |" << endl;
                cout << "--------------------------------------------------------" << endl;
                
                for (int i = 0; i < jumlahSiswa; i++) {
                    float rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
                    
                    cout << "| " << (i + 1) << " | ";
                    cout << nama[i] << " | ";
                    cout << nilai[i][0] << " | ";
                    cout << nilai[i][1] << " | ";
                    cout << nilai[i][2] << " | ";
                    cout << rata << " |" << endl;
                }
                cout << endl;
            }
            
        } else if (pilihan == 3) {
            cout << "Thank you for using the program. Goodbye!" << endl;
            break;
            
        } else {
            cout << "Error: Invalid option! Please choose 1, 2, or 3.\n" << endl;
        }
    }
    
    return 0;
}
