#include <iostream>
#include <cstdio>

using namespace std;

void mergeS(int ara[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for(int i = 0;i<n1;i++){
        L[i] = ara[l+i];
    }
    for(int i = 0;i<n2;i++){
        R[i] = ara[m+1+i];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            ara[k] = L[i];
            i++;
        }
        else{
            ara[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        ara[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        ara[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int ara[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(ara, l, m);
        mergeSort(ara, m+1, r);
        mergeS(ara, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout << "Given array is \n" ;
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
