#include <iostream>

using namespace std;

int dc(int ara[], int l, int h){
    if(h == l){
        //cout << ara[l] << endl;
        return ara[l];
    }

    int m = (l + (h - l) / 2);
    int left = dc(ara, l, m);
    int right = dc(ara, m + 1, h);
    int n = h - l + 1;
    if(left == right == -1)
        return -1;
    else if(left == -1 && right != -1)
        return right;
    else if(left != -1 && right == -1)
        return left;
    else if (left != right)
        return -1;
    return left;
}

int main(){
    int ara[] = {1,2,2,2,2,5,5,5};
    int n = dc(ara, 0, 7);
    if(n == -1)
        cout << "NO" << endl;
    else
        cout << n << endl;
}
