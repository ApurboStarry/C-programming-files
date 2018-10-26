#include <iostream>

using namespace std;

void egyptianFraction(int nr, int dr){
    if(nr == 0 || dr == 0){
        return;
    }
    if(dr % nr == 0){
        cout << "1/" << (dr/nr);
        return;
    }
    if(nr%dr == 0){
        cout << nr / dr << endl;
        return;
    }
    if(nr > dr){
        cout << nr/dr << " + ";
        egyptianFraction(nr%dr, dr);
        return;
    }
    int n = dr / nr + 1;
    cout << "1/" << n << " + ";
    egyptianFraction(nr*n - dr,dr*n);

}

int main(){
    int nr = 12, dr = 13;
    cout << "Egyptian Fraction of " << nr << "/" << dr << " is : ";
    egyptianFraction(nr,dr);

}
