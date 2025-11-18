// Generate Binary Numbers from 1 to N using Queue
#include <iostream>
#include <string>
using namespace std;

// Simple Queue class to store strings
class Queue {
private:
    string* arr;     // Array to store queue elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int capacity;    // Maximum capacity of the queue
    int count;       // Current number of elements in the queue

public:
    // Constructor: Initialize the queue with given size
    Queue(int size) {
        capacity = size;           // Set the maximum capacity
        arr = new string[capacity]; // Allocate memory for string array
        front = 0;                 // Initialize front to 0
        rear = -1;                 // Initialize rear to -1 (empty queue)
        count = 0;                 // Initialize count to 0 (no elements)
    }

    // Destructor: Free the allocated memory
    ~Queue() {
        delete[] arr;  // Delete the dynamically allocated array
    }

    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;  // Queue is empty if count is 0
    }

    // Check if the queue is full
    bool isFull() {
        return count == capacity;  // Queue is full if count equals capacity
    }

    // Get the current size of the queue
    int size() {
        return count;  // Return the number of elements in the queue
    }

    // Add an element to the rear of the queue
    void enqueue(string value) {
        // Check if the queue is full
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;  // Exit if queue is full
        }

        // Move rear to the next position
        rear = (rear + 1) % capacity;

        // Insert the value at the rear position
        arr[rear] = value;

        // Increment the count of elements
        count++;
    }

    // Remove and return the front element from the queue
    string dequeue() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return "";  // Return empty string if queue is empty
        }

        // Get the value at the front position
        string value = arr[front];

        // Move front to the next position
        front = (front + 1) % capacity;

        // Decrement the count of elements
        count--;

        // Return the dequeued value
        return value;
    }
};

// Function to generate and print first n binary numbers
void generateBinaryNumbers(int n) {
    // Create a queue with capacity of 2*n (enough space for all operations)
    Queue queue(2 * n);

    // Step 1: Start by enqueuing the first binary number "1"
    queue.enqueue("1");

    // Step 2: Loop n times to generate n binary numbers
    for (int i = 0; i < n; i++) {

        // Step 3a: Dequeue the front element (current binary number)
        string current = queue.dequeue();

        // Step 3b: Print the current binary number
        cout << current << endl;

        // Step 3c: Append "0" to current and enqueue it
        string next0 = current + "0";  // Create next binary by adding "0"
        queue.enqueue(next0);          // Add to queue for future use

        // Step 3d: Append "1" to current and enqueue it
        string next1 = current + "1";  // Create next binary by adding "1"
        queue.enqueue(next1);          // Add to queue for future use
    }
}

// Main function to test the binary number generator
int main() {
    int n;  // Variable to store how many binary numbers to generate

    // Get input from user
    cout << "Enter how many binary numbers to generate: ";
    cin >> n;  // Read the value of n

    // Print header
    cout << "\nFirst " << n << " binary numbers:" << endl;

    // Generate and print the binary numbers
    generateBinaryNumbers(n);

    return 0;  // End of program
}