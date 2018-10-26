#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ara[] = {20, 30, 10, 5, 30};
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0;i<5;i++){
        pq.push(ara[i]);
    }

    int ans = 0;

    while(pq.size() != 1){
        int temp = 0;
        temp += pq.top();
        pq.pop();
        temp += pq.top();
        pq.pop();
        ans += temp;
        //cout << "$$$ " << temp << endl;
        pq.push(temp);
    }
    cout << ans << endl;
}






















