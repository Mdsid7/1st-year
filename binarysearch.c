#include<stdio.h>
#include<stdlib.h>
int mid;
int binary(int n,int a[n],int ele,int b,int e)
{
    int f=-1; //temp variable
    mid=(b+e)/2;
    while(b<=e)
    {
        if(a[mid]==ele)
        {
            f=mid;
            break;
        }
        else if(a[mid]>ele)
        {
          e=mid-1;
          binary(n,a,ele,b,e);
        }    
        else
        {
          b=mid+1;  
          binary(n,a,ele,b,e);
        }    
    }
    return f;
}
void display(int n,int a[n],int f)
{
    if(f<0)
      printf("ELement does not exist");
    else
      printf("Element %d found at position %d",a[f],f+1);
}
int main()
{
    int n,ele;
    printf("\nEnter the no of elements:\n");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the sorted elements:\n");
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    printf("\nEnter the element to be searched:\n");
    scanf("%d",&ele);
    int e=binary(n,a,ele,0,n-1);
    display(n,a,e);
    return 0;  
}
