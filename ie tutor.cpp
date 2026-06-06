#include <iostream>
#include <string>
using namespace std;

int main () {
	int total_ticket;
	cout << "How many ticket do you have?"; cin >> total_ticket;
	
	if (total_ticket > 5)
		cout << "Congrats! You've got 1 voucher" << endl;
		
	cout << "Thank you for buying!";
}
