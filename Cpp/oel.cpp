#include<iostream>
#include<string>
using namespace std;

struct Patient{
    int id,emergencyLevel;
    string name;
};

void addPatient(Patient arr[],int &count){
    if(count>=20){
        cout<<"cannot admit more patients"<<endl;
        return;
    }

    Patient newPatient;
    cout<<"===add new patient==="<<endl;
    cout<<"ID: ";
    cin>>newPatient.id;
    cin.ignore();
    cout<<"Name: ";
    getline(cin,newPatient.name);
    cout<<"enter emergency level (1=low,2=medium,3=high): ";
    cin>>newPatient.emergencyLevel;
    arr[count]=newPatient;
    count++;
    cout<<"patient added successfullly."<<endl;

}

void displayPatients(Patient arr[],int &count){
    if(count==0){
        cout<<"no patients"<<endl;
        return;
    }
    cout<<"ALL patients"<<endl;
    cout<<"==================="<<endl;
    for(int i=0; i<count; i++){
        cout<<"ID: "<<arr[i].id<<endl;
        cout<<"Name: "<<arr[i].name<<endl;
        cout<<"Emergency Level: "<<arr[i].emergencyLevel<<endl;
    }
}

int findPatientIndex(Patient arr[], int count, int id){
    for(int i=0; i<count; i++){
        if(arr[i].id==id){
            return i;
        }
    }

    return -1;
}

class ActionStack{
    private:
    string *arr;
    int top;
    int capacity;
    public:
    ActionStack(int size=50){
        capacity=size;
        arr=new string[capacity];
        top=-1;
    }

    void push(string action){
        if(top>=capacity-1){
            cout<<"Stack full"<<endl;
            return;
        }
        top++;
        arr[top]=action;
        cout<<"Action "<<action<<" pushed into stack"<<endl;
    }

    string pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return "";
        }
        string action=arr[top];
        top--;
        return action;
    }

    string peek(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return "";
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }

    void display(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        cout<<"Action Stack"<<endl;
        for(int i=top; i>0; i--){
            cout<<(top-i-1)<<". "<<arr[i]<<endl;
        }
    }
};

class EmergencyQueue{
    private:
    int* patientIDs;
    int* levels;
    int front,rear,size,capacity;
    public:
    EmergencyQueue(int cap=50){
        capacity=cap;
        patientIDs=new int[capacity];
        levels=new int[capacity];
        front=size=0;
        rear=-1;
    }

    void enqueue(int patientID,int emergencyLevel){
        if(size>=capacity){
            cout<<"Emergency queue is full"<<endl;
            return;
        }
        if(size==0){
            rear++;
            patientIDs[rear]=patientID;
            levels[rear]=emergencyLevel;
            size++;
            cout<<"patient added";
            return;
        }

        rear++;
        int pos=rear;
        while(pos>front && levels[pos-1]<emergencyLevel){
            patientIDs[pos]=patientIDs[pos-1];
            levels[pos]=levels[pos-1];
            pos--;
        }

        patientIDs[pos]=patientID;
        levels[pos]=emergencyLevel;
        size++;
        cout<<"Patient added ";
    }

    int dequeue() {

        if (isEmpty()) {
            cout << "Emergency queue is empty!" << endl;
            return -1;
        }
        int patientID = patientIDs[front];
        front++;
        size--;
        cout << "Patient ID " << patientID << " called for treatment." << endl;
        return patientID;
    }

    bool isEmpty() {
        return size == 0;
    }

     void display() {
        // Check if empty
        if (isEmpty()) {
            cout << "\nEmergency queue is empty." << endl;
            return;
        }

        cout << "\n--- Emergency Queue (Priority Order) ---" << endl;
        cout << "Position\tPatient ID\tPriority" << endl;
        cout << "----------------------------------------" << endl;

        // Display from front to rear
        for (int i = front, pos = 1; i < front + size; i++, pos++) {
            cout << pos << "\t\t" << patientIDs[i] << "\t\t";

            // Show priority level
            if (levels[i] == 3) cout << "3 (High)";
            else if (levels[i] == 2) cout << "2 (Medium)";
            else cout << "1 (Low)";

            cout << endl;
        }
    }
};