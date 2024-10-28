#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "src/binOpClass.hpp"
#include "src/binOpStructs.hpp"

#include "src/Item.h"
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

void runClass() {
    std::vector<Item*> shopping_list;

    // Example of adding items to the shopping list
    shopping_list.push_back(new Grocery("Apple", 1.99, 1.5));
    shopping_list.push_back(new Electronics("Laptop", 999.99, 2));
    shopping_list.push_back(new Clothing("T-shirt", 19.99, "L"));

    // Display all items
    std::cout << "Shopping List:" << std::endl;
    for (const auto& item : shopping_list) {
        item->display();
        std::cout << std::endl;
    }

    // Persist the shopping list to a file
    std::ofstream out("shopping_list.txt");
    for (const auto& item : shopping_list) {
        item->persist(out);
    }
    out.close();

    // Cleanup memory
    for (auto& item : shopping_list) {
        delete item;
    }
    shopping_list.clear();

    // Restore items from file
    std::ifstream in("shopping_list.txt");
    while (in) {
        Item* item = Item::restore(in);
        if (item) {
            shopping_list.push_back(item);
        }
    }
    in.close();

    // Display restored items
    std::cout << "Restored Shopping List:" << std::endl;
    for (const auto& item : shopping_list) {
        item->display();
        std::cout << std::endl;
    }

    // Cleanup memory after restoring
    for (auto& item : shopping_list) {
        delete item;
    }

};

int main() {
    runClass();


    //
    // // binOm based in structs
    // performBinOp();
    //
    // vector<BinOpClass*> binVector = prerformBinom();
    // // Print to console every expression
    // std::ofstream outputFile("output.txt");
    //
    // if (outputFile.is_open()) {
    //     for (int i = 0; i < binVector.size(); ++i) {
    //         cout << binVector[i]->getOpen1() << " " << binVector[i]->getOp() << " " << binVector[i]->getOpen2() << " -> " << binVector[i]->getResult() << endl;
    //         outputFile << binVector[i]->getOpen1() << " "
    //                     << binVector[i]->getOp() << " "
    //                     << binVector[i]->getOpen2() << " -> "
    //                     << binVector[i]->getResult() << std::endl;
    //     }
    // } else {
    //     std::cerr << "Cannot open a file" << std::endl;
    // }
    //
    // // free memory from heap
    // for (int i = 0; i < binVector.size(); ++i) {
    //     delete binVector[i];
    // }

    return 0;
}