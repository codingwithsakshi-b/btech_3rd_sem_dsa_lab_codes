#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int precedence(char operation) {
    switch (operation) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

bool isOperator(char character) {
    return character == '+' || character == '-' || character == '*' ||
           character == '/' || character == '^';
}

bool convertToPostfix(const string& expression, vector<string>& postfix,
                      string& error) {
    stack<char> operators;
    bool expectingOperand = true;

    for (size_t i = 0; i < expression.size();) {
        if (isspace(static_cast<unsigned char>(expression[i]))) {
            ++i;
            continue;
        }

        if (isalnum(static_cast<unsigned char>(expression[i])) ||
            expression[i] == '_') {
            if (!expectingOperand) {
                error = "Missing operator between operands.";
                return false;
            }

            size_t start = i;
            while (i < expression.size() &&
                   (isalnum(static_cast<unsigned char>(expression[i])) ||
                    expression[i] == '_')) {
                ++i;
            }
            postfix.push_back(expression.substr(start, i - start));
            expectingOperand = false;
            continue;
        }

        char character = expression[i];
        if (character == '(') {
            if (!expectingOperand) {
                error = "Missing operator before '('.";
                return false;
            }
            operators.push(character);
            ++i;
        } else if (character == ')') {
            if (expectingOperand) {
                error = "Missing operand before ')'.";
                return false;
            }

            while (!operators.empty() && operators.top() != '(') {
                postfix.push_back(string(1, operators.top()));
                operators.pop();
            }
            if (operators.empty()) {
                error = "Mismatched parentheses.";
                return false;
            }
            operators.pop();
            ++i;
            expectingOperand = false;
        } else if (isOperator(character)) {
            if (expectingOperand) {
                error = "Missing operand before operator.";
                return false;
            }

            while (!operators.empty() && operators.top() != '(' &&
                   (precedence(operators.top()) > precedence(character) ||
                    (precedence(operators.top()) == precedence(character) &&
                     character != '^'))) {
                postfix.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.push(character);
            ++i;
            expectingOperand = true;
        } else {
            error = string("Invalid character: ") + character;
            return false;
        }
    }

    if (postfix.empty()) {
        error = "Expression is empty.";
        return false;
    }
    if (expectingOperand) {
        error = "Expression ends with an operator or an opening parenthesis.";
        return false;
    }

    while (!operators.empty()) {
        if (operators.top() == '(') {
            error = "Mismatched parentheses.";
            return false;
        }
        postfix.push_back(string(1, operators.top()));
        operators.pop();
    }

    return true;
}

int main() {
    string expression;
    vector<string> postfix;
    string error;

    cout << "Enter an infix expression: ";
    getline(cin, expression);

    if (!convertToPostfix(expression, postfix, error)) {
        cout << "Error: " << error << endl;
        return 1;
    }

    cout << "Postfix expression: ";
    for (size_t i = 0; i < postfix.size(); ++i) {
        if (i > 0)
            cout << " ";
        cout << postfix[i];
    }
    cout << endl;

    return 0;
}
