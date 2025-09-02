#include <iostream>
#include <sstream>  
#include <cmath>     
using namespace std;

#define MAX 1000

class Stack {
private:
    long long arr[MAX];  
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(long long value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    long long pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    long long peek() {
        if (isEmpty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[top];
    }

    // Evaluate postfix expression (with spaces, multi-digit, negatives)
    long long evaluate(string s) {
        stringstream ss(s);
        string token;

        while (ss >> token) {
            // If token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                long long a = pop();
                long long b = pop();

                if (token == "+") push(b + a);
                else if (token == "-") push(b - a);
                else if (token == "*") push(b * a);
                else if (token == "/") {
                   
                    if (a == 0) {
                        cout << "Division by zero error!\n";
                        return 0;
                    }
                    push(b / a);
                }
                else if (token == "^") push(pow(b, a));
            }
            else {
                // Token is a number (can be negative or multi-digit)
                long long num = stoll(token);
                push(num);
            }
        }
        return pop(); // final result
    }
};

int main() {
    Stack s;
    string expression;

    cout << "Enter postfix expression: ";
    getline(cin, expression);

    cout << "Result = " << s.evaluate(expression) << endl;

    return 0;
}
