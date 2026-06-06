#include <iostream>
using namespace std;

int main () {
    int count, counter;
cout << "How many repetition ? ";
cin >> count;
counter = count;
cout << "Countdown begin ...\n" << endl;
do {
cout << "Printing : " << counter << endl;
counter--;
} while(counter > 0);
cout << endl;
if(count <= 0)
{
cout << "Executed at least once...";
cout << "The condition is false...";
cout << endl;
}
else
{
cout << "Finished countdwon..." << endl;
cout << "Last counter : " << counter;
cout << endl;
}
return 0;
}