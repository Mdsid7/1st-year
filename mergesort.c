#include<stdio.h>
#include<stdlib.h>
int A[10],max=10;
void merge(int beg, int mid , int end)
{
    int B[10];
    int i= beg, j= mid+1, k=beg ,p;
    while(i<=mid && j<=end)
    {
        if(A[i]<=A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else
        {
            B[k]=A[j];
            j++;
            k++;
        }
        
    }
    if(i>mid)
    {
        for(p=j;p<=end;p++)
        {
            B[k]=A[p];
            k++;
        }
    }
    if(j>end)
    {
        for(p=i;p<=mid;p++)
        {
            B[k]=A[p];
            k++;
        }
    }
    for(p=beg;p<=end;p++)
     A[p]=B[p];
}
void mergesort(int beg, int end)
{
    if(beg<end)
    {
        int mid= (int)((beg+end)/2);
        mergesort(beg,mid);
        mergesort(mid+1, end);
        merge(beg ,mid, end);
    }
}
void main()
{
    int i;
    printf("Enter the elements=");
    for(i=0;i<max;i++)
      scanf("%d",&A[i]);
    mergesort(0,max-1);
    printf("After Sorting:");
    for(i=0;i<max;i++)
      printf("%d\t",A[i]);  
}