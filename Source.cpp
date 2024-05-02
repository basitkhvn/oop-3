/*
Name: Abdul Basit
Roll No : 23I-0820
Section : F
Instructor : Marium Hida
TA name : Ariyan Choudhary
*/

#include <iostream>
#include "Header.h"


using namespace std;

int main() {

    char c;
    do {
        cout << "Choose Computer Type:\n";
        cout << "1. PC\n";
        cout << "2. MAC\n";
        cout << "Enter your choice (1/2): ";
        cin >> c;

        if (c == '1') {
            PC pc;
            pc.getComputerSpecs();
          // Assuming total price of PC
            pc.displayComputerSpecsAndPrice();
        }
        else if (c == '2') {
            MAC mac;
            mac.getComputerSpecs();
            // Assuming total price of MAC
            mac.displayComputerSpecsAndPrice();
        }
        else {
            cout << "Invalid choice! Please enter either 1 or 2.\n";
        }

        cout << "Do you want to create another computer? (Y/N): ";
        cin >> c;
    } while (toupper(c) == 'Y');


	return 0;
}