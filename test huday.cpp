#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n > 0) {
        cout << n % 26 << endl;
        n = n / 26;
    }
}
















