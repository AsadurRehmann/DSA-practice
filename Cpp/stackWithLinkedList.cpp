#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	Node(int val){
		data=val;
		next=nullptr;
	}
};

class Stack{
	Node* top;
	public:
		Stack(){
			top=nullptr;
		}

	bool isEmpty(){
		return top==nullptr;
	}

	void push(int val){
		Node* newNode=new Node(val);
		newNode->next=top;
		top=newNode;
		cout<<val<<" pushed to stack"<<endl;
	}

	int pop(){
		if(isEmpty()){
			cout<<"Stack is empty";
			return -1;
		}
		Node* temp=top;
		int poppedValue=temp->data;
		top=top->next;
		delete temp;
		return poppedValue;
	}

	int peek(){
		if(isEmpty()){
			cout<<"stack empty";
			return -1;
		}
		return top->data;
	}

	int getSize(){
		int count=0;
		Node* current=top;
		while(current!=nullptr){
			count++;
			current=current->next;
		}
		return count;
	}

	void display(){
		Node* current=top;
		while(current!=nullptr){
			cout<<current->data<<" ";
			current=current->next;
		}
		cout<<endl;
	}
};

