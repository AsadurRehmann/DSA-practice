#include<iostream>
using namespace std;

struct Node
{
    int data;
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

    void push(int value){
        Node* newNode=new Node;
        newNode->data=value;
        newNode->next=top;
        top=newNode;

    }

    int pop(){
        if(isEmpty()){
            cout<<"stack underflow";
            return -1;
        }
        int value=top->data;
        Node* temp=top;
        top=top->next;
        delete temp;
        return value;
    }

};

int evalutePostfix(string exp){
    Stack stack;

    for(int i=0; i<exp.length(); i++){
        if(exp[i]>='0' && exp[i]<='9'){
            stack.push(exp[i]-'0');
        }else{
            int op2=stack.pop();
            int op1=stack.pop();

            switch (exp[i])
            {
            case '+':
                stack.push(op1+op2);
                break;
            case '-':
                stack.push(op1-op2);
                break;
            case '*':
                stack.push(op1*op2);
                break;
            case '/':
                stack.push(op1/op2);
                break;

            }
        }

    }

    return stack.pop();
}

int main(){
    string exp="46+2/5*7+";
    cout<<evalutePostfix(exp);
    return 0;
}
