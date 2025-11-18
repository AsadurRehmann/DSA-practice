#include<iostream>
#include<vector>
using namespace std;

class Stack{
    private:
        int arr[1000];
        int top;
    public:
        Stack(){
            top = -1;
        }
        void push(int x){
            if(top == 999){
                cout << "Stack Overflow" << endl;
                return;
            }
            arr[++top] = x;
        }
        void pop(){
            if(top == -1){
                cout << "Stack Underflow" << endl;
                return;
            }
            top--;
        }
        int peek(){
            if(top == -1){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }
        bool isEmpty(){
            return top == -1;
        }
};

void stockSpan(vector<int>& prices, vector<int>& spans) {
   Stack s;
    for(int i=0; i<prices.size(); i++){

        while(!s.isEmpty() && prices[s.peek()]<=prices[i]){
            s.pop();

        }
        s.isEmpty() ? spans[i]=i+1 :spans[i]=i-s.peek();
        s.push(i);
    }
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans(prices.size());

    stockSpan(prices, spans);

    cout << "Stock Spans: ";
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}