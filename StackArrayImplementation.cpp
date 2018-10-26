#include <iostream>
#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;

using namespace std;

void Push(int x){
    if(top == MAX_SIZE - 1){
        cout << "Error! : Stack has Overflown" << endl;
        return;
    }
    a[++top] = x;
}

void Pop(){
    if(top == -1){
        cout << "Error! : The stack is empty" << endl;
    }
    top--;
}

int Top(){
    if(top == -1){
        cout << "Error! : The stack is empty" << endl;
        return -1;
    }
    return a[top];
}

void Print(){

    for(int i=0;i<=top;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    Push(2); Print();
    Push(4); Print();
    Push(6); Print();
    Pop(); Print();

    cout << Top() << endl;

    Push(10); Print();
}
