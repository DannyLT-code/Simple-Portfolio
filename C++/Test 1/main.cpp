#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Specify the name of the text file you want to read.
    string fileName = "example.txt";

    // Create an input file stream.
    ifstream inputFile(fileName);

    // Check if the file can be opened successfully.
    if (!inputFile.is_open()) {
        cerr << "Error opening the file: " << fileName << endl;
        return 1; // Exit with an error code.
    }

    string line;

    // Read and print each line of the file.
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // Close the file.
    inputFile.close();

    return 0; // Exit without errors.
}
