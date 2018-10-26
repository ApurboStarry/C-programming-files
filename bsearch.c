#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp_in,*fp_out;
    char *inputfile = "F:\\C programming\\in.txt";
    char *outputfile = "F:\\C programming\\out.txt";

    char line[80];
    int num1,num2,sum;

    fp_in = fopen (inputfile, "r");
    fp_out = fopen (outputfile,"w");

    fgets (line ,80,fp_in);
    printf("Line  = %s\n", line);

    sscanf(line , "%d %d", &num1,&num2);

    sum= num1 + num2;
    printf("%d + %d = %d\n\n",num1,num2,sum);
    fprintf(fp_out,"%d\n",sum);

    fclose(fp_in);
    fclose(fp_out);

    return 0;

}
