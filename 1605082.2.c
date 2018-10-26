#include<stdio.h>

int main()
{
    int A[6][4]={
                    {1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16},
                    {17,18,19,20},
                    {21,22,23,24}
                };

    printf("A=%p\n",A);
    printf("*A=%p\n",*A);
    printf("**A=%d\n",**A);
    printf("*A+1=%p\n",*A+1);
    printf("(*(*A+3)+5)=%d",(*(*A+3)+5));

    printf("\n\nsizeof(int) = %d",sizeof(int));
    printf("\nsizeof(int*) = %d",sizeof(int*));
    printf("\nsizeof(int**) = %d",sizeof(int**));

    return 0;
}
