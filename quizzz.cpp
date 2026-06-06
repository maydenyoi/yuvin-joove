#include <iostream>
#include <string>
using namespace std;

int main () {
	string usrnm;
	string username = "admin";
	string pw;
	string password = "020";
	int remainingAttempts = 3;
	int cusMenu, cusTicket, numTicket, price, purchase, disc;
	disc = 0;
	price = 0;
	
	cout << "===========================" << endl;
	cout << "CINEMA TICKET SALES SYSTEM" << endl;
	cout << "===========================" << endl;
	cout << endl;
	
	while (remainingAttempts >= 1) {
		cout << "--- Login ---";
		cout << endl;
		cout << "Username : "; cin >> usrnm;
		cout << "Password : "; cin >> pw;
			
				if (usrnm == username && pw == password) {
					cout << "Login successful! Welcome, admin!";
					cout << endl;
					cout << endl;
					cout << endl;
						break;
				} else {
					remainingAttempts--; 
					if (remainingAttempts >= 1) {
						cout << endl;
						cout << "Incorrect username or password";
						cout << endl;
						cout << "Remaining attempts : ";
						cout << remainingAttempts;
						cout << endl;
						cout << endl;
					} else {
							cout << endl;
							cout << "Incorrect username or password";
							cout << endl;
							cout << "Remaining attempts : ";
							cout << remainingAttempts;
							cout << endl;
							cout << endl;
							cout << "Program terminated for security reason.";
					}
				}
				break;
		}	
	do {
	cout << "=====================================";
	cout << endl;
	cout << "Choose menu (1-3) : "; cin >> cusMenu;
	cout << "=====================================";
	cout << endl;
	cout << endl;
	cout << "=====================================";
	cout << endl;
	cout << "	TICKET PRICE LIST		";
	cout << endl;
	cout << "=====================================";
	cout << endl;
	cout << "1. Regular		- Rp 35, 000";
	cout << endl;
	cout << "2. Deluxe		- Rp 50, 000";
	cout << endl;
	cout << "3. Premium		- Rp 75, 000";
	cout << endl;
	cout << "4. VIP			- Rp 100, 000";
	cout << endl;
	cout << "=====================================";
	cout << endl;
	cout << "Choose ticket type (1-4) : "; cin >> cusTicket;
	cout << "Number of tickets to buy : "; cin >> numTicket;
	
	if (cusTicket == 1)
		price = 35000;
	else if (cusTicket == 2)
		price = 50000;
	else if (cusTicket == 3)
			price = 75000;
	else if (cusTicket == 4)
				price = 100000;
	else {
		return 0;
		}
	purchase = price * numTicket;
	disc 
	
	} while () {
		return 0;
		}
}
