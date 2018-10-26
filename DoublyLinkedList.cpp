#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head;

Node* getNewNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void InsertAtHead(int data){
    Node* temp = getNewNode(data);
    if(head == NULL){
        head = temp;
        return;
    } else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void InsertAtTail(int data){
    Node* temp = new Node();
    temp = getNewNode(data);
    if(head == NULL){
        head = temp;
        return;
    } else {
        Node* temp2 = head;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
    }
}

void Print(){
    Node* temp = new Node();
    temp = head;
    cout << "Forward Iteration : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ReversePrint(){
    Node* temp = new Node();
    temp = head;

    if(temp == NULL) return;

    while(temp->next != NULL){
        temp = temp->next;
    }

    cout << "Reverse Iteration : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;

}

int main() {
    head = NULL;
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();

    InsertAtTail(8); Print(); ReversePrint();
}














