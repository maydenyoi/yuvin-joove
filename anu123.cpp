#include <iostream>
#include <string>
using namespace std;

int main () {
    string usrnm;
    string username = "admin";
    string pw;
    string password = "020";
    string seatType;
    int chance = 3;
    int cusMenu, cusTicket, numTicket, price, purchase, disc, subTotal, rebate, totalPayment, totalTicket, totalTransaction;
    subTotal = 0;
    disc = 0;
    price = 0;
    totalTicket = 0;
    totalTransaction = 0;

    cout << "===========" << endl;
    cout << "SYSTEM ..." << endl;
    cout << "===========" << endl;

    while (chance >= 1) {
        cout << "---Loginkan dulu le---" << endl;
        cout << "Username : "; cin >> usrnm;
        cout << "Password : "; cin >> pw;

        if (usrnm == username && pw == password) {
            cout << "Login berhasil le" << endl;
            break;
        } else {
            chance--;
            if (chance >= 1) {
                cout << "Incorrect username or password!" << endl;
                cout << "Chances remaining : " << chance << endl << endl;
            } else {
                cout << "Incorrect username or password!" << endl;
                cout << "Chances remaining : " << chance << endl;
                cout << "Program telah keluar le" << endl;
                return (0);
            }
        }

    }
     do {
        cout << "Main Menu" << endl;
        cout << "1. Buy Ticket" << endl;
        cout << "2. Transaction Summary" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose Menu (1-3) : "; cin >> cusMenu;
        cout << endl;

        if (cusMenu == 1) {
            cout << "Ticket Price List" << endl;
            cout << "1. Reguler : Rp 10.000" << endl;
            cout << "2. Deluks : Rp 15.0000" << endl;
            cout << "3. Premium : Rp 25.000" << endl;
            cout << "4. VIP : Rp 35.000" << endl;
            cout << "Choose Ticket Type : "; cin >> cusTicket;
            cout << "Number of Ticket to Buy : "; cin >> numTicket;

            if (cusTicket == 1)
                price = 10000;
            else if (cusTicket == 2)
                price = 15000;
            else if (cusTicket == 3)
                price = 25000;
            else if (cusTicket == 4)
                price = 35000;
            else {
                return (0);

            }
            purchase = price * numTicket;
            if (numTicket >= 5) disc = 10;
            else if (numTicket >= 10) disc = 20;
            if (cusTicket == 4 && numTicket >= 3) disc +=5;
            rebate = purchase * disc / 100;
            totalPayment = purchase-rebate;

            cout << "Purchase Details" << endl;
            if (cusTicket == 1)
                seatType = "Reguler";
            else if (cusTicket == 2)
                seatType = "Deluks";
            else if (cusTicket == 3)
                seatType = "Premium";
            else if (cusTicket == 4)
                seatType = "VIP";

            cout << "Seat Type : " << seatType << endl;
            cout << "Ticket Quantity : " << numTicket << endl;
            cout << "Unit Price : Rp " << price << endl;
            cout << "Subtotal : Rp " << purchase << endl;
            cout << "Discount (" << disc << "%) : Rp " << rebate << endl;
            cout << "Total Price : Rp " << totalPayment << endl;
            cout << "Transaction Saved!" << endl << endl;
            subTotal += totalPayment;
            totalTicket += numTicket;
            totalTransaction += 1;
        } else if (cusMenu == 2) {
            cout << "Transaction Summary " << endl;
            cout << "Total Tickets : " <<  totalTicket << endl;
            cout << "Total Transacton : " <<  totalTransaction << endl;
            cout << "Total Purchase : " <<  subTotal << endl << endl;
        } else if (cusMenu == 3){
            cout << "Thank you le" << endl;
            return 0;
        } else {
            cout << "There is nothing here le << endl";
        }
    } while (true);
}