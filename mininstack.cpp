#include <iostream>
#include <stack>
#include <utility>   // For std::pair
#include <algorithm> // For std::min

using namespace std;

class MinStack {
private:
    // The stack stores pairs of {value, current_minimum}
    stack<pair<int, int>> st;

public:
    MinStack() {
        // Constructor
    }
    
    // Pushes a value onto the stack
    void push(int val) {
        if (st.empty()) {
            // If the stack is empty, the value is its own minimum
            st.push({val, val});
        } else {
            // The new minimum is the smaller of the new value and the current minimum
            int current_min = st.top().second;
            st.push({val, min(val, current_min)});
        }
    }
    
    // Removes the top element from the stack
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    // Returns the top element of the stack
    int top() {
        if (!st.empty()) {
            return st.top().first;
        }
        // Return a default value if the stack is empty
        return -1; 
    }
    
    // Returns the minimum element in the stack
    int getMin() {
        if (!st.empty()) {
            return st.top().second;
        }
        // Return a default value if the stack is empty
        return -1; 
    }
};

// Main function to demonstrate the MinStack
int main() {
    MinStack minStack;

    cout << "Pushing 5..." << endl;
    minStack.push(5);
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl; // Top: 5, Min: 5

    cout << "\nPushing 2..." << endl;
    minStack.push(2);
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl; // Top: 2, Min: 2

    cout << "\nPushing 7..." << endl;
    minStack.push(7);
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl; // Top: 7, Min: 2

    cout << "\nPushing 1..." << endl;
    minStack.push(1);
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl; // Top: 1, Min: 1
    
    cout << "\nPopping..." << endl;
    minStack.pop();
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl; // Top: 7, Min: 2

    cout << "\nPopping..." << endl;
    minStack.pop();
    cout << "Top: " << minStack.top() << ", Min: " << minStack.getMin() << endl; // Top: 2, Min: 2

    return 0;
}