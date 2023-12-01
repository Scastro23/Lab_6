// Samuel Castro
// Lab 6
// FA2023
/* Description: Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns with
appropriate headings.*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function to read binary string
bool readBinary(string line, int& val) {
    // Ignore the blanks indicated by '_'
    int pos = 0;
    while (pos < line.size() && line[pos] == '_') {
        pos++;
    }

    // Reading binary digits
    while (pos < line.size()) {
        // Check for correct binary input ('0' or '1')
        if (line[pos] == '1' || line[pos] == '0') {
            // Conversion of binary to decimal
            val = val * 2 + (line[pos] - '0');
        }
        else {
            // Return false any other character is found
            return false;
        }
        pos++;
    }
    return true; // Return true for valid binary
}

int main() {
    // Read from file
    ifstream infile("BinaryIn.dat");

    // Print header
    cout << setw(20) << "Binary Number" << setw(30) << "Decimal Equivalent" << endl;

    // Read line by line until end of file
    string input;
    while (infile >> input) {
        int val = 0;
        if (readBinary(input, val)) {
            // Output valid binary number and its decimal equivalent
            cout << setw(20) << input << setw(30) << val << endl;
        }
        else {
            // Output message for bad input and placeholder for decimal value
            cout << setw(20) << "Bad digit on input" << setw(30) << "__" << endl;
        }
    }
}
