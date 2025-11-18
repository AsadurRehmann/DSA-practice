#include<iostream>
using namespace std;

// ============================================================
// QUEUE WITH ARRAY - COMPLETE TUTORIAL
// ============================================================
// Queue is like a LINE at a ticket counter:
// - People join at the BACK (enqueue/rear)
// - People leave from the FRONT (dequeue/front)
// - First person in line gets served first
// This is called FIFO: First In, First Out
// ============================================================

class Queue {
private:
    int* arr;           // Dynamic array to store elements
    int capacity;       // Maximum size of queue
    int front;          // Index of front element
    int rear;           // Index of rear element
    int count;          // Current number of elements in queue

public:
    // ============================================================
    // CONSTRUCTOR: Initialize an empty queue
    // ============================================================
    Queue(int size = 10) {
        capacity = size;            // Set maximum capacity
        arr = new int[capacity];    // Allocate array memory
        front = 0;                  // Front starts at index 0
        rear = -1;                  // Rear at -1 means queue is empty
        count = 0;                  // No elements initially

        cout << "Queue created with capacity " << capacity << endl;
    }

    // ============================================================
    // DESTRUCTOR: Clean up memory when queue is destroyed
    // ============================================================
    ~Queue() {
        delete[] arr;               // Free the array memory
    }

    // ============================================================
    // ISEMPTY: Check if queue has no elements
    // ============================================================
    bool isEmpty() {
        return count == 0;          // If count is 0, queue is empty
    }

    // ============================================================
    // ISFULL: Check if queue is at maximum capacity
    // ============================================================
    bool isFull() {
        return count == capacity;   // If count equals capacity, it's full
    }

    // ============================================================
    // ENQUEUE: Add element to the BACK/REAR of queue
    // ============================================================
    // Visual (capacity = 5):
    // Before: [10][20][__][__][__]  front=0, rear=1, count=2
    //          ^front  ^rear
    // Enqueue 30:
    // After:  [10][20][30][__][__]  front=0, rear=2, count=3
    //          ^front      ^rear
    // ============================================================
    void enqueue(int value) {
        // Step 1: Check if queue is full (safety check!)
        if (isFull()) {
            cout << "Error: Queue is FULL! Cannot enqueue " << value << endl;
            return;                 // Exit function early
        }

        // Step 2: Move rear pointer forward (with wraparound)
        // IMPORTANT: Use modulo % to wrap around when reaching end
        rear = (rear + 1) % capacity;   // If rear=4 and capacity=5, next is 0

        // Step 3: Store the value at rear position
        arr[rear] = value;

        // Step 4: Increment count
        count++;

        cout << value << " enqueued to queue" << endl;
    }

    // ============================================================
    // DEQUEUE: Remove element from the FRONT of queue
    // ============================================================
    // Visual (capacity = 5):
    // Before: [10][20][30][__][__]  front=0, rear=2, count=3
    //          ^front      ^rear
    // Dequeue:
    // After:  [__][20][30][__][__]  front=1, rear=2, count=2
    //              ^front  ^rear     (10 is logically removed)
    // ============================================================
    int dequeue() {
        // Step 1: Check if queue is empty (safety check!)
        if (isEmpty()) {
            cout << "Error: Queue is EMPTY! Cannot dequeue." << endl;
            return -1;              // Return error value
        }

        // Step 2: Get the value at front position (before moving front)
        int dequeuedValue = arr[front];

        // Step 3: Move front pointer forward (with wraparound)
        front = (front + 1) % capacity;     // Circular movement

        // Step 4: Decrement count
        count--;

        // Return the removed value
        return dequeuedValue;
    }

    // ============================================================
    // PEEK/FRONT: Look at the FRONT element WITHOUT removing it
    // ============================================================
    int peek() {
        // Step 1: Check if queue is empty
        if (isEmpty()) {
            cout << "Error: Queue is empty! Nothing to peek." << endl;
            return -1;
        }

        // Step 2: Return front element (don't modify anything!)
        return arr[front];
    }

    // ============================================================
    // GETSIZE: Return current number of elements
    // ============================================================
    int getSize() {
        return count;               // We maintain count, so O(1) operation!
    }

    // ============================================================
    // DISPLAY: Show all elements in queue (front to rear)
    // ============================================================
    // This shows the logical order of elements
    // ============================================================
    void display() {
        // Step 1: Check if queue is empty
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue (front to rear): ";

        // Step 2: Traverse from front to rear (with circular logic)
        // We can't use simple for loop because of circular nature
        int i = front;                      // Start from front
        for (int j = 0; j < count; j++) {   // Loop 'count' times
            cout << arr[i] << " ";          // Print current element
            i = (i + 1) % capacity;         // Move to next (circular)
        }

        cout << endl;
    }

