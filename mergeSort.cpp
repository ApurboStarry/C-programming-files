#include <iostream>
#include <cstdio>

using namespace std;

void merge(int ara[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1],R[n2];
    for(int i = 0;i<n1;i++){
        L[i] = ara[l + i];
    }

    for(int i = 0;i<n2;i++){
        R[i] = ara[m + 1 + i];
    }

    int i = 0,j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            ara[k++] = L[i++];
        }else {
            ara[k++] = R[j++];
        }
    }

    while(i < n1){
        ara[k++] = L[i++];
    }
    while(j < n2){
        ara[k++] = R[j++];
    }
}

void mergeSort(int ara[],int low,int high){
    if(low < high){
        int m = low + (high - low) / 2;
        mergeSort(ara,low,m);
        mergeSort(ara,m+1,high);

        merge(ara,low,m,high);
    }
}

void printArray(int ara[], int n){
    for(int i = 0; i<n;i++){
        cout << ara[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}











