#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ara[100000];

int main()
{
    int input,aramem=0,sortflag,n=0,i;
    while(input!=8)
    {
        printf("Choose");
        printf("\n");
        printf("\n");
        printf("  1.For entry of a list\n");
        printf("  2.For printing the list\n");
        printf("  3.For sorting the list\n");
        printf("  4.For searching a number\n");
        printf("  5.For appending a number\n");
        printf("  6.For inserting a number\n");
        printf("  7.For deleting a number\n");
        printf("  8.For exit\n");
        printf("Enter your option: ");

        scanf("%d",&input);
        system("cls");

        switch(input)
        {
            case 1: for(i=0;i<n;i++)
                    {
                        ara[i]=0;
                    }
                    printf("Enter the length of the list: ");
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
                        printf("The sorted list is: ");
                        int i,j,temp;
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
                        for(i=0;i<n;i++)
                        {
                            printf("%d ",ara[i]);
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
                            if(index==-1)
                            {
                                printf("The number us not found in your list");
                                getche();
                                system("cls");
                                break;
                            }
                            else
                            {
                                printf("%d is found in the %dth position of your list",num,(i+1));
                                getche();
                                system("cls");
                                break;
                            }
                        }
                    else if(sortflag==1)
                    {
                        int index=-1;
                        for(i=0;i<n;i++)
                        {
                            if(num==ara[i])
                            {
                                index=i;
                                break;
                            }
                            else if(ara[i]>num)
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
                        int appnd;
                        scanf("%d",&appnd);
                        if(sortflag==1)
                        {
                            ara[n]=appnd;
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
                        printf("Enter the number you want to insert: ");
                        int ins;
                        scanf("%d",&ins);
                        if(sortflag==1)
                        {
                            for(i=0;i<n;i++)
                            {
                                if(ara[i]>ins)
                                {
                                    int j;
                                    for(j=n;j>i;j--)
                                    {
                                        ara[j]=ara[j-1];
                                    }
                                    ara[i]=ins;
                                    n++;
                                    break;
                                }
                            }
                            printf("Successfully inserted");
                            getche();
                            system("cls");
                            break;
                        }
                        else if(sortflag==0)
                        {
                            ara[n]=ins;
                            n++;
                            sortflag=0;
                            printf("Successfully inserted the number!");
                            getche();
                            system("cls");
                            break;
                        }
                    }
            case 7: if(aramem==0)
                    {
                        printf("You have not entered a list yet");
                        getche();
                        system("cls");
                        break;
                    }
                    else if(aramem==1)
                    {
                        printf("Which number do you want to delete?: ");
                        int del;
                        scanf("%d",&del);
                        if(sortflag==0)
                        {
                            for(i=0;i<n;i++)
                            {
                                if(ara[i]==del)
                                {
                                    int j;
                                    for(;i<(n-1);i++)
                                    {
                                        ara[i]=ara[i+1];
                                    }
                                    n--;
                                    printf("Deleted successfully");
                                    getche();
                                    system("cls");
                                    break;
                                }
                                if(i==n-1){
                                    printf("%d is not found in the list \n",del);
                                    printf("Try again");
                                    getche();
                                    system("cls");
                                    break;
                                }
                            }
                        }
                        else if(sortflag==1){
                            for(i=0;i<n;i++)
                            {
                                if(ara[i]>del)
                                {
                                    printf("%d is not found in the list \n",del);
                                    printf("Try again");
                                    getche();
                                    system("cls");
                                    break;
                                }
                                if(ara[i]==del)
                                {
                                    for(;i<(n-1);i++)
                                    {
                                        ara[i]=ara[i+1];
                                    }
                                    n--;
                                    printf("Deleted successfully");
                                    getche();
                                    system("cls");
                                    break;
                                }
                            }

                        }
                    }
                    break;
            case 8:
                    printf("You have successfully exited!!\n");
                    break;
        }
    }
    return 0;
}
