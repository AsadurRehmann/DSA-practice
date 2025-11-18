#include<iostream>
using namespace std;

struct Node{
    int data;
    int minSoFar;
    Node* next;
};

class Stack{
    private:
    Node* top;
    public:
    Stack(){
        top=nullptr;
    }

    bool isEmpty(){
        return top==nullptr;
    }

    void push(int val){
        Node* newNode=new Node();
        newNode->data=val;
        if(isEmpty()){
            newNode->minSoFar=val;
        }else{
            if(val<top->minSoFar){
                newNode->minSoFar=val;
            }else{
                newNode->minSoFar=top->minSoFar;
            }
        }

        newNode->next=top;
        top=newNode;
    }

    int getMin(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return -1;
        }
        return top->minSoFar;
    }

    int pop(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return '\0';
        }

        int value=top->data;
        Node* temp=top;
        top=top->next;
        delete temp;
        return value;
    }

    int peek(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return '\0';
        }
        return top->data;
    }

    void display(){
        Node* temp=top;

        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }


};


int main(){
 Stack s;
    s.push(10);
    s.push(20);
    s.push(5);
    s.push(15);
s.display();

    cout << "Current Minimum: " << s.getMin() << endl;

    s.pop();
    cout << s.getMin() << endl;

    s.pop();
    cout << << s.getMin() << endl;

    return 0;
}



