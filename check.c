#include<stdio.h>

#define SWAP(a,b) { \
        a ^= b;     \
        b ^= a;     \
        a ^= b;     \
        }           \

int main()
{
    int a = 83,b = 313;
    printf("a = %d , b = %d",a,b);
    SWAP(a,b);
    printf("a = %d , b= %d",a,b);

    return 0;
}
