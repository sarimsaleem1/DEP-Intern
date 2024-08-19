#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void compressFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName, ios::in);
    ofstream outputFile(outputFileName, ios::out);

    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return;
    }
    if (!outputFile) {
        cerr << "Error creating output file!" << endl;
        return;
    }

    char currentChar, previousChar;
    int count = 1;

    inputFile.get(previousChar);

    while (inputFile.get(currentChar)) {
        if (currentChar == previousChar) {
            count++;
        } else {
            outputFile << count << previousChar;
            count = 1;
        }
        previousChar = currentChar;
    }

    outputFile << count << previousChar;

    inputFile.close();
    outputFile.close();

    cout << "Compression completed. Compressed data saved in: " << outputFileName << endl;
}


void decompressFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName, ios::in);
    ofstream outputFile(outputFileName, ios::out);

    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return;
    }
    if (!outputFile) {
        cerr << "Error creating output file!" << endl;
        return;
    }

    char ch;
    int count;

    while (inputFile >> count >> ch) {
        for (int i = 0; i < count; ++i) {
            outputFile << ch;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Decompression completed. Decompressed data saved in: " << outputFileName << endl;
}

int main() {
    string inputFileName = "input.txt";
    string compressedFileName = "compressed.txt";
    string decompressedFileName = "decompressed.txt";


    compressFile(inputFileName, compressedFileName);

   
    decompressFile(compressedFileName, decompressedFileName);

    return 0;
}
