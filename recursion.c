#include<stdio.h>
#include<stdlib.h>

int comparefunc(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b);
}

int main()
{
    int i,n,key,*item;

    printf("How many numbers you want to sort?: ");
    scanf("%d",&n);

    int values[n];

    printf("Enter the numbers: \n");

    for(i=0;i<n;i++)
    {
        printf("Number %d: ",i+1);
        scanf("%d",&values[i]);
    }

    qsort(values,n,sizeof(int),comparefunc);

    printf("Sorted Array: ");
    for(i=0;i<5;i++)
    {
        printf("%d ",values[i]);
    }

    printf("\n\nBinary Search Section: \n");

    while(1)
    {
        printf("Enter the value of the key(0 to exit): ");
        scanf("%d",&key);

        if(key == 0) break;

        item = (int *) bsearch(&key,values,n,sizeof(int),comparefunc);

        if(item != NULL) printf("Item found: %d\n",*item);
        else printf("Item not found in the array\n");
    }


    printf("\n");
    return 0;
}
