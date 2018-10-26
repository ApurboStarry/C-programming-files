#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
    char jobID;
    int deadLine;
    int profit;
};

bool comparator(Job a, Job b){
    return (a.profit > b.profit);
}

void jobScheduling(Job ara[], int n){
    sort(ara,ara+n,comparator);
    int result[n];
    bool slot[n];
    fill(slot,slot + n,false);

    for(int i = 0;i<n;i++){
        for(int j = min(n,ara[i].deadLine) - 1;j >= 0;j--){
            if(slot[j] == false){
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    for(int i = 0;i<n;i++){
        if(slot[i])
            cout << ara[result[i]].jobID << " ";
    }

}

int main(){
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};

    jobScheduling(arr,4);
}
