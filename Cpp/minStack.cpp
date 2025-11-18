#include<iostream>  // For input/output operations
#include<climits>   // For INT_MIN constant
using namespace std;

class MinStack {
private:
    int mainStack[1000];  // Array to store actual stack elements
    int minStack[1000];   // Array to store minimum element at each level
    int top;              // Index pointing to top element (-1 means empty)

public:
    // Constructor: Initialize empty stack
    MinStack() {
        top = -1;  // -1 indicates stack is empty
    }

    // Push operation: Add element to stack - O(1)
    void push(int x) {
        // Check if stack is full (top index is 999)
        if (top == 999) {
            cout << "Stack Overflow" << endl;
            return;  // Cannot push more elements
        }

        // Increment top first, then insert element into main stack
        mainStack[++top] = x;

        // Handle min stack
        if (top == 0) {
            // First element: it's the minimum by default
            minStack[top] = x;
        } else {
            // Compare new element with previous minimum
            if (x < minStack[top - 1]) {
                // New element is smaller, so it becomes new minimum
                minStack[top] = x;
            } else {
                // Previous minimum is still smaller, keep it
                minStack[top] = minStack[top - 1];
            }
        }
    }

    // Pop operation: Remove top element - O(1)
    void pop() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;  // Nothing to pop
        }
        // Decrement top (removes from both mainStack and minStack)
        top--;
    }

    // Peek operation: Return top element without removing - O(1)
    int peek() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return INT_MIN;  // Return smallest int as error indicator
        }
        // Return element at top index from main stack
        return mainStack[top];
    }

    // GetMin operation: Return minimum element in stack - O(1)
    int getMin() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return INT_MIN;  // Return smallest int as error indicator
        }
        // Return element at top of min stack (always contains current minimum)
        return minStack[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;  // True if top is -1, false otherwise
    }

    // Display both stacks for visualization
    void display() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        // Print all elements in main stack from bottom to top
        cout << "Main Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << mainStack[i] << " ";
        }
        // Print all elements in min stack from bottom to top
        cout << "\nMin Stack:  ";
        for (int i = 0; i <= top; i++) {
            cout << minStack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create a MinStack object
    MinStack s;

    cout << "=== MinStack Demo ===" << endl << endl;

    // Test 1: Push 5 (first element, becomes minimum)
    cout << "Push 5:" << endl;
    s.push(5);
    s.display();  // Shows both stacks
    cout << "Current Min: " << s.getMin() << endl << endl;

    // Test 2: Push 3 (smaller than 5, becomes new minimum)
    cout << "Push 3:" << endl;
    s.push(3);
    s.display();
    cout << "Current Min: " << s.getMin() << endl << endl;

    // Test 3: Push 7 (larger than 3, minimum stays 3)
    cout << "Push 7:" << endl;
    s.push(7);
    s.display();
    cout << "Current Min: " << s.getMin() << endl << endl;

    // Test 4: Push 2 (smaller than 3, becomes new minimum)
    cout << "Push 2:" << endl;
    s.push(2);
    s.display();
    cout << "Current Min: " << s.getMin() << endl << endl;

    // Test 5: Push 4 (larger than 2, minimum stays 2)
    cout << "Push 4:" << endl;
    s.push(4);
    s.display();
    cout << "Current Min: " << s.getMin() << endl << endl;

    // Test 6: Pop (removes 4, minimum goes back to 2)
    cout << "Pop:" << endl;
    s.pop();
    s.display();
    cout << "Current Min: " << s.getMin() << endl << endl;

    // Test 7: Pop (removes 2, minimum goes back to 3)
    cout << "Pop:" << endl;
    s.pop();
    s.display();
    cout << "Current Min: " << s.getMin() << endl << endl;

    // Test 8: Peek at top element and check minimum
    cout << "Peek: " << s.peek() << endl;
    cout << "Current Min: " << s.getMin() << endl;

    return 0;  // Program ends successfully
}
