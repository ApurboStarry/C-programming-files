#include <bits/stdc++.h>

using namespace std;

int w(int freq[], int i, int j){
    int sum = 0;
    for(int x = i;x < j;x++){
        sum += freq[x];
    }
    return sum;
}

int OBST(int freq[], int n){
    int cost[n+1][n+1];
    for(int i = 0;i<=n;i++){
        cost[i][i] = 0;
    }
    for(int i = 0;i<n;i++){
        cost[i][i+1] = freq[i];
    }
    for(int L = 2;L <= n;L++){
        for(int i = 0;i<n;i++){
            if(i+L > n){
                //cout << "\nIN BREAK" << endl;
                break;
            }
            int j = i+L;
            int min = INT_MAX;
            for(int x = i+1;x <= j;x++){
                if(min > cost[i][x-1] + cost[x][j])
                    min = cost[i][x-1] + cost[x][j];
            }
            cost[i][j] = min + w(freq, i, j);
        }
    }
    return cost[0][n];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout << OBST(freq, n) << endl;
    //cout << w(freq, 1, 4) << endl;
    return 0;
}
