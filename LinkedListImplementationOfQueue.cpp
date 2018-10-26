#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue(){
    Node* temp = front;
    if(front == NULL){
            cout << "The List is already empty";
        return;
    }else if(front == rear){
        front = rear = NULL;
    }else {
        front = front->next;
    }
    delete temp;
}

int Front(){
    return front->data;
}

void Print(){
    Node* temp = front;
    cout << "The queue is : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Print();
    Dequeue();
    Print();
}
