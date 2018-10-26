#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


void gotoxy(int x, int y)
{
    COORD c={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int menu()
{
    int n;
    printf("   Choose\n");
    printf("\t1. For creating an account\n");
    printf("\t2. For viewing account balance\n");
    printf("\t3. For viewing transaction history\n");
    printf("\t4.For depositing money\n");
    printf("\t5.For withdrawing money\n");
    printf("\t6.For transfer money\n");
    printf("\t7.For exit\n");
    printf("\nEnter your option: ");
    scanf("%d",&n);

    return n;
}

typedef struct xx{
    int  day;
    int  month;
    int  year;
}date;

typedef struct yy
{
    int transaction_id;
    int transaction_type;
    date transaction_date;
    char description[1000];
    double transaction_amount;
}transaction;

typedef struct zz {
    int account_number;
    char account_name[30];
    date account_opening_date;
    transaction transaction_history[100];
    double balance;
}account;

account bank_acc[100];
int count=0;
int tcount[100];
int id=984621;
int tid=786423;
FILE *fpnew,*fpod;
char *namenw="dataNew.txt";
char *number="number.txt";


void create_account()
{
    printf("Enter your name: ");
    scanf(" %[^\n]", &bank_acc[count].account_name);
    bank_acc[count].account_number=id+count;
    printf("Enter the amount of money you want to deposit: ");
    scanf("%lf",&bank_acc[count].balance);
    SYSTEMTIME st;
    GetLocalTime(&st);
    bank_acc[count].account_opening_date.day=st.wDay;
    bank_acc[count].account_opening_date.month=st.wMonth;
    bank_acc[count].account_opening_date.year=st.wYear;
    system("cls");
    printf("Successfully created your account");
    printf("\nYour account number is: %d",bank_acc[count].account_number);
    printf("\nDate: %d/%d/%d\n",bank_acc[count].account_opening_date.day,bank_acc[count].account_opening_date.month,bank_acc[count].account_opening_date.year);
    count++;
    system("pause");
}

void view_account_balance()
{
    int a,i;
    printf("Enter your account number: ");
    scanf("%d",&a);
    system("cls");
    for(i=0;i<100;i++)
    {
        if(a==bank_acc[i].account_number) break;
    }
    if(i==100)
    {
        printf("Error!! Account number not found.\nTry Again!!!");
        system("pause");
    }
    else{
        printf("Mr. %s, your account balance is: %lf",bank_acc[i].account_name,bank_acc[i].balance);
        printf("\nAccount opening date: %d/%d/%d\n\n\n",bank_acc[i].account_opening_date.day,bank_acc[i].account_opening_date.month,bank_acc[i].account_opening_date.year);
        system("pause");
    }
}

void view_transaction_history()
{
    int a,i,j,x=5,y=13;
    double m;
    printf("Enter your account number: ");
    scanf("%d",&a);
    for(i=0;i<100;i++)
    {
        if(a==bank_acc[i].account_number) break;
    }
    if(i==100)
    {
        printf("Error!! Cannot find the account number entered by you!!\nTry again\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\n\tDear %s, your transaction history is given below: ",bank_acc[i].account_name);
        gotoxy(30,5);
        printf("TRANSACTION HISTORY");
        gotoxy(29,6);
        printf("====================");
        gotoxy(5,10);
        printf("DATE");
        gotoxy(5,11);
        printf("====");
        gotoxy(20,10);
        printf("TRANS. ID");
        gotoxy(20,11);
        printf("==========");
        gotoxy(35,10);
        printf("TYPE");
        gotoxy(35,11);
        printf("====");
        gotoxy(45,10);
        printf("AMOUNT");
        gotoxy(45,11);
        printf("======");
        gotoxy(60,10);
        printf("DESCRIPTION");
        gotoxy(60,11);
        printf("===========");
        for(j=0;j<tcount[i];j++)
        {
            gotoxy(x,y);
            printf("%d/%d/%d",bank_acc[i].transaction_history[j].transaction_date.day,bank_acc[i].transaction_history[j].transaction_date.month,bank_acc[i].transaction_history[j].transaction_date.year);
            x+=15;
            gotoxy(x,y);
            printf("%d",bank_acc[i].transaction_history[j].transaction_id);
            x+=15;
            gotoxy(x,y);
            printf("%d",bank_acc[i].transaction_history[j].transaction_type);
            x+=10;
            gotoxy(x,y);
            printf("%lf",bank_acc[i].transaction_history[j].transaction_amount);
            x+=15;
            gotoxy(x,y);
            printf("%s\n\n",bank_acc[i].transaction_history[j].description);
            x=5;
            y+=2;
        }
        printf("\n");
        system("pause");
    }
}

void deposit_money()
{
    int a,i;
    double m;
    printf("Enter your account number: ");
    scanf("%d",&a);
    for(i=0;i<100;i++)
    {
        if(a==bank_acc[i].account_number) break;
    }
    if(i==100)
    {
        printf("Error!! Cannot find the account number entered by you!!\nTry Again");
        system("pause");
    }
    else{
        printf("Dear %s,\nEnter the amount: ",bank_acc[i].account_name);
        scanf("%lf",&m);
        bank_acc[i].balance+=m;
        SYSTEMTIME st;
        GetLocalTime(&st);
        tid+=11;
        bank_acc[i].transaction_history[tcount[i]].transaction_date.day=st.wDay;
        bank_acc[i].transaction_history[tcount[i]].transaction_date.month =st.wMonth;
        bank_acc[i].transaction_history[tcount[i]].transaction_date.year =st.wYear;
        bank_acc[i].transaction_history[tcount[i]].transaction_id=tid;
        bank_acc[i].transaction_history[tcount[i]].transaction_type=0;
        strcpy(bank_acc[i].transaction_history[tcount[i]].description,"Deposition Complete");
        bank_acc[i].transaction_history[tcount[i]].transaction_amount=m;
        system("cls");
        tcount[i]++;
        printf("Successfully done!!! :D\n");
        system("pause");
    }
}

void withdraw_money()
{


    int a,i;
    double m;
    printf("Enter your Account number: ");
    scanf("%d",&a);
    for(i=0;i<100;i++)
    {
        if(a==bank_acc[i].account_number)
            break;
    }
    if(i==100){
        printf("No account found!!\nType correctly\n");
        system("pause");
    }
    else
    {
        printf("Dear %s,\nEnter the amount: ",bank_acc[i].account_name);
        scanf(" %lf",&m);
        if(m>bank_acc[i].balance){
            system("cls");
            printf("Insufficient balance!!! :(");
            system("pause");
            return;
        }
        else{
            bank_acc[i].balance-=m;
            SYSTEMTIME st;
            GetLocalTime(&st);
            tid+=11;
            bank_acc[i].transaction_history[tcount[i]].transaction_date.day=st.wDay;
            bank_acc[i].transaction_history[tcount[i]].transaction_date.month =st.wMonth;
            bank_acc[i].transaction_history[tcount[i]].transaction_date.year =st.wYear;
            bank_acc[i].transaction_history[tcount[i]].transaction_id=tid;
            bank_acc[i].transaction_history[tcount[i]].transaction_type=1;
            strcpy(bank_acc[i].transaction_history[tcount[i]].description,"Withdraw Completed");
            bank_acc[i].transaction_history[tcount[i]].transaction_amount=m;
            system("cls");
            tcount[i]++;
            printf("Successfully done!!! :D\n");
            system("pause");
        }
    }
}

void transfer_money()
{
    int a,i,r,j;
    double m;
    printf("Enter your Account number: ");
    scanf("%d",&a);
    for(i=0;i<100;i++)
    {
        if(a==bank_acc[i].account_number)
            break;
    }
    if(i==100){
        printf("No account found!!\nType correctly\n");
        system("pause");
    }
    else
    {
        printf("Dear %s,\nEnter the amount: ",bank_acc[i].account_name);
        scanf(" %lf",&m);
        if(m>bank_acc[i].balance){
            printf("Insufficient balance!!! :(");
            system("pause");
            return;
        }
        else
        {
            printf("Enter the recipient's account number: ");
            scanf("%d",&r);
            for(j=0;j<100;j++)
            {
                if(r==bank_acc[j].account_number)
                break;
            }
            if(j==100){
            printf("No account found!!\nType correctly\n");
            system("pause");
            }
            else
            {
                bank_acc[i].balance-=m;
                bank_acc[j].balance+=m;
                SYSTEMTIME st;
                GetLocalTime(&st);
                tid+=11;
                bank_acc[i].transaction_history[tcount[i]].transaction_date.day=st.wDay;
                bank_acc[i].transaction_history[tcount[i]].transaction_date.month =st.wMonth;
                bank_acc[i].transaction_history[tcount[i]].transaction_date.year =st.wYear;
                bank_acc[i].transaction_history[tcount[i]].transaction_id=tid;
                bank_acc[i].transaction_history[tcount[i]].transaction_type=2;
                strcpy(bank_acc[i].transaction_history[tcount[i]].description,"Transfer Completed");
                bank_acc[i].transaction_history[tcount[i]].transaction_amount=m;
                system("cls");
                tcount[i]++;
                printf("Successfully done!!! :D\n");
                system("pause");
            }
        }
    }
}

account readfile(account bank[], int n)
{
    int i;
    fscanf(fpod," %d",&bank[n].account_number);
    fscanf(fpod," %[^\n]", bank[n].account_name);
    fscanf(fpod," %d %d %d",&bank[n].account_opening_date.day,&bank[n].account_opening_date.month,&bank[n].account_opening_date.year);
    for(i=0;i<tcount[n];i++){
    fscanf(fpod," %d %d %d %d %d %lf %[^\n] ",&bank[n].transaction_history[i].transaction_id,&bank[n].transaction_history[i].transaction_type,&bank[n].transaction_history[i].transaction_date.day,&bank[n].transaction_history[i].transaction_date.month,&bank[n].transaction_history[i].transaction_date.year,&bank[n].transaction_history[i].transaction_amount,bank[n].transaction_history[i].description);
    }
    fscanf(fpod," %lf",&bank[n].balance);
    return bank[n];
}
void writefile(account bank[],int n)
{
    int i;
    fprintf(fpnew,"%d\n",bank[n].account_number);
    fprintf(fpnew,"%s\n", bank[n].account_name);
    fprintf(fpnew,"%d %d %d\n",bank[n].account_opening_date.day,bank[n].account_opening_date.month,bank[n].account_opening_date.year);
    for(i=0;i<tcount[n];i++){
    fprintf(fpnew,"%d %d %d %d %d %lf %s\n",bank[n].transaction_history[i].transaction_id,bank[n].transaction_history[i].transaction_type,bank[n].transaction_history[i].transaction_date.day,bank[n].transaction_history[i].transaction_date.month,bank[n].transaction_history[i].transaction_date.year,bank[n].transaction_history[i].transaction_amount,bank[n].transaction_history[i].description);
    }
    fprintf(fpnew,"%lf\n",bank[n].balance);
}


int main()
{
    int option,i;
    FILE *fp=fopen(number,"r");
    if(fp!=0)
    {
        for(i=0;i<100;i++)
            fscanf(fp," %d",&tcount[i]);
        fscanf(fp," %d",&count);
    }
    fclose(fp);

    fpod=fopen(namenw,"r");
    if(fpod!=0){
        for(i=0;i<count;i++)
            readfile(bank_acc,i);
    }
    fclose(fpnew);

    do{
        system("cls");
        option=menu();
        system("cls");
        switch(option)
        {
            case 1:create_account();
                    break;
            case 2:view_account_balance();
                    break;
            case 3:view_transaction_history();
                    break;
            case 4:deposit_money();
                    break;
            case 5:withdraw_money();
                    break;
            case 6:transfer_money();
                    break;
        }
    }while(option!=7);

    fp=fopen(number,"w");
    for(i=0;i<100;i++)
        fprintf(fp,"%d\n",tcount[i]);
    fprintf(fp,"%d\n",count);
    fclose(fp);

    fpnew=fopen(namenw,"w");
    for(i=0;i<count;i++)
    writefile(bank_acc,i);
    fclose(fpnew);

    return 0;
}
