#include <cstdio>

using namespace std;

int getMedian(int ara1[], int ara2[],int n){
    int i =0, j = 0, m1 = -1, m2 = -1;
    for(int count = 0; count <= n;count++){
        if(ara1[i] < ara2[j]){
            m1 = m2;
            m2 = ara1[i++];
        }
        else {
            m1 = m2;
            m2 = ara2[j++];
        }

        if(i == n){
            m1 = m2;
            m2 = ara2[0];
        }
        else if(j == n){
            m1 = m2;
            m2 = ara1[0];
        }
    }
    return (m1 + m2) / 2;
}

int main(){
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};

    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    getchar();
    return 0;
}
