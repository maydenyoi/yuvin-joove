#include <iostream>
#include <string>
using namespace std;

int main() {
    string usernameBenar = "admin";
    string usrnm;
    string pw, pwBenar = "020";
    int chance = 2;

    while (chance > 0) {
        cout << "Username : ";
        cin >> usrnm;
        cout << "Password : ";
        cin >> pw;

        if (usrnm == usernameBenar && pw == pwBenar) {
            cout << "Login berhasil!" << endl;
            break;
        } else {
            chance--;
            if (chance > 0) {
                cout << "Ada yang gak bener nih!" << endl;
                cout << "Kesempatan tersisa : " << chance << endl;
            } else {
                cout << "Abis deh 😢" << endl;
            }
        }
    }

    return 0;
}
