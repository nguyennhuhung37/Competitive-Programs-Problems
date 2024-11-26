#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

// Hàm kiểm tra xem ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Hàm chuyển đổi biểu thức từ hậu tố sang trung tố
string postfixToInfix(const string &expression) {
    stack<string> s;

    for (char c : expression) {
        if (isspace(c)) {
            continue;
        } else if (isdigit(c)) {
            string operand(1, c);
            s.push(operand);
        } else if (isOperator(c)) {
            if (s.size() < 2) {
                throw invalid_argument("Invalid postfix expression");
            }
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string infix = "(" + op1 + " " + c + " " + op2 + ")";
            s.push(infix);
        } else {
            throw invalid_argument("Invalid character in expression");
        }
    }

    if (s.size() != 1) {
        throw invalid_argument("Invalid postfix expression");
    }

    return s.top();
}

int main() {
    string expression;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);

    try {
        string infix = postfixToInfix(expression);
        cout << "Infix expression: " << infix << endl;
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
