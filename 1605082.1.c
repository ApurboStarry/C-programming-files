#include<stdio.h>

int process(int *(*pf)(int *, int *))
{
    int result,a,b;

    printf("\n");
    printf("Enter the value of a: ");
    scanf("%d",&a);

    printf("Enter the value of b: ");
    scanf("%d",&b);

    result= *pf(&a,&b);

    return result;
}

int *sum(int *a, int *b)
{
    int *c;
    *c=*a+*b;
    return c;
}

int *sub(int *a,int *b)
{
    int *d;
    *d=*a-*b;
    return d;
}

int *max(int *a,int *b)
{
    return ((*a>*b)? a: b);

}

int main()
{

    int c;
    printf("\tDetermination of summation of two numbers");
    c=process(sum);

    printf("\n\nSummation of the two numbers is: %d\n",c);
    printf("\n\n\tDetermination of subtraction of two numbers");
    c=process(sub);

    printf("\n\nSubtraction of the two numbers is: %d\n",c);
    c=process(max);

    printf("\n\nMaximum of the two numbers is: %d\n",c);

    return 0;

}
