#include <iostream>
#include <string>
using namespace std;

int main () {
	int choose, duration;
	int basePrice, afterFirstHour;
	char member;
	string vehiclesType;
	
	
    cout << "=== PARKING MANAGEMENT SYSTEM ===" << endl << endl;
    
    cout << "Vehicle Types : " << endl << endl;
    cout << "1. Motorcycle (Rp 2000/hour)" << endl << endl;
    cout << "2. Car (Rp 5000/hour)" << endl << endl;
    cout << "3. Truck (Rp 10000/hour)" << endl << endl;
    
    cout << "Choose vehicle type (1-3) : ";
    cin >> choose;
    cout << endl;
    
    cout << "Parking duration (hours) : ";
    cin >> duration;
    cout << endl;
    
    // If user is a member, users get a discount 20 %. 
    cout << "Are you a member? (Y/N) : ";
    cin >> member;
    cout << endl << endl << endl;
    
    cout << "=== PAYMENT DETAILS ===" << endl << endl;
    
    cout << "Vehicle Type : ";
    cin >> vehiclesType;
    cout << endl;
    
    cout << "Duration : ";
    cin >> duration;
    cout << endl;
    
    cout << "Base Price : ";
    cin >> basePrice;
    cout << endl;
    
    cout << "After first hour : ";
    cin >> afterFirstHour;
    cout << endl;
    
    switch (choose) {
		case 1 : 
			vehiclesType = "Motorcycle";
			basePrice = 2000;
			afterFirstHour = 4000; // prices go up after the first hour //
			break;
			
		case 2 : 
			vehiclesType = "Car";
			basePrice = 5000;
			afterFirstHour = 7000;
			break;
			
		case 3 :
			vehiclesType = "Truck";
			basePrice = 10000;
			afterFirstHour = 12000;
			break;
			
		default : 
			cout << "Data Invalid";
			return (0);
	}
    
    // Counting a subtotal //
    int subtotal = 0;
    if (duration > 0) {
		subtotal = basePrice; // The first hour //
		if (duration > 1) {
			subtotal += (duration - 1) * afterFirstHour;
			}
		}
		cout << endl;
		
	// Counting if user are member //
	int discount = 0;
	if (member == 'Y' || member == 'y') {
		discount = subtotal * 20 / 100;
		}
		
	int total = subtotal - discount;
	
	// Show details //
	cout << "=== PAYMENT DETAILS ===" << endl << endl << endl;
	cout << "Vehicle Type : " << vehiclesType << endl << endl;
	cout << "Duration : " << duration << " hours" << endl << endl;
	cout << "Base Price : Rp " << basePrice << "/hour" << endl << endl;
	cout << "After first hour : Rp " << afterFirstHour << "/hour" << endl << endl;
	cout << "Subtotal : Rp " << subtotal << endl << endl;
	if (discount > 0) {
			cout << "Member discount (20%)" << endl << endl;
		}
	cout << "TOTAL : Rp " << total << endl << endl;
	return (0);
}
