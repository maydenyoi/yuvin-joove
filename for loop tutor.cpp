#include <iostream>
using namespace std;

int main () {
int count, counter;
	cout << "How many repetition? "; cin >> count;
	cout << "Countdown begin...\n";
	for (counter=count; counter > 0; counter--) {
		cout << "Printing : " << counter << endl;
	}
	
	if (count <= 0) {
		cout << "There is no repetition..." << endl;
	}
	else {
		cout << "Finished countdown..." << endl;
		cout << "Last counter : " << counter << endl;
	}
	return (0);
}
