#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

vector<string> infixToPostfix(const string &expression) {
    stack<char> operators;
    vector<string> postfix;
    string number;

    for (char c : expression) {
        if (isdigit(c) || c == '.') {
            number += c;
        } else {
            if (!number.empty()) {
                postfix.push_back(number);
                number.clear();
            }
            if (isOperator(c)) {
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    postfix.push_back(string(1, operators.top()));
                    operators.pop();
                }
                operators.push(c);
            } else if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfix.push_back(string(1, operators.top()));
                    operators.pop();
                }
                operators.pop(); // Pop '('
            }
        }
    }

    if (!number.empty()) {
        postfix.push_back(number);
    }

    while (!operators.empty()) {
        postfix.push_back(string(1, operators.top()));
        operators.pop();
    }

    return postfix;
}

void printPostfix(const vector<string> &postfix) {
    for (const string &token : postfix) {
        cout << token << " ";
    }
    cout << endl;
}

int main() {
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);

    vector<string> postfix = infixToPostfix(expression);
    cout << "Postfix expression: ";
    printPostfix(postfix);

    return 0;
}
