#include <stdio.h>
#include <stdlib.h>

int arr[100000];
int main()
{
    int input,n=0,i,j,snum,anum,inum,dnum;
    int sortflag=0;

    do{
        printf("choose\n");
        printf("1 for entry of a list\n");
        printf("2 for printing the list\n");
        printf("3 for sorting the list\n");
        printf("4 for searching a number\n");
        printf("5 for appending a number\n");
        printf("6 for inserting a number\n");
        printf("7 for deleting a number\n");
        printf("8 for exit\n");
        printf("Enter your option: ");

        scanf("%d",&input);
        system("cls");
        switch(input)
        {
        case 1: //entry of a list
            for(i=0; i<n; i++)
                arr[i]=0;
            printf("Enter n: ");
            scanf("%d",&n);
            for(i=0; i<n; i++)
                scanf("%d",&arr[i]);
            printf("Done");
            getche();
            system("cls");
            break;

        case 2://printing the list
            if(n==0)
            {
                printf("List does not exist.\n");
            }
            else
            {
                printf("list:\n");
                for(i=0; i<n; i++)
                    printf("%d ",arr[i]);
            }
            getche();
            system("cls");
            break;
            break;

        case 3://sort the list
            for(i=0; i<n; i++)
                for(j=i+1; j<n; j++)
                    if(arr[i]>arr[j])
                    {
                        int temp=arr[i];
                        arr[i]=arr[j];
                        arr[j]=temp;
                    }
            sortflag=1;
            break;

        case 4://search a number
            printf("Enter a number: ");
            scanf("%d",&snum);
            //sorted search
            if(sortflag)
            {
                for(i=0; i<n; i++)
                {
                    if(arr[i]>snum)
                    {
                        printf("not found\n");
                        break;
                    }
                    if(arr[i]==snum)
                    {
                        printf("The number was found\n");
                        break;
                    }
                    if(i==n-1)
                    {
                        printf("not found\n");
                        break;
                    }
                }
            }
            //unsorted search
            else
            {
                for(i=0; i<n; i++)
                {
                    if(snum==arr[i])
                    {
                        printf("The number was found\n");
                        break;
                    }
                    if(i==n-1)
                        printf("not found\n");
                }
            }
            break;

        case 5://appending a number
            printf("Enter a number: ");
            scanf("%d",&anum);
            arr[n]=anum;
            n++;
            if(arr[n]<arr[n-1])
                sortflag=0;

            break;

        case 6:
            printf("Enter a number: ");
            scanf("%d",&inum);

            if(sortflag)
            {
                for(i=n-1; i>=0; i--)
                {
                    if(arr[i]>inum)
                    {
                        arr[i+1]=arr[i];
                    }
                    else
                    {
                        arr[i+1]=inum;
                        break;
                    }
                }
                n++;
            }
            else{
                arr[n]=inum;
                n++;
            }
            break;

        case 7: //deleting a number
            printf("Enter a number: ");
            scanf("%d",&dnum);
            if(sortflag)
            {
                for(i=0; i<n; i++)
                {
                    if(arr[i]>dnum)
                    {
                        printf("doesn't exist\n");
                        break;
                    }
                    if(arr[i]==dnum)
                    {
                        for(; i<n-1; i++)
                        {
                            arr[i]=arr[i+1];
                        }
                        n--;
                        break;
                    }
                    if(i==n-1)
                    {
                        printf("doesn't exist\n");
                        break;
                    }
                }
            }
            else
                for(i=0; i<n; i++)
                {
                    if(arr[i]==dnum)
                    {
                        for(; i<n-1; i++)
                        {
                            arr[i]=arr[i+1];
                        }
                        n--;
                    }
                    if(i==n-1)
                    {
                        printf("doesn't exist.\n");
                        break;
                    }
                }
            break;

        case 8:
            printf("You've successfully exited\n");
            break;
        default :
            printf("Invalid input!!\nTry again\n");
            getche();
            system("cls");
        }
    }
    while(input!=8);

    return 0;
}
