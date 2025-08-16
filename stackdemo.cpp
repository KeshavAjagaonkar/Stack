#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of the stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // Push operation
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed onto stack.\n";
        }
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Nothing to pop.\n";
        } else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    // Display stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n==== Stack Menu ====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
