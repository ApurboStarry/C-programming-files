#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int factorial(int n) {
    int product = 1;
    for(int i = n; i >= 1; i--) {
        product *= i;
    }
    return product;
}

int permutation(int n, int r) {
    return (factorial(n) / factorial(n-r));
}

int main()
{
    string str = "4456";
    int a = stoi(str2);
    cout << a << endl;
}
