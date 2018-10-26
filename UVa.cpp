#include<iostream>

using namespace std;

int uva(int n){
    int counter = 0;
    while(n != 1){
        if(n % 2 == 0){
            n = n / 2;
            counter++;
        }else {
            n = 3 * n + 1;
            counter++;
        }
    }
    return counter;
}

int main(){
    while(true){
        int i,j,l = 0;
        cin >> i >> j;
        int len =j-i+1;
        int counter[len];
        for(int k = i;k <= j;k++){
            counter[l] = uva(k);
            l++;
        }

        int max = counter[0];
        for(int z = 1;z < len;z++){
            if(max < counter[z]){
                max = counter[z];
            }
        }

        cout << i << " " << j << " " << max + 1 <<endl;
    }


}
