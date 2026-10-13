#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool evaluatePostfix(const string& expression, int& result, string& error) {
    vector<string> tokens;

    if (expression.find_first_of(" \t\n\r") != string::npos) {
        istringstream input(expression);
        string token;
        while (input >> token)
            tokens.push_back(token);
    } else {
        for (char character : expression)
            tokens.push_back(string(1, character));
    }

    stack<int> operands;

    for (const string& token : tokens) {
        istringstream tokenInput(token);
        int value;
        char extraCharacter;

        if ((tokenInput >> value) && !(tokenInput >> extraCharacter)) {
            operands.push(value);
            continue;
        }

        if (token.size() != 1 ||
            (token[0] != '+' && token[0] != '-' &&
             token[0] != '*' && token[0] != '/')) {
            error = "Invalid token: " + token;
            return false;
        }

        if (operands.size() < 2) {
            error = "Invalid postfix expression: not enough operands.";
            return false;
        }

        int rightOperand = operands.top();
        operands.pop();
        int leftOperand = operands.top();
        operands.pop();

        switch (token[0]) {
            case '+':
                operands.push(leftOperand + rightOperand);
                break;
            case '-':
                operands.push(leftOperand - rightOperand);
                break;
            case '*':
                operands.push(leftOperand * rightOperand);
                break;
            case '/':
                if (rightOperand == 0) {
                    error = "Division by zero.";
                    return false;
                }
                operands.push(leftOperand / rightOperand);
                break;
        }
    }

    if (operands.size() != 1) {
        error = "Invalid postfix expression: operands remain without an operator.";
        return false;
    }

    result = operands.top();
    return true;
}

int main() {
    string expression;
    int result;
    string error;

    cout << "Enter a postfix expression: ";
    getline(cin, expression);

    if (evaluatePostfix(expression, result, error))
        cout << "Result: " << result << endl;
    else
        cout << "Error: " << error << endl;

    return 0;
}
