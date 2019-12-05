#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
};
typedef struct node*NODE;
NODE front=NULL,rear=NULL;
int count=0,size=10;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(NULL)
    {
        printf("memory not available\n");
        exit(0);
    }
    return x;
}
void enqueue(int item)
{
    if(count==size)
    {
        printf(" queue overflow");
        exit(0);
    }
    else
    {
        NODE temp=getnode();
        temp->info=item;
        temp->link=NULL;
        if(count==0)
        {
            front=temp;
            rear=temp;
        }
        else
        {
            rear->link=temp;
            rear=temp;
        }
        count++;
    }
}
void dequeue()
{
    if(count==0)
    {
        printf("underflow of queuue\n");
        exit(0);
    }
    else
    {
        NODE temp=front;
        if(count==1)
        {
        rear=NULL;
        front=NULL;
        }
        else
            front=front->link;
            free(temp);
            count--;
    }
    
}
void isempty()
{
    if(count==0)
    {
        printf("list is empty\n");
        exit(0);
    }
    else
    {
        printf("list is not empty\n");
    }
    
}
void isfull()
{
    if(count==size)
    {
        printf("list is full\n");
        exit(0);
    }
    else
    {
        printf("list is not full\n");
    }
    
}
void display()
{
    if(count==0)
    {
        printf("list is empty");
        exit(0);
    }
    else
    {
        NODE ptr=front;
        printf("After operation is performed:\n");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->link;
        }
    }
}
void main()
{
    int choice,item;
    do
    {
        printf("\nENTER YOUR CHOICE\n1->Enqueue\n2->Dequeue\n3->Isfull\n4->Isempty\n0->Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                   printf("enter the item\n");
                   scanf("%d",&item);
                   enqueue(item);
                   display();
                   break;
            case 2:
                  dequeue();
                  display();
                  break;
            case 3:
                   isfull();
                   break;
            case 4:
                  isempty();
                  break;
            case 0:
                   exit(0);
        }
    } while (choice!=0);
}