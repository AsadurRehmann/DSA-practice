#include<iostream>
using namespace std;

class circularQueue{
    private:
    int* arr;
    int front,rear,capacity,size;
    public:
    circularQueue(int cap){
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
        rear=(rear+1)%capacity;

        arr[rear]=x;
        size++;
        cout<<x<<" added in position "<<rear<<endl;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"queue is Empty";
            return -1;
        }
        int dequeued=arr[front];
        front=(front+1)%capacity;
        cout<<dequeued<<" is removed from position "<<front;
        size--;
        return dequeued;
    }

    int getFront(){
        if(isEmpty()){
            cout<<"queue empty.";
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(isEmpty()){
            cout<<"queue empty.";
            return -1;
        }
        return arr[rear];
    }

    void display(){
        if(isEmpty()){
            cout<<"queue empty.";
            return;
        }
        cout<<"queue elements: ";
        int i=front;
        for(int count=0; count<size; count++){
            cout<<arr[i]<<" ";
            i=(i+1)%capacity;
        }
    }

    void showState() {
        cout << "Front: " << front << ", Rear: " << rear << ", Size: " << size << endl;
    }

    // Destructor
    ~circularQueue() {
        delete[] arr;
    }
};

int main() {
    cout << "=== Circular Queue Demo ===" << endl << endl;

    // Create circular queue with capacity 5
    circularQueue cq(5);

    // Add 5 elements (fill the queue)
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cout << endl;
    cq.display();
    cq.showState();

    cout << endl;

    // Try to add one more (should fail - queue full)
    cq.enqueue(60);

    cout << endl;

    // Remove 3 elements from front
    cout << "Removing 3 elements..." << endl;
    cq.dequeue();  // Remove 10
    cq.dequeue();  // Remove 20
    cq.dequeue();  // Remove 30

    cout << endl;
    cq.display();
    cq.showState();  // Now front=3, rear=4, size=2

    cout << endl;

    // KEY DEMO: Now add 3 more elements
    // rear will wrap around to beginning (circular behavior)
    cout << "Adding 3 more elements (watch the wrapping!)..." << endl;
    cq.enqueue(60);  // rear wraps to 0
    cq.enqueue(70);  // rear = 1
    cq.enqueue(80);  // rear = 2

    cout << endl;
    cq.display();
    cq.showState();  // Now front=3, rear=2 (circular!)

    cout << endl;

    // Show front and rear
    cout << "Front element: " << cq.getFront() << endl;  // 40
    cout << "Rear element: " << cq.getRear() << endl;    // 80

    cout << endl;

    // Remove all remaining elements
    cout << "Removing all elements..." << endl;
    while (!cq.isEmpty()) {
        cq.dequeue();
    }

    cout << endl;

    // Try to remove from empty queue
    cq.dequeue();

    return 0;
}