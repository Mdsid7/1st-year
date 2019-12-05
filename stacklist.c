#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
};
typedef struct node*NODE;
NODE top = NULL;
int count=0, size=10;
NODE getnode()
{
    NODE x;
    x=((NODE)malloc(sizeof(struct node)));
    if(x==NULL)
    {
        printf("memory not available");
        exit(0);
    }
    return x;
}
void push(int item)
{
    if(count==size)
    {
        printf("stack overflow");
        exit(0);
    }
    else
    {
      NODE temp=getnode();
      temp->info=item;
      temp->link=top;
      top=temp;
      count++;
    }  
}
void pop()
{
    if(top==NULL)
    {
        printf("stack underflow");
        exit(0);
    }
    else
    {
        NODE temp=top;
        printf("Deleted item is : %d\n",temp->info);
        top=top->link;
        free(temp);
        count--;
    }
}
void peek()
{
    NODE temp;
    if(top==NULL)
    {
        printf("stack is empty");
        exit(0);
    }
    else
        printf("The top element is : %d\n",temp->info);
}
void isfull()
{
    if(count==size)
      printf("stack is full\n");
    else
      printf("stack is not full\n");
}
void isempty()
{
    if(top==NULL)
      printf("Stack is empty\n");
    else
      printf("Stack is not empty\n");
}
void display()
{
    NODE ptr=top;
    printf("After the operation:\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->link;
    }
}
void main()
{
    int choice,item;
    do
    {
        printf("\nENTER YOUR CHOICE\n1->Push\n2->Pop\n3->Peek\n4->Isfull\n5->Isempty\n0-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   printf("Enter the element:\n");
                   scanf("%d",&item);
                   push(item);
                   display();
                   break;
            case 2:
                   pop();
                   display();
                   break;
            case 3:
                   peek();
                   break;
            case 4:
                   isfull();
                   break;
            case 0:
                   exit(0);
        }
    } while (choice!=0);
}