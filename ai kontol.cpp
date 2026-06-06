#include <iostream>
#include <string>
using namespace std;

int main() {
	string usrnm;
	string usernameBenar  = "admin";
	string pw, pwBenar = "020";
	int chance = 2;
	
	while (chance > 0) {
		cout << "Username : "; cin >> usrnm;
		cout << "Password : "; cin >> pw;
		
			if (usrnm == usernameBenar && pw == pwBenar) {
				cout << "Login berhasil!" << endl;
				break;
			} else {
					chance--;
				if (chance > 0) {
						cout << "ada yang gak bener nih!" << endl;
						cout << "kesempatan tersisa : " << chance << endl;
					} else {
							cout << "abis deh";
				}
			}
		}
}
