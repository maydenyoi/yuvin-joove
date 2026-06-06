#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int menu;
    string question;

    cout <<"=============================================="<<endl;
    cout <<"           PIGEONHOLE DEMONSTRATION"<<endl;
    cout <<"=============================================="<<endl;

    // Step 1: User enters question
    cout << "Enter your question: ";
    // getline(cin, question);
    cin >> question;

    // Step 2: Display formatted question
    cout << "\n---------\n";
    cout << "Pigeonhole\n";
    cout << "---------\n";
    cout << question << endl << endl;

    // Step 3: Menu loop
    while(true){
        cout <<"MENU"<<endl<<endl;
        cout <<"1. Learning Materials"<<endl;
        cout <<"2. Calculator"<<endl;
        cout <<"3. Exit"<<endl;
        cout <<"\nChoose menu (1-3): "; 
        cin >> menu;

        if(!(menu >= 1 || menu <= 3)){
            cout<<"Invalid input!\n";
            continue;
        }

        switch(menu){
            case(1):{ // LEARNING MATERIALS
                cout<<"\n=== LEARNING MATERIALS ===\n\n";
                cout << "🕊 Pigeonhole Principle\n\n";
                cout << "📘 Definition:\n";
                cout << "If there are more pigeons than holes to put them in,\n";
                cout << "then at least one hole must contain more than one pigeon.\n\n";
                cout << "📊 Example:\n";
                cout << "If there are 10 pigeons and only 9 holes,\n";
                cout << "then at least one hole must contain more than one pigeon.\n\n";
                cout << "💻 In Programming:\n";
                cout << "This principle can be used to calculate group distribution or detect duplication.\n";
                cout << "Pigeons = objects, Holes = containers.\n";
                cout << "It shows that some containers will inevitably have more items than others.\n\n";
                cout << "🧮 General Formula:\n";
                cout << "If there are n pigeons and m holes,\n";
                cout << "then at least one hole must contain ceil(n/m) pigeons.\n\n";
                cout << "🎓 Conclusion:\n";
                cout << "The Pigeonhole Principle helps us prove that repetition or overlap\n";
                cout << "is unavoidable when distributing a large number of items into fewer places.\n\n";
                break;
            }

            case(2):{ // CALCULATOR
                int n, m;
                cout << "\n=== PIGEONHOLE CALCULATOR ===\n";
                cout << "Enter number of pigeons: ";
                cin >> n;
                if(!(n > 0)){
                    cout<<"Invalid input!\n";
                    break;
                }

                cout << "Enter number of holes: ";
                cin >> m;
                if(!(m > 0)){
                    cout<<"Invalid input!\n";
                    break;
                }

                int min = floor(n / m);
                int remainder = n % m;

                cout << "\nResult for question: " << question << endl;
                cout << "-------------------------------------------\n";
                cout << "Minimum pigeons per hole: " << min << endl;

                if (remainder > 0) {
                    cout << remainder << " hole(s) contain " << min + 1 << " pigeons each.\n";
                } else {
                    cout << "No hole contains more than " << min << " pigeons.\n";
                }

                if(n >= m) {
                    if (remainder > 0 ) {
                        cout << "At least one hole has >= " << min + 1 << " pigeons.\n";
                    } else {
                        cout <<"No hole has more than " << min << " pigeons.\n";
                    }
                } else {
                    cout << "Not every hole is filled, so the pigeonhole principle does not apply.\n";
                }
                cout << endl;
                break;
            }

            default:{
                cout << "\nThank you for using the program!\n";
                return 0;
            }
        }
    }
}