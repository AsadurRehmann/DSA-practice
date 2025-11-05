#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=nullptr;
    }
};

class LLQueue{
    private:
    Node* front;
    Node* rear;
    int size;

    public:
    LLQueue(){
        front=rear=nullptr;
        size=0;
    }

    void enqueue(int x){
        Node* newNode=new Node(x);

        if(rear==nullptr){
            front=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
        size++;
        cout << x << " enqueued to queue" << endl;

    }

    void dequeue(){
         if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }
        Node* temp=front;
        cout<<front->data<<" removed from queue. "<<endl;
        front=front->next;

        if(front==nullptr){
            rear=nullptr;
        }
        delete temp;
        size--;
    }

    int getFront(){
        if(isEmpty()){
            cout<<"queue is empty. "<<endl;
            return -1;
        }
        return front->data;
    }

    int getRear(){
        if(isEmpty()){
            cout<<"queue is empty. "<<endl;
            return -1;
        }
        return rear->data;
    }

    bool isEmpty(){
        return front==nullptr;
    }

    int getSize(){
        return size;
    }

    void display(){
       if(isEmpty()){
        cout<<"queue is empty. "<<endl;
        return;
       }

       Node* temp = front;
       cout<<"queue elements: ";
       while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
       }
       cout<<endl;
    }

    ~LLQueue() {
        // Remove all elements one by one
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    cout << "=== Queue using Linked List Demo ===" << endl << endl;

    // Create an empty queue
    LLQueue q;

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
