#include<stdio.h>
#include<stdlib.h>
void insert(int m, int n, int a[m][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void addition(int m,int n,int p,int q,int a[m][n],int b[p][q],int c[m][q])
{
    if(m!=p && n!=q)
    {
        printf("Addition is not possible");
        exit(0);
    }
    else
    {
       for(int i=0;i<m;i++)
       {
          for(int j=0;j<n;j++)
          {
            c[i][j]=a[i][j]+b[i][j];
          }
       }   
    }   
}
void subtraction(int m,int n,int p,int q,int a[m][n],int b[p][q],int c[m][q])
{
    if(m!=p && n!=q)
    {
        printf("Subtraction not possible");
        exit(0);
    }
    else
    {
       for(int i=0;i<m;i++)
       {
          for(int j=0;j<n;j++)
          {
            c[i][j]=a[i][j]-b[i][j];
          }
       }   
    }   
}
void multiplication(int m,int n,int p,int q,int a[m][n],int b[p][q],int c[m][q])
{
    if(n!=p)
    {
        printf("multiplication not possible");
        exit(0);
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<q;j++)
            {
                for(int k=0;k<p;k++)
                {
                  c[i][j]=(c[i][j]+(a[i][k]*b[k][j]));
                } 
            }
        }
    }
}
void display(int m,int n,int c[m][n])
{
    printf("After Operation:\n");
    for(int i=0;i<m;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d",c[i][j]);
        }
    }
    printf("\n");
}
void main()
{
    int m, n, p, q;
    printf("Enter no of rows and columns of 1st matrix:\n");
    scanf("%d %d",&m,&n);
    printf("Enter no of rows and columns of 2nd matrix:\n");
    scanf("%d %d",&p,&q);
    int a[m][n],b[p][q],c[m][q],op;
    printf("Enter the elements in 1st matrix:\n");
    insert(m,n,a);
    printf("Enter the elements in 2nd matrix:\n");
    insert(p,q,b);
    printf("Enter the operation \n 1->Addition \n 2->Subtraction \n 3-Multiplication \n ");
    scanf("%d",&op);
    switch(op)
    {
        case 1 :
                addition(m,n,p,q,a,b,c);
                display(m,q,c);
                break;
        case 2 :
                subtraction(m,n,p,q,a,b,c);
                display(m,q,c);
                break;
        case 3 :
                multiplication(m,n,p,q,a,b,c);
                display(m,q,c);
                break;                
    }
}