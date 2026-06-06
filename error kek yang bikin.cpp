#include <iostream>
#include <string>
using namespace std;

int main () {
	string usrnm;
	string username = "admin";
	string pw;
	string password = "020";
	string st;
	int remainingAttempts = 3;
	int cusMenu, cusTicket, numTicket, price, purchase, disc, subTotal, rebate, totalPayment, totalTicket, totalTransaction;
	subTotal = 0;
	disc = 0;
	price = 0;
	totalTicket = 0;
	totalTransaction = 0;
	
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
													cout << endl;
														return (0);
			}
		}
	}
	do {
		cout << "=====================================";
			cout << endl;
				cout << "		MAIN MENU			";
					cout << endl;
						cout << "=====================================";
							cout << endl;
								cout << "1. Buy Ticket";
									cout << endl;
										cout << "2. View Transaction Summary";
											cout << endl;
												cout << "3. Exit";
													cout << endl;
														cout << "=====================================";
															cout << endl;
																cout << "Choose menu (1-3) : "; cin >> cusMenu;
																	cout << endl;
																		cout << "=====================================";
																			cout << endl;
	if (cusMenu == 1) {
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
						cout << endl;
	
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
	if (numTicket >= 10) disc = 20;
	else if (numTicket >= 5) disc = 10;
	if (cusTicket == 4 && numTicket >= 3) disc += 5;
	rebate = purchase * disc / 100;
	totalPayment = purchase - rebate;
	
	cout << "--- PURCHASE DETAILS ---";
	cout << endl;
	
	if (cusTicket == 1)
		st = "Regular";
		else if (cusTicket == 2)
			st = "Deluxe";
				else if (cusTicket == 3)
					st = "Premium";
						else if (cusTicket == 4)
							st = "VIP";
	
	cout << "Seat Type : " << st;
		cout << endl;
			cout << "Ticket Quantity : " << numTicket;
				cout << endl;
					cout << "Unit Price : Rp " << price;
						cout << endl;
							cout << "Subtotal : Rp " << purchase;
								cout << endl;
									cout << "Discount (" << disc << "%) : Rp " << rebate;
										cout << endl;
											cout << "Total Price : Rp " << totalPayment;
												cout << endl << endl;
													cout << "Transaction saved successfully";
														cout << endl;
														subTotal += totalPayment;
															totalTicket += numTicket;
																totalTransaction += 1;
	} else if (cusMenu == 2) {
			cout << endl;
				cout << endl;
					cout << "=====================================";
						cout << endl;
							cout << "TRANSACTION SUMMARY";
								cout << endl;
									cout << "=====================================";
										cout << endl;
			cout << "Total Tickets : " << totalTicket;
				cout << endl;
					cout << "Total Tansactions : " << totalTransaction;
						cout << endl;
							cout << "Total Purchase : " << subTotal;
								cout << endl;
				} else if (cusMenu == 3) {
						cout << "THANK YOU:D";
							return (0);
					} else {
							cout << "GA ADA DI OPSI BEGO!";
								cout << endl;
									cout << endl;
		}
	} while (true);
}
