//
// Created by mathy on 11.10.2024.
//

#ifndef BINOPSTRUCTS_HPP
#define BINOPSTRUCTS_HPP



#endif //BINOPSTRUCTS_HPP
#include <vector>
using namespace std;

struct BinOp {
    float opan1, opan2, result;
    char op;
};

BinOp* evaluate() {
    BinOp *op = new BinOp();
    string input;

    cout << "Enter operation in format (10 * 2): ";
    getline(cin, input);

    stringstream ss(input);
    ss >> op->opan1 >> op->op >> op->opan2;

    switch (op->op) {
        case '+':
            op->result = op->opan1 + op->opan2;
        break;
        case '-':
            op->result = op->opan1 - op->opan2;
        break;
        case '*':
            op->result = op->opan1 * op->opan2;
        break;
        case '/':
            op->result = op->opan1 / op->opan2;
        break;
        default:
            cout << "Error: Unknown operator" << endl;
        op->result = 0;
        break;
    }

    return op;
}

void performBinOp() {
    char choice = 'y';
    vector<BinOp*> ops;

    while (choice == 'y' || choice == 'Y') {
        ops.push_back(evaluate());

        cout << "Do you want to continue ? (y / n)";
        cin >> choice;
        cin.ignore();
    }

    // print result to console
    for (int i = 0; i < ops.size(); ++i) {
        cout << ops[i]->opan1 << " " << ops[i]->op << " " << ops[i]->opan2
             << " -> " << ops[i]->result << endl;
    }

    // Deallocate memmory
    for (int i = 0; i < ops.size(); ++i) {
        delete ops[i];
    }
}