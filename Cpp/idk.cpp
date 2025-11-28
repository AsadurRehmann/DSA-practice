#include<iostream>
using namespace std;

// ============================================================
// STEP 1: CREATE THE NODE CLASS
// ============================================================
// Node is a "box" that holds:
// 1. Your data (the actual value)
// 2. An arrow pointing to the next box
// Same as stack, but we'll use it differently!
// ============================================================

class Node {
public:
    int data;           // The actual value stored in this node
    Node* next;         // Pointer/arrow to the next node in the chain

    // Constructor: When you create a new Node, this runs automatically
    Node(int value) {
        data = value;       // Store the value in this node
        next = nullptr;     // Initially, this node doesn't point anywhere
    }
};

// ============================================================
// STEP 2: CREATE THE QUEUE CLASS
// ============================================================
// Queue is like a LINE at a ticket counter:
// - People join at the BACK/REAR (enqueue)
// - People leave from the FRONT (dequeue)
// - First person in line gets served first
// This is called FIFO: First In, First Out
//
// KEY DIFFERENCE from Stack:
// - Stack has only ONE pointer (top)
// - Queue has TWO pointers (front and rear)
// ============================================================

class Queue {
private:
    // We need TWO pointers for efficient operations
    Node* front;        // Points to the first node (where we remove)
    Node* rear;         // Points to the last node (where we add)
    int count;          // Keeps track of number of elements

public:
    // ============================================================
    // CONSTRUCTOR: Initialize an empty queue
    // ============================================================
    Queue() {
        front = nullptr;    // Empty queue, front points to nothing
        rear = nullptr;     // Empty queue, rear points to nothing
        count = 0;          // No elements initially
    }

    // ============================================================
    // DESTRUCTOR: Clean up memory when queue is destroyed
    // IMPORTANT: Prevents memory leaks!
    // ============================================================
    ~Queue() {
        // Keep removing elements until queue is empty
        while (!isEmpty()) {
            dequeue();      // dequeue() already deletes nodes
        }
    }

    // ============================================================
    // ISEMPTY: Check if queue has no elements
    // ============================================================
    bool isEmpty() {
        return front == nullptr;    // If front is null, queue is empty
        // Alternative: return count == 0;
    }

    // ============================================================
    // ENQUEUE: Add element to the BACK/REAR of queue
    // ============================================================
    // Visual:
    // Before: front -> [10] -> [20] -> [30] <- rear
    // Enqueue 40:
    // After:  front -> [10] -> [20] -> [30] -> [40] <- rear
    //
    // SPECIAL CASE - Empty queue:
    // Before: front -> nullptr, rear -> nullptr
    // Enqueue 10:
    // After:  front -> [10] <- rear (both point to same node!)
    // ============================================================
    void enqueue(int value) {
        // Step 1: Create a new node with the given value
        Node* newNode = new Node(value);    // Allocate memory for new node

        // Step 2: Check if queue is empty (SPECIAL CASE!)
        if (isEmpty()) {
            // Queue is empty, so this is the first node
            front = newNode;        // Front points to new node
            rear = newNode;         // Rear also points to same node
        }
        else {
            // Queue is not empty, add at the end
            // Step 3a: Make current rear point to new node
            rear->next = newNode;   // Old rear's next points to new node

            // Step 3b: Update rear to point to new node
            rear = newNode;         // Rear now points to the new last node
        }

        // Step 4: Increment count
        count++;

        cout << value << " enqueued to queue" << endl;
    }

    // ============================================================
    // DEQUEUE: Remove element from the FRONT of queue
    // ============================================================
    // Visual:
    // Before: front -> [10] -> [20] -> [30] <- rear
    // Dequeue:
    // After:  front -> [20] -> [30] <- rear (10 is deleted)
    //
    // SPECIAL CASE - Only one element:
    // Before: front -> [10] <- rear (both point to same node)
    // Dequeue:
    // After:  front -> nullptr, rear -> nullptr (queue becomes empty)
    // ============================================================
    int dequeue() {
        // Step 1: Check if queue is empty (safety check!)
        if (isEmpty()) {
            cout << "Error: Queue is EMPTY! Cannot dequeue." << endl;
            return -1;              // Return error value
        }

        // Step 2: Store the current front node (we'll delete it soon)
        Node* temp = front;         // temp points to node we want to remove

        // Step 3: Get the data from front node (we need to return this)
        int dequeuedValue = front->data;    // Save value before deleting

        // Step 4: Move front pointer to next node
        front = front->next;        // front now points to second node

        // Step 5: SPECIAL CASE - If queue becomes empty
        if (front == nullptr) {
            // We removed the last element, so rear should also be null
            rear = nullptr;         // CRITICAL: Don't forget this!
        }

        // Step 6: Delete the old front node (free memory!)
        delete temp;                // CRITICAL: prevents memory leak

        // Step 7: Decrement count
        count--;

        // Step 8: Return the value we dequeued
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

        // Step 2: Return front's data (don't delete anything!)
        return front->data;
    }

    // ============================================================
    // GETREAR: Look at the REAR element WITHOUT removing it
    // ============================================================
    // This is easy with linked list because we have rear pointer!
    // (Would be hard with array-based queue)
    // ============================================================
    int getRear() {
        // Step 1: Check if queue is empty
        if (isEmpty()) {
            cout << "Error: Queue is empty! Nothing at rear." << endl;
            return -1;
        }

        // Step 2: Return rear's data
        return rear->data;
    }

    // ============================================================
    // GETSIZE: Return current number of elements
    // ============================================================
    int getSize() {
        return count;       // We maintain count, so O(1) operation!
    }

    // ============================================================
    // DISPLAY: Show all elements in queue (front to rear)
    // ============================================================
    void display() {
        // Step 1: Check if queue is empty
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue (front to rear): ";

        // Step 2: Create a temporary pointer to traverse
        // IMPORTANT: Use 'current', NOT 'front', so we don't lose front pointer!
        Node* current = front;      // Start from front

        // Step 3: Walk through each node and print its data
        while (current != nullptr) {        // Keep going until end
            cout << current->data << " ";   // Print current node's value
            current = current->next;        // Move to next node
        }

        cout << endl;
    }

    // ============================================================
    // DEBUG: Show internal state (for learning purposes)
    // ============================================================
    void showInternalState() {
        cout << "\n--- Internal State ---" << endl;
        cout << "Count: " << count << endl;
        cout << "Front data: " << (front ? to_string(front->data) : "null") << endl;
        cout << "Rear data: " << (rear ? to_string(rear->data) : "null") << endl;
        cout << "Is Empty: " << (isEmpty() ? "Yes" : "No") << endl;
        cout << "----------------------\n" << endl;
    }
};

// ============================================================
// MAIN FUNCTION: Test our queue implementation
// ============================================================

int main() {
    cout << "=== Queue with Linked List Demo ===" << endl << endl;

    // Create a queue object
    Queue q;

    // TEST 1: Enqueue elements
    cout << "--- TEST 1: Enqueuing elements ---" << endl;
    q.enqueue(10);      // Queue: [10]
    q.enqueue(20);      // Queue: [10] -> [20]
    q.enqueue(30);      // Queue: [10] -> [20] -> [30]
    q.enqueue(40);      // Queue: [10] -> [20] -> [30] -> [40]
    q.enqueue(50);      // Queue: [10] -> [20] -> [30] -> [40] -> [50]
    cout << endl;

    // TEST 2: Display queue
    cout << "--- TEST 2: Display queue ---" << endl;
    q.display();
    cout << "Size: " << q.getSize() << endl;
    q.showInternalState();

    // TEST 3: Peek at front and rear
    cout << "--- TEST 3: Peek at front and rear ---" << endl;
    cout << "Front element: " << q.peek() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    q.display();    // Queue unchanged
    cout << endl;

    // TEST 4: Dequeue elements
    cout << "--- TEST 4: Dequeuing elements ---" << endl;
    cout << "Dequeued: " << q.dequeue() << endl;    // Remove 10
    cout << "Dequeued: " << q.dequeue() << endl;    // Remove 20
    q.display();    // Should show: 30 40 50
    q.showInternalState();

    // TEST 5: Mix enqueue and dequeue
    cout << "--- TEST 5: Mix enqueue and dequeue ---" << endl;
    q.enqueue(60);      // Queue: [30] -> [40] -> [50] -> [60]
    q.enqueue(70);      // Queue: [30] -> [40] -> [50] -> [60] -> [70]
    cout << "Dequeued: " << q.dequeue() << endl;    // Remove 30
    q.display();        // Should show: 40 50 60 70
    cout << endl;

    // TEST 6: Dequeue all elements
    cout << "--- TEST 6: Dequeue all elements ---" << endl;
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }
    q.display();        // Should show "Queue is empty"
    q.showInternalState();

    // TEST 7: Try to dequeue from empty queue
    cout << "--- TEST 7: Dequeue from empty queue ---" << endl;
    q.dequeue();        // Should show error
    cout << endl;

    // TEST 8: Enqueue after emptying
    cout << "--- TEST 8: Enqueue after emptying ---" << endl;
    q.enqueue(100);     // Queue: [100]
    q.enqueue(200);     // Queue: [100] -> [200]
    q.display();
    q.showInternalState();

    // TEST 9: Single element edge case
    cout << "--- TEST 9: Single element operations ---" << endl;
    Queue q2;
    q2.enqueue(999);
    cout << "Front: " << q2.peek() << ", Rear: " << q2.getRear() << endl;
    cout << "Dequeued: " << q2.dequeue() << endl;
    q2.display();       // Should be empty

    return 0;
}

