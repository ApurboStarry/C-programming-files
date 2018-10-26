#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, n,j,ara[100];
   time_t t;

   n = 3;

   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ )
   {
       ara[i]=rand() % 3;
       for(j=0;j<i;j++)
       {
           if(ara[j] == ara[i]) ara[i]= rand() %3;
       }
   }

    for(i=0;i<n;i++)
    {
        printf("%d\n",ara[i]);
    }

   return(0);
}
