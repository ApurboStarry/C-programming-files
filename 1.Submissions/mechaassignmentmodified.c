#include<stdio.h>
#include<math.h>
#define pi 3.1416

int main()
{
    float mat[4][4],another_mat[4][1],mod_mat[4][1],angle;
    int i,j,l,axis,NOTrans,type,dx,dy,dz;
    another_mat[3][0]=1;
    memset(mod_mat,0,sizeof(mod_mat));
    memset(mat,0,sizeof(mat));
    printf("Enter coordinates x, y and z: ");
    scanf("%f %f %f",&another_mat[0][0],&another_mat[1][0],&another_mat[2][0]);

    printf("Enter no. of transformations:");
    scanf("%d",&NOTrans);

    for(l=1; l<=NOTrans; l++)
    {
        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
                mat[i][j]=0;

        for(i=0; i<4; i++)
            mod_mat[i][0]=0;

        printf("Choose your option:\n\n");
        printf("\t1.Type 1 for Rotation.\n");
        printf("\t2.Type 2 for Translation\n\n");
        printf("Enter your option: ");
        scanf("%d",&type);
        if(type==1)
        {
            printf("Again choose your option:\n\n");
            printf("\t1.Type 1 for rotation about x axis\n");
            printf("\t2.Type 2 for rotation about y axis\n");
            printf("\t3.Type 3 for rotation about z axis\n\n");
            printf("Enter your option: ");
            scanf("%d",&axis);
            printf("Enter angle of rotation: ");
            scanf("%f",&angle);
            switch(axis)
            {
            case 1:
                for(i=0; i<4; i++)
                    mat[0][i]=mat[i][0]=mat[3][i]=mat[i][3]=0;
                mat[0][0]=mat[3][3]=1;
                mat[1][1]=mat[2][2]=cos(angle*pi/180);
                mat[1][2]=-sin(angle*pi/180);
                mat[2][1]=sin(angle*pi/180);
                break;
            case 2:
                for(i=0; i<4; i++)
                    mat[3][i]=mat[i][3]=mat[1][i]=mat[i][1]=0;
                mat[1][1]=mat[3][3]=1;
                mat[0][0]=mat[2][2]=cos(angle*pi/180);
                mat[2][0]=-sin(angle*pi/180);
                mat[0][2]=sin(angle*pi/180);
                break;
            case 3:
                for(i=0; i<4; i++)
                    mat[2][i]=mat[i][2]=mat[3][i]=mat[i][3]=0;
                mat[2][2]=mat[3][3]=1;
                mat[0][0]=mat[1][1]=cos(angle*pi/180);
                mat[0][1]=-sin(angle*pi/180);
                mat[1][0]=sin(angle*pi/180);
            }

            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                    mod_mat[i][0]+=mat[i][j]*another_mat[j][0];
        }
        else if(type==2)
        {
            printf("Enter dx, dy and dz: ");
            scanf("%d %d %d",&dx,&dy,&dz);
            for(i=0; i<4; i++)mat[i][i]=1;
            mat[0][3]=(double)dx,mat[1][3]=(double)dy,mat[2][3]=(double)dz;

            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                    mod_mat[i][0]+=mat[i][j]*another_mat[j][0];
        }

        for(i=0; i<4; i++)
            another_mat[i][0]=mod_mat[i][0];
    }

    printf("\nThe final point is: ");
    printf("(%.4lf , %.4lf , %.4lf)\n\n",mod_mat[0][0],mod_mat[1][0],mod_mat[2][0]);

    return 0;

}
