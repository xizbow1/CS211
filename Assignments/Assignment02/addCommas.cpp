#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void addCommas(unsigned long long int input){
    if (input < 1000){
        cout << input;
    } else {
        addCommas(input / 1000);
        cout << "," << setfill('0') << setw(3) << input % 1000; // Iomanip prevents 0's that are the first digit in a set of 3 from being omitted
    }
}