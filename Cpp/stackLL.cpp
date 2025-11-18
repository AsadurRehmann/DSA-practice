#include<iostream>
using namespace std;

struct Node{
    char data;
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

    void push(char val){
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=top;
        top=newNode;
    }

    char pop(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return '\0';
        }

        char value=top->data;
        Node* temp=top;
        top=top->next;
        delete temp;
        return value;
    }

    char peek(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return '\0';
        }
        return top->data;
    }

    void reverse(string str){


    }
};

string reverse(string str){
    Stack s;
    string reversed="";
    for(char ch:str){
        s.push(ch);
    }

    while(!s.isEmpty()){
        reversed+=s.pop();
    }
    return reversed;
}

int main(){
    string str="Asad ur Rehman";
    cout<<reverse(str);
}



