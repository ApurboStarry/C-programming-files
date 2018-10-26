#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* head;

void Insert(int n){
    Node* temp = new Node();
    temp->data = n;
    if(head == NULL){
        head = temp;
    }else {
        Node* temp2 = head;
        while(temp2->link != NULL){
            temp2 = temp2->link;
        }
        temp2->link = temp;
    }
}

void Insert(int data,int pos){
    Node* temp1 = new Node();
    temp1->data = data;

    Node* temp2 = head;
    for(int i =1;i<=pos-1;i++){
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;
}

void Print(){
    Node* temp = new Node();
    temp = head;

    cout << "The List is : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

void Delete(int n){
    Node* temp1 = new Node();
    temp1 = head;

    for(int i=1;i<n-1;i++){
        temp1 = temp1->link;
    }
    Node* temp2 = new Node();
    temp2 = temp1->link;
    temp1->link = temp2->link;
    delete temp2;
}

void Reverse(){
    Node *current,*prev,*next;
    current = head;
    prev = NULL;

    while(current != NULL){
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void RPrint(Node* p){
    if(p == NULL) {
        cout << endl;
        return;
    }
    RPrint(p->link);
    cout << p->data << " ";

}

void RReverse(Node* p){
    if(p->link == NULL){
        head = p;
        return;
    }
    RReverse(p->link);
    //Node* q = p->link;
    //q->link = p;
    p->link->link = p;
    p->link = NULL;
}

int main(){
    head = NULL;
    Insert(4);
    Insert(5);
    Insert(6);
    Insert(7);
    Insert(8);
    Insert(9);
    Insert(10,3);

    Print();

    cout << "Enter the position which you want to delete : ";
    int n;
    cin >> n;
    Delete(n);
    Print();

    cout << "After reversing the list : ";
    RReverse(head);
    Print();


}

