#include <iostream>
#include <string>
using namespace std;

// Function to get the length of a name
int nameLength(string name) {
    return name.length();
}

// Function to check if two numbers are equal or different
bool numbersAreEqual(int x, int y) {
    return x == y;
}

// Function to check whether a number is even or odd
bool isEven(int num) {
    return num % 2 == 0;
}

// Function to find the average of two numbers
float average(int x, int y) {
    return (x + y) / 2.0f;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to create an identity matrix
void identityMatrix(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    string name;
    int x, y;

    cout << "Your name: ";
    getline(cin >> ws, name);

    cout << "Hello, " << name;
    cout << "\nThe length of your name is " << nameLength(name) << " characters.";

    cout << "\n\nEnter value for x: ";
    cin >> x;
    cout << "Enter value for y: ";
    cin >> y;

    if (numbersAreEqual(x, y)) {
        cout << "\n\nx and y are equal numbers.";
        cout << "\n\nHere is the identity matrix with height and width " << x << endl;
        identityMatrix(x);
    } else {
        cout << "\nx and y are different numbers.";

        if (isEven(x)) cout << "\n\nx is an even number.";
        else cout << "\n\nx is an odd number.";

        if (isEven(y)) cout << "\ny is an even number.";
        else cout << "\ny is an odd number.";

        cout << "\n\nThe average of x and y is " << average(x, y);
        cout << "\n\nx minus y is " << subtract(x, y);
        cout << "\ny minus x is " << subtract(y, x);
    }
}
