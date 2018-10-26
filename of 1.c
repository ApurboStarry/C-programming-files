#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *SelectionSort(int ara[10000],int n)
{
    int i,j,temp,*array;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ara[i]>ara[j])
            {
                temp=ara[i];
                ara[i]=ara[j];
                ara[j]=temp;
            }
        }
    }
    return ara;
}

int main()
{
    int input,aramem=0,sortflag;
    while(input!=8)
    {
        printf("Choose");
        printf("\n");
        printf("   1. For entry of a list\n");
        printf("   2.For printing the list\n");
        printf("   3.For sorting the list\n");
        printf("   4.For searching a number\n");
        printf("   5.For appending a number\n");
        printf("   6.For inserting a number\n");
        printf("   7.For deleting a number\n");
        printf("   8.For exit\n");
        printf("Enter your option: ");

        scanf("%d",&input);
        system("cls");

        switch(input)
        {
            case 1: printf("Enter the length of the list: ");
                    int n,ara[10000];
                    scanf("%d",&n);
                    printf("Enter your list: ");
                    int i;
                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&ara[i]);
                    }
                    sortflag=0;
                    aramem=1;
                    printf("Successfully entered the list!");
                    getche();
                    system("cls");
                    break;

            case 2: if(aramem==0) printf("You have not entered your list yet");
                    else if(aramem==1)
                    {
                        printf("Your list: ");
                        for(i=0;i<n;i++)
                        {
                            printf("%d ",ara[i]);
                        }
                    }
                    getche();
                    system("cls");
                    break;

            case 3:
                   if(aramem==0)
                   {
                       printf("You have not entered a list yet");
                       getche();
                       system("cls");
                       break;
                   }
                   else
                   {
                        printf("The sorted array is: ");
                        int *array=SelectionSort(ara,n);
                        for(i=0;i<n;i++)
                        {
                            printf("%d ",array[i]);
                        }
                        sortflag=1;
                        getche();
                        system("cls");
                        break;
                   }
            case 4: if(aramem==0)
                    {
                        printf("You have not Entered a list yet");
                        getche();
                        system("cls");
                        break;
                    }
                    else
                    {
                         printf("Enter the number you want to search: ");
                    int num;
                    scanf("%d",&num);
                    if(sortflag==0)
                        {
                            int index=-1;
                            for(i=0;i<n;i++)
                            {
                                if(num==ara[i])
                                {
                                    index=i;
                                    break;
                                }
                            }
                            if(index==i)
                            {
                                printf("The number us not found in your list");
                                getche();
                                system("cls");
                            }
                            else
                            {
                                printf("%d is found in the %dth position of your list",num,(i+1));
                            }
                        }
                    else if(sortflag==1)
                    {
                        int index=-1;
                        int *array=SelectionSort(ara,n);
                        for(i=0;i<n;i++)
                        {
                            if(num==array[i])
                            {
                                index=i;
                                break;
                            }
                            else if(array[i]>num)
                            {
                                break;
                            }
                        }
                        if(index==-1)
                        {
                            printf("%d is not found in your list",num);
                            getche();
                            system("cls");
                            break;
                        }
                        else{
                            printf("%d is found in the %dth position of your list",num,(i+1));
                            getche();
                            system("cls");
                            break;
                        }
                    }
                    }
            case 5: if(aramem==0)
                    {
                        printf("You have not entered a list yet");
                        getche();
                        system("cls");
                        break;
                    }
                    else{
                        printf("Enter the number you want to append: ");
                        int appnd,*array;
                        scanf("%d",&appnd);
                        if(sortflag==1)
                        {
                            array[n]=appnd;
                            n++;
                            sortflag=0;
                            printf("Successfully appended the number!");
                            getche();
                            system("cls");
                            break;
                        }
                        else
                        {
                            ara[n]=appnd;
                            n++;
                            sortflag=0;
                            printf("Successfully appended the number!");
                            getche();
                            system("cls");
                            break;
                        }
                    }
            case 6: if(aramem==0)
                    {
                        printf("You have not entered a list yet");
                        getche();
                        system("cls");
                    }
                    else{
                        printf("Enter the position you want to insert: ");
                        int ins;
                        scanf("%d",&ins);
                        printf("Now enter the number: ");
                        int number;
                        scanf("%d",&number);
                        for(i=n;i>=ins;i--)
                        {
                            ara[i]=ara[i-1];
                        }
                        ara[ins-1]=number;
                        n++;
                        printf("Successfully inserted the number");
                        getche();
                        system("cls");
                        break;
                    }
            case 7: if(aramem==0)
                    {
                        printf("You have not entered a list yet");
                        getche();
                        system("cls");
                        break;
                    }
                    else
                    {
                        printf("Which position you want to delete?: ");
                    int del,array[10000];
                    scanf("%d",&del);
                    if(sortflag==0)
                    {
                        for(i=(del-1);i<=n-2;i++)
                        {
                            ara[i]=ara[i+1];
                        }
                        n--;
                        printf("Deleted successfully");
                        getche();
                        system("cls");
                        break;
                    }
                    else{
                        for(i=(del-1);i<=n-2;i++)
                        {
                            array[i]=array[i+1];
                        }
                        n--;
                        printf("Deleted successfully");
                        getche();
                        system("cls");
                        break;
                    }
                    }
            case 8:
                printf("exited!!\n");
                break;
        }
    }
    return 0;
}
