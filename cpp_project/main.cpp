#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "src/binOpClass.hpp"
#include "src/binOpStructs.hpp"

using namespace std;

// Returns vector of pointers to BinOpClass on the heap
vector<BinOpClass*> prerformBinom() {
    vector<BinOpClass*> vectorOfPointersToClass;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        BinOpClass *op = new BinOpClass();

        op->evaluate();
        vectorOfPointersToClass.push_back(op);

        cout << "Press y to add other opeartion: ";
        cin >> choice;
        cin.ignore();
    }

    return vectorOfPointersToClass;
};

int main() {

    // binOm based in structs
    // performBinOp();

    vector<BinOpClass*> binVector = prerformBinom();

    // Print to console every expression
    std::ofstream outputFile("output.txt");

    if (outputFile.is_open()) {
        for (int i = 0; i < binVector.size(); ++i) {
            cout << binVector[i]->getOpen1() << " " << binVector[i]->getOp() << " " << binVector[i]->getOpen2() << " -> " << binVector[i]->getResult() << endl;
            outputFile << binVector[i]->getOpen1() << " "
                        << binVector[i]->getOp() << " "
                        << binVector[i]->getOpen2() << " -> "
                        << binVector[i]->getResult() << std::endl;
        }
    } else {
        std::cerr << "Cannot open a file" << std::endl;
    }

    // free memory from heap
    for (int i = 0; i < binVector.size(); ++i) {
        delete binVector[i];
    }

    return 0;
}