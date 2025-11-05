#include <iostream>
using namespace std;

// Node structure for linked list
class Node {
public:
    int data;        // Data stored in node
    Node* next;      // Pointer to next node

    // Constructor to create new node
    Node(int val) {
        data = val;
        next = nullptr;  // Initially points to nothing
    }
};

class QueueLL {
private:
    Node* front;     // Pointer to front node
    Node* rear;      // Pointer to rear node
    int size;        // Number of elements in queue

public:
    // Constructor: Initialize empty queue
    QueueLL() {
        front = nullptr;   // No front node yet
        rear = nullptr;    // No rear node yet
        size = 0;          // Empty queue
    }

    // Add element at rear
    void enqueue(int x) {
        // Step 1: Create new node with data x
        Node* newNode = new Node(x);

        // Step 2: Check if queue is empty
        if (rear == nullptr) {
            // First element: both front and rear point to new node
            front = rear = newNode;
        }
        else {
            // Step 3: Link current rear to new node
            rear->next = newNode;

            // Step 4: Move rear to new node
            rear = newNode;
        }

        size++;  // Increment size
        cout << x << " enqueued to queue" << endl;
    }

    // Remove element from front
    void dequeue() {
        // Check if queue is empty
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }

        // Step 1: Store front node temporarily
        Node* temp = front;

        cout << temp->data << " dequeued from queue" << endl;

        // Step 2: Move front to next node
        front = front->next;

        // Step 3: If front becomes null, rear should also be null
        if (front == nullptr) {
            rear = nullptr;  // Queue is now empty
        }

        // Step 4: Delete the old front node
        delete temp;

        size--;  // Decrement size
    }

    // Get front element without removing
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;  // Return data of front node
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return rear->data;   // Return data of rear node
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;  // If front is null, queue is empty
    }

    // Get current size
    int getSize() {
        return size;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;  // Start from front

        // Traverse the linked list
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;  // Move to next node
        }
        cout << endl;
    }

    // Destructor: Free all nodes
    ~QueueLL() {
        // Remove all elements one by one
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    cout << "=== Queue using Linked List Demo ===" << endl << endl;

    // Create an empty queue
    QueueLL q;

    // Add elements (no size limit!)
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << endl;

    // Display queue
    q.display();

    cout << endl;

    // Get front and rear
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Size: " << q.getSize() << endl;

    cout << endl;

    // Remove some elements
    cout << "Removing 2 elements..." << endl;
    q.dequeue();
    q.dequeue();

    cout << endl;

    // Display after removal
    q.display();
    cout << "Size: " << q.getSize() << endl;

    cout << endl;

    // Add more elements (queue grows dynamically)
    cout << "Adding more elements..." << endl;
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);

    cout << endl;

    // Display final queue
    q.display();
    cout << "Size: " << q.getSize() << endl;

    cout << endl;

    // Remove all elements
    cout << "Removing all elements..." << endl;
    while (!q.isEmpty()) {
        q.dequeue();
    }

    cout << endl;

    // Try to dequeue from empty queue
    q.dequeue();

    return 0;
}