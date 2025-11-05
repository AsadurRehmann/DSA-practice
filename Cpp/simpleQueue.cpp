#include<iostream>
using namespace std;

class Queue{
    private:
    int* arr;
    int front,rear,capacity,size;

    public:
    Queue(int cap){
        capacity=cap;
        arr=new int[capacity];
        front=size=0;
        rear=-1;
    }

    bool isFull(){
        return size==capacity;
    }

    bool isEmpty(){
        return size==0;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"queue is full.";
            return;
        }
        arr[++rear]=x;
        size++;
        cout<<x<<"is added in queue.";
    }

    int dequeue(){
    if(isEmpty()){
        cout << "Queue is empty." << endl;
        return -1;
    }
    int dequeued = arr[front];
    cout << dequeued << " removed from queue." << endl;
    front++;
    size--;
    return dequeued;
}

    int getFront(){
        if(isEmpty()){
            cout<<"queue is empty.";
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(isEmpty()){
            cout<<"queue is empty.";
            return -1;
        }
        return arr[rear];
    }

    void Display(){
        if(isEmpty()){
            cout<<"queue is empty.";
            return;
        }
        for(int i=front; i<=rear; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main() {
    cout << "=== Simple Queue Demo ===" << endl;

    // Create a queue with capacity 5
    Queue q(5);

    // Add elements to queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << endl;

    // Display current queue
    q.Display();

    cout << endl;

    // Try to add one more (should show overflow)
    q.enqueue(60);

    cout << endl;

    // Get front and rear
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    cout << endl;

    // Remove some elements
    q.dequeue();
    q.dequeue();

    cout << endl;

    // Display queue after dequeue
    q.Display();

    cout << endl;

    // Problem: Now front=2, rear=4. If we add more elements, rear will reach capacity
    // even though positions 0 and 1 are wasted!
    q.enqueue(60);

    cout << endl;
    q.Display();

    cout << endl;
    cout << "Notice: After dequeue, front positions are wasted!" << endl;
    cout << "This is why we need Circular Queue!" << endl;

    return 0;
}