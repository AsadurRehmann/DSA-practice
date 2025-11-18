#include<iostream>
using namespace std;
#define size 5
class Stack{
    private:
    int top;
    int arr[size];
    public:
    Stack(){
        top=-1;
    }

    bool isEmpty(){
        return top==-1;
    }

    bool isFull(){
        return top==size-1;
    }

    void push(char val){
        if(isFull()){
            cout<<"stack full"<<endl;
            return;
        }
        arr[++top]=val;
    }

    char pop(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return '\0';
        }
        char poped=arr[top];
        --top;
        return poped;
    }




};

bool areBracketsBalanced(string str){
        Stack para;
        for(int i=0; i<str.length(); i++){
            char c=str[i];
            if(c=='(' || c=='{' || c=='['){
                para.push(c);
            }else{
                if(para.isEmpty()){
                    return false;
                }
                char top=para.pop();
                if(c==')' && top!='(' ||
                    c=='}' && top!='{' ||
                    c==']' && top!='['
                ){
                    return false;
                }
            }
        }
        return para.isEmpty();
    }

    int evalutaPostix(string str){
        Stack stack;

        for(int i=0; i<str.length(); i++){

            if(str[i]>='0' && str[i]<='9'){
                stack.push(str[i]-'0');
            }
            else{
                int op2=stack.pop();
                int op1=stack.pop();
                switch(str[i]){
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


    string str="531*+4-";
    cout<<evalutaPostix(str);
}