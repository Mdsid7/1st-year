#include<stdio.h>
#include<stdlib.h>
void input(int m,int n,int a[m][n])
{
    printf("Enter %d array elements:\n",m*n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void sparse(int m,int n,int a[m][n])
{
    int s,c=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            c++;
        }
    }
    if(c>((m*n)/2))
    {
        int s=(m*n)-c;
        int b[3][s];
        int k=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]!=0)
                {
                    b[0][k]=i;
                    b[1][k]=j;
                    b[2][k]=a[i][j];
                    k++;
                }
            }
        }
        printf("the sparse matrix is:\n");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<s;j++)
            {
                printf(" %d", b[i][j]);
            }
            printf("\n");
        }
    }    
    else
    {
        printf("it is not a sparse matrix");
        exit(0);
    }
}
void main()
{
    int m,n;
    printf("Enter the no of rows and columns:\n");
    scanf("%d %d",&m,&n);
    int a[m][n];
    input(m,n,a);
    sparse(m,n,a);
}