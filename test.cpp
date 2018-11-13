#include <bits/stdc++.h>

using namespace std;

int* foo() {
    int *ara = new int[5];
    for(int i = 0; i < 5; i++) {
        ara[i] = i + 200;
    }
    return ara;
}

int main()
{
    int *ara = foo();
    for(int i = 0; i < 5; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;
}



















