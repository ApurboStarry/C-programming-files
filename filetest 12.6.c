#include<stdio.h>
#include<string.h>
#define TRUE 1

typedef struct{
    int month;
    int day;
    int year;
}date;

typedef struct{
    char name[80];
    char street [80];
    char city [80];
    int acc_no;
    char acc_type;
    float oldbalance;
    float newbalance;
    float payment;
    date lastpayment;
} record;

record readscreen(record customer);
void writefile(record customer);
FILE *fpt;


main()
{
    int flag=TRUE;
    record customer;
    fpt=fopen ("records.dat","w");
    printf("CUSTOMER BILLING SYSTEM-INITIALIZATION\n\n");
    printf("Enter todays date: ");
    scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
    customer.newbalance=0;
    customer.payment=0;
    customer.acc_type='C';

    while(flag)
    {
        printf("Enter customer's name: ");
        scanf(" %[^\n]", customer.name);
        fprintf(fpt,"\n%s\n", customer.name);
        if(strcmp(customer.name,"END")==0) break;
        customer=readscreen(customer);
        writefile(customer);
    }

    fclose(fpt);
}

record readscreen(record customer)
{
    printf("Street: ");
    scanf(" %[^\n]", customer.street);
    printf("City: ");
    scanf(" %[^\n]", customer.street);
    printf("Account number: ");
    scanf("%d",&customer.acc_no);
    printf("Current balance: ");
    scanf("%lf",&customer.oldbalance);

    return customer;
}

void writefile(record customer)
{
    fprintf(fpt, "%s\n", customer.street);
    fprintf(fpt, "%s\n", customer.city);
    fprintf(fpt, "%d\n", customer.acc_no);
    fprintf(fpt, "%c\n", customer.acc_type);
    fprintf(fpt, "%0.2f\n", customer.oldbalance);
    fprintf(fpt, "%0.2f\n", customer.newbalance);
    fprintf(fpt, "%0.2f\n", customer.payment);
    fprintf("%d/%d/%d\n", customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);

    return;

}
