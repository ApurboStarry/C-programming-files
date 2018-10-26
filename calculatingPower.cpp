#include <iostream>

using namespace std;

float power(float x, int n){
    if(n == 0)
        return 1;
    float temp = power(x,n/2);
    if(n %2 == 0){
        return temp * temp;
    }
    else{
        if(n > 0)
            return x * temp * temp;
        else
            return temp * temp / x;
    }
}

int main(){
    cout << power(7,2) << endl << power(2.5,-3) << endl;
}
