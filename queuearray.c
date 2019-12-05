#include<stdio.h>
#include<stdlib.h>
int rear=-1 ,front=-1, n=100, a[100];
void enqueue()
{
    int item;
    printf("Enter the item:\n");
    scanf("%d",&item);
    if(rear==(n-1))
    {
        printf("queue overflow");
        exit(0);
    }
    else if(rear==-1)
    {
        rear=0;
        front=0;
    }
    else
      rear=rear+1;
    a[rear]=item;
    for(int i=front;i<=rear;i++)
    {
        printf("-->%d\n",a[i]);
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue underflow");
        exit(0);
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
      front=front+1;
    for(int i=front;i<=rear;i++)
    {
        printf("-->%d\n",a[i]);
    }
}
void isfull()
{
    if(rear==(n-1))
      printf("the queue is full \n");
    else
      printf("queue is not full\n");
}
void isempty()
{
    if(front==-1)
      printf("the queue is empty\n");
    else
      printf("the queue is not empty\n");
}
void main()
{
    int choice;
    do
    {
        printf("ENTER YOUR CHOICE :\n 1->Enqueue\n 2->Dequeue \n 3->Isfull \n 4->Isempty \n 0->Exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                    enqueue();
                    break;
            case 2 :
                    dequeue();
                    break;
            case 3 :
                    isfull();
                    break;
            case 4 : 
                    isempty();
                    break;
            case 0 :
                    exit(0);                                
        }
    } while (choice!=0);
}