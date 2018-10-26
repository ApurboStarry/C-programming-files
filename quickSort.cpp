#include <iostream>
#include <cstdio>

using namespace std;

void swapK(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int ara[], int l, int h){
    int pivot = ara[h];
    int i = l - 1;

    for(int j = l; j < h;j++){
        if(ara[j] <= pivot){
            i++;
            swapK(&ara[i], &ara[j]);
        }
    }
    swapK(&ara[i+1], &ara[h]);
    return i+1;
}

void quickSort(int ara[], int l, int h){
    if(l < h){
        int pi = partition(ara, l, h);

        quickSort(ara, l, pi - 1);
        quickSort(ara, pi + 1, h);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
