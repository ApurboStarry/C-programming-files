#include<stdio.h>

double rec(int n)
{
    if (n == 1) return 1;
    else if (n == 2) return 3;
    else return (rec(n-1) * rec(n-2));
}

int main()
{
    int n;
    printf("Enter the value of n: ");  //Typing 17 will result in a out of range value
    scanf("%d",&n);
    printf("\nThe nth term is: %0.0lf\n\n",rec(n));

    return 0;
}
