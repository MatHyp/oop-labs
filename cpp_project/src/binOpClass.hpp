//
// Created by mateuszkubuntu on 09/10/2024.
//

#ifndef BINOPCLASS_HPP
#define BINOPCLASS_HPP
using namespace std;

class BinOpClass {
    public:
    BinOpClass() {
        cout << "Enter operation in format (10 * 2): ";

        if (!(cin >> this->opan1 >> this->op >> this->opan2)) {
            throw runtime_error("Invalid input! Please enter numbers and an operator.");
        }
    };

    void evaluate() {
        switch (this->op) {
            case '+':
                this->result = this->opan1 + this->opan2;
            break;
            case '-':
                this->result = this->opan1 - this->opan2;
            break;
            case '*':
                this->result = this->opan1 * this->opan2;
            break;
            case '/':
                this->result = this->opan1 / this->opan2;
            break;
            default:
                cout << "Error: Unknown operator" << endl;
                this->result = 0;
            break;
        }
    };

    char getOp() {
        return op;
    }

    float getOpen1() {
        return opan1;
    }

    float getOpen2() {
        return opan2;
    }
    float getResult() {
        return result;
    }


    private:
        float opan1, opan2, result;
        char op;
};

#endif //BINOPCLASS_HPP