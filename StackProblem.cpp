#include<iostream>
#include <cstring>
#include<stack>
#include <cstdio>

using namespace std;

bool isBalanced(char ara[]){
    stack<char> s;
    for(int i = 0;i<strlen(ara);i++){
        if(ara[i] == '[' || ara[i] == '{' || ara[i] == '('){
            s.push(ara[i]);
        }
        else if(ara[i] == ']' || ara[i] == '}' || ara[i] == ')'){
            if(s.empty() || (s.top() != '(' && ara[i] == ')') || (s.top() != '{' && ara[i] == '}') || (s.top() != '[' && ara[i] == ']')){
                return false;
            }
            else {
                s.pop();
            }
        }
    }
    return s.empty() ? true : false;
}

int main(){
    char ara[101];
    cin >> ara;
    cout << isBalanced(ara) <<  endl;
}
