#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void Push(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop(){
    Node* temp = new Node();
    if (top == NULL){
        cout << "Error! : The list is empty" << endl;
        return;
    }
    temp = top;
    top = top->next;
    delete temp;
}

int Top(){
    if(top == NULL){
        cout << "Error! : The list is empty" << endl;
        return -1;
    }
    return top->data;
}

bool isEmpty(){
    return (top == NULL);
}

void Print(Node* p){
    if(p == NULL)
        return;
    Print(p->next);
    cout << p->data << " ";
}

int main(){
    cout << isEmpty() << endl;
    Push(5);
    Push(4);
    Push(3);

    Print(top);
    cout << endl;

    Pop();
    Print(top);
    cout << endl;

    cout << isEmpty() << endl;
    cout << Top() << endl;
}