// ============================================================
// KEY CONCEPTS TO REMEMBER FOREVER:
// ============================================================
// 1. QUEUE STRUCTURE (Linked List):
//    - TWO pointers: front and rear
//    - Each node has: data + next pointer
//    - Last node's next points to nullptr
//    - NO SIZE LIMIT (dynamic growth!)
//
// 2. WHY TWO POINTERS?
//    - Front pointer: For O(1) dequeue (remove from front)
//    - Rear pointer: For O(1) enqueue (add to rear)
//    - Without rear pointer, enqueue would be O(n)
//      (would need to traverse entire list to find last node)
//
// 3. ENQUEUE (Add to rear) - TWO CASES:
//    Case A - Empty queue:
//      front = newNode;
//      rear = newNode;
//    Case B - Non-empty queue:
//      rear->next = newNode;
//      rear = newNode;
//    Time: O(1) - Always constant!
//
// 4. DEQUEUE (Remove from front) - TWO CASES:
//    Case A - Multiple elements:
//      temp = front;
//      front = front->next;
//      delete temp;
//    Case B - Last element (queue becomes empty):
//      temp = front;
//      front = nullptr;
//      rear = nullptr;    // DON'T FORGET THIS!
//      delete temp;
//    Time: O(1) - Always constant!
//
// 5. CRITICAL SPECIAL CASES:
//    - First enqueue (empty → 1 element):
//      Both front AND rear point to same node
//    - Last dequeue (1 element → empty):
//      Set BOTH front AND rear to nullptr
//
// 6. QUEUE vs STACK (Linked List):
//    Queue:
//      - Two pointers (front, rear)
//      - Add at rear, remove from front
//      - FIFO (First In, First Out)
//    Stack:
//      - One pointer (top)
//      - Add and remove from top
//      - LIFO (Last In, First Out)
//
// 7. LINKED LIST QUEUE vs ARRAY QUEUE:
//    Linked List:
//      ✅ No size limit (dynamic)
//      ✅ No wasted space
//      ✅ Simple logic (no circular)
//      ❌ Extra memory for pointers
//    Array:
//      ✅ Better cache locality
//      ✅ Less memory per element
//      ❌ Fixed size
//      ❌ Circular logic (complex)
//
// 8. VISUALIZATION:
//    Empty: front -> null, rear -> null
//
//    Enqueue 10: front -> [10] <- rear
//
//    Enqueue 20: front -> [10] -> [20] <- rear
//
//    Enqueue 30: front -> [10] -> [20] -> [30] <- rear
//
//    Dequeue:    front -> [20] -> [30] <- rear (10 deleted)
//
//    Dequeue:    front -> [30] <- rear (20 deleted)
//
//    Dequeue:    front -> null, rear -> null (30 deleted, empty!)
//
// 9. MEMORY MANAGEMENT:
//    - Every 'new' needs a 'delete'
//    - Destructor cleans up all nodes
//    - Always delete in dequeue()
//    - Prevents memory leaks!
//
// 10. COMMON MISTAKES TO AVOID:
//     ❌ Forgetting to set rear = nullptr when queue becomes empty
//     ❌ Not handling empty queue case in enqueue
//     ❌ Forgetting to delete nodes (memory leak!)
//     ❌ Losing front pointer while traversing (use temp!)
// ============================================================