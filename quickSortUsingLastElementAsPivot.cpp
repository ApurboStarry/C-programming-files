#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int ara[],int low, int high){
    int pivot = ara[high];
    int i = low - 1;
    for(int j = low; j <= high - 1;j++){
        if(ara[j] <= pivot){
            i++;
            swap(&ara[i],&ara[j]);
        }
    }
    swap(&ara[i+1],&ara[high]);
    for(int i = low;i<= high;i++){
        cout << ara[i] << " ";
    }
    cout << endl;
    return (i+1);
}

void quickSort(int ara[],int low, int high){
    if(low < high){
        int pi = partition(ara,low,high);
        quickSort(ara,low,pi - 1);
        quickSort(ara,pi + 1,high);
    }
}

void printArray(int ara[], int size){
    for(int i = 0; i<size;i++){
        cout << ara[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout << "After sorting the array becomes : ";
    printArray(arr, n);
    return 0;
}






















