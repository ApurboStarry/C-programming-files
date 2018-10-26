#include<stdio.h>

int main()
{
    int nr, nc;
    while(1)
    {
        printf("Enter number of rows: ");
        scanf("%d",&nr);
        printf("Enter number of columns: ");
        scanf("%d",&nc);
        int mat[nc][nc];
        if(nr != nc)
        {
            printf("\nERROR:The matrix must have to be a square matrix if you want to transpose it!!!\nTry Again\n\n");
            continue;
        }
        else
        {
            int i,j,temp;
            printf("\n");
            for(i=0;i<nr;i++)
            {
                for(j=0;j<nc;j++)
                {
                    printf("Enter the value of a%d%d: ",(i+1),(j+1));
                    scanf("%d",&mat[i][j]);
                }
            }
            for(i=1;i<nr;i++)
            {
                for(j=0;j<i;j++)
                {
                    temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }

            printf("\nThe transposed matrix is given below: \n");
            for(i=0;i<nr;i++)
            {
                for(j=0;j<nc;j++)
                {
                    printf("%d ",mat[i][j]);
                }
                printf("\n");
            }
        }
        break;
    }
    return 0;
}