    // ============================================================
    // GETREAR: Get the rear element (bonus function)
    // ============================================================
    int getRear() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];           // Return element at rear position
    }

    // ============================================================
    // DEBUG: Show internal state (for learning purposes)
    // ============================================================
    void showInternalState() {
        cout << "\n--- Internal State ---" << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Count: " << count << endl;
        cout << "Front index: " << front << endl;
        cout << "Rear index: " << rear << endl;
        cout << "Array contents: ";
        for (int i = 0; i < capacity; i++) {
            if (i == front && i == rear && count > 0) {
                cout << "[" << arr[i] << "*] ";  // Front and rear same
            } else if (i == front) {
                cout << "[" << arr[i] << "F] ";  // Front
            } else if (i == rear) {
                cout << "[" << arr[i] << "R] ";  // Rear
            } else {
                cout << "[" << arr[i] << "] ";
            }
        }
        cout << "\n----------------------\n" << endl;
    }
};

// ============================================================
// MAIN FUNCTION: Test our queue implementation
// ============================================================

int main() {
    cout << "=== Queue with Array Demo ===" << endl << endl;

    // Create a queue with capacity 5
    Queue q(5);
    cout << endl;

    // TEST 1: Enqueue elements
    cout << "--- TEST 1: Enqueuing elements ---" << endl;
    q.enqueue(10);      // Queue: [10]
    q.enqueue(20);      // Queue: [10, 20]
    q.enqueue(30);      // Queue: [10, 20, 30]
    q.display();
    q.showInternalState();

    // TEST 2: Peek at front
    cout << "--- TEST 2: Peek at front ---" << endl;
    cout << "Front element: " << q.peek() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Size: " << q.getSize() << endl << endl;

    // TEST 3: Dequeue elements
    cout << "--- TEST 3: Dequeuing elements ---" << endl;
    cout << "Dequeued: " << q.dequeue() << endl;    // Remove 10
    cout << "Dequeued: " << q.dequeue() << endl;    // Remove 20
    q.display();
    q.showInternalState();

    // TEST 4: Enqueue more (demonstrating circular nature)
    cout << "--- TEST 4: Enqueue more (circular behavior) ---" << endl;
    q.enqueue(40);      // Queue: [30, 40]
    q.enqueue(50);      // Queue: [30, 40, 50]
    q.enqueue(60);      // Queue: [30, 40, 50, 60]
    q.enqueue(70);      // Queue: [30, 40, 50, 60, 70] - FULL!
    q.display();
    q.showInternalState();

    // TEST 5: Try to enqueue when full
    cout << "--- TEST 5: Enqueue when full ---" << endl;
    q.enqueue(80);      // Should fail - queue is full!
    cout << endl;

    // TEST 6: Dequeue some and enqueue again
    cout << "--- TEST 6: Dequeue and enqueue (circular wrap) ---" << endl;
    cout << "Dequeued: " << q.dequeue() << endl;    // Remove 30
    cout << "Dequeued: " << q.dequeue() << endl;    // Remove 40
    q.enqueue(80);      // Now there's space
    q.enqueue(90);
    q.display();
    q.showInternalState();

    // TEST 7: Empty the queue
    cout << "--- TEST 7: Empty the queue ---" << endl;
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }
    q.display();
    cout << endl;

    // TEST 8: Try to dequeue when empty
    cout << "--- TEST 8: Dequeue from empty queue ---" << endl;
    q.dequeue();        // Should show error
    cout << endl;

    // TEST 9: Enqueue after emptying
    cout << "--- TEST 9: Enqueue after emptying ---" << endl;
    q.enqueue(100);
    q.enqueue(200);
    q.display();

    return 0;
}

// ============================================================
// KEY CONCEPTS TO REMEMBER FOREVER:
// ============================================================
// 1. QUEUE STRUCTURE (Array-based):
//    - Fixed size array
//    - TWO pointers: front and rear
//    - Count variable tracks number of elements
//    - Uses CIRCULAR logic with modulo (%)
//
// 2. WHY CIRCULAR?
//    - Without circular: [__][__][30][40][50] - front=2
//      Can't use indices 0,1 even though they're empty!
//    - With circular: Rear wraps to index 0 when reaching end
//      rear = (rear + 1) % capacity
//
// 3. ENQUEUE (Add to rear):
//    - Check if full
//    - Move rear forward: rear = (rear + 1) % capacity
//    - Store value at arr[rear]
//    - Increment count
//    - Time: O(1) - Always constant!
//
// 4. DEQUEUE (Remove from front):
//    - Check if empty
//    - Get value at arr[front]
//    - Move front forward: front = (front + 1) % capacity
//    - Decrement count
//    - Time: O(1) - Always constant!
//
// 5. INITIALIZATION:
//    - front = 0 (first position)
//    - rear = -1 (no elements yet)
//    - count = 0 (empty)
//    - When first element added, rear becomes 0
//
// 6. FULL vs EMPTY:
//    - Empty: count == 0
//    - Full: count == capacity
//    - DON'T use (rear + 1) == front to check full!
//      (confuses full with empty in circular)
//
// 7. VISUALIZATION:
//    capacity = 5, front = 2, rear = 4, count = 3
//    Array: [__][__][10][20][30]
//                    ^F      ^R
//    Enqueue 40: rear wraps to 0
//    Array: [40][__][10][20][30]
//            ^R      ^F
//
// 8. QUEUE vs STACK:
//    - Queue: FIFO (First In, First Out) - like a line
//    - Stack: LIFO (Last In, First Out) - like plates
//    - Queue uses front AND rear
//    - Stack uses only top
// ============================================================