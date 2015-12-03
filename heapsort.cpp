
//
// Zübeyr Furkan Eryilmaz
// 21202676
// CS 202 - 01
// Assignment 3
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "heap.h"

using namespace std;

int main(int argc, char** argv) {

   if (argc == 3) {

        int numberOfElements = 0;

        ifstream inputFile;
        inputFile.open(argv[1]);

        //Calculates number of elemets
        string number;
        while (inputFile >> number) { // -> O(n)
            numberOfElements++;
        }

        //Creates a heap whose size is equal to number of elements in the file
        heap maxHeap(numberOfElements);

        //Turns beginning of the file
        inputFile.clear();
        inputFile.seekg(0);

        //Inserts each numbers in the file to the heap
        while (inputFile >> number) { // O(n)
            maxHeap.insert(atoi(number.c_str())); // O(logn)
        } // O(nlogn)

        inputFile.close();

        ofstream outputFile;
        outputFile.open(argv[2]);

        // Prints number of elements and number of comparisons
        cout << "n = " << numberOfElements << ", Number of comparisons = " << maxHeap.getComparisons() << endl;

        // Writes the numbers in the input file in descending order to specified file
        for (int i = 0; i < numberOfElements; i++) { // O(n)
            outputFile << maxHeap.popMaximum() << "\n"; // O(logn)
        } // O(nlogn)

        outputFile.close();

    }

    else
    {
    	cout << "Input number mismatch" << endl;
    }

    return 0;
}
