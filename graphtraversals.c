#include<stdio.h>
#include<stdlib.h>
int top=-1,front=-1,rear=-1,n=4,a[4],status[4];
int G[4][4]={{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};
void push(int p)
{
    top=top+1;
    a[top]=p;
}
void pop()
{
    printf("%d->",a[top]);
    top=top-1;
}
void insert(int item)
{
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
      rear=rear+1;
    a[rear]=item;  
}
void del()
{
    printf("%d->",a[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
      front=front+1;    
}
void dfs(int p)
{
    int i,k;
    for(i=0;i<n;i++)
      status[i]=1;
    push(p);
    status[p]=2;
    while(top!=-1)
    {
        status[a[top]]=3;
        k=a[top];
        pop();
        for(i=0;i<n;i++)
        {
            if(G[k][i]==1 && status[i]==1)
            {
                push(i);
                status[i]=2;
            }
        }
    }  
}
void bfs(int p)
{
    int i,k;
    insert(p);
    status[p]=2;
    while(front!=-1 && rear!=-1)
    {
        status[a[front]]=3;
        k=a[front];
        del();
        for(i=0;i<n;i++)
        {
            if(G[k][i]==1 && status[i]==1)
            {
                insert(i);
                status[i]=2;
            }
        }
    }
}
void bst()
{
    int i;
    for(i=0;i<n;i++)
      status[i]=1;
    for(i=0;i<n;i++)
    {
        if(status[i]==1)
          bfs(i);
    }
}
int main()
{
    int choice;
    printf("\nENTER THE GRAPH TRAVERSAL\n1->Bfs\n2->Dfs\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
               printf("the bfs is : \n");
               bst();
               break;
        case 2:
               printf("the dfs is: \n");
               dfs(0);
               break;
    }
    return 0;
}

