#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int n) {
        capacity = n;
        arr = new int[n];
        top = -1;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Error: Stack is full" << endl;
            return;
        }

        arr[++top] = value;
        cout << "Top tray: " << arr[top] << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Error: Stack is empty" << endl;
            return;
        }

        top--;

        if (top == -1)
            cout << "Stack is empty" << endl;
        else
            cout << "Top tray: " << arr[top] << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;

    Stack stack(n);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}

