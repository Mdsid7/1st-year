#include<stdio.h>
#include<stdlib.h>
int max=10,top=-1,stack[10];
int push()
{
    if(top==max-1)
    {
        printf("stack overflow");
        exit(0);
    }
    else
    {
        int item;
        printf("Enter the element to be pushed:\n");
        scanf("%d",&item);
        stack[++top]=item;
        return top;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("stack underflow");
        exit(0);
    }
    else
    {
        int item;
        item=stack[top--];
        return top;
    }
}
void peek()
{
    printf("Top element is %d\n",stack[top]);
}
void isfull()
{
    if(top==max-1)
        printf("stack is full ,cannot insert elements\n");
    else
        printf("stack is not full\n");
}
void isempty()
{
    if(top==-1)
        printf("stack is empty, cannot delete element\n");
    else 
        printf("stack is not empty\n");    
}
void display()
{
    printf("After operation is performed=\n");
    for(int i=0;i<top+1;i++)
    {
        printf("%d\t",stack[i]);
    }
    printf("\n");
}
void main()
{
    int choice;
    do
    {
        printf("ENTER YOUR CHOICE \n 1->Push \n 2->Pop \n 3->Peek \n 4->Isfull \n 5->Isempty \n 0->Exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                    push();
                    display();
                    break;
            case 2 :
                    pop();
                    display();
                    break;
            case 3:
                   peek();
                   break;
            case 4:
                   isfull();
                   break;
            case 5:
                   isempty();
                   break;
            case 0:
                   exit(0);                                     
        }
    } while (choice!=0);
}
