#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

enum {MINUS,PLUS,DIVISION,MULTIPLICATION};

char* infixToPostfix(char ara[]){
    char* str = new char();
    stack<char> s;
    int i = 0;
    int length = strlen(ara);

}

int main(){
    char ara[101];
    cin >> ara;
    cout << PLUS << MINUS << DIVISION << MULTIPLICATION << endl;
    cout << infixToPostfix(ara) <<  endl;
}
