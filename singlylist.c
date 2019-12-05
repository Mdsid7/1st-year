#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
};
typedef struct node*NODE;
NODE start = NULL;
int count=0;
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
void insertatbeg(int item)
{
    NODE temp=getnode();
    temp->info=item;
    temp->link=start;
    start=temp;
}
void insertatposi(int item,int posi)
{
    NODE temp=getnode();
    temp->info=item;
    count=1;
    if(posi==1)
    {
        temp->link=start;
        start=temp;
    }
    else
    {
        NODE ptr=start;
        while(count<posi-1)
        {
            ptr=ptr->link;
            count++;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}
void insertatend(int item)
{
    NODE temp=getnode();
    NODE loc,locp;
    if(start==NULL)
    {
        temp->link=start;
        temp->info=item;
        start=temp;
    }
    else
    {
        locp=NULL;
        loc=start;
        while(loc->link!=NULL)
        {
            locp=loc;
            loc=loc->link;
        }
        temp->info=item;
        loc->link=temp;
        temp->link=NULL;
    }
}
void deleteatbeg()
{
    NODE temp=start;
    if(start==NULL)
    {
      printf("list is empty");
      exit(0);
    }  
    else
    {
        start=start->link;
        free(temp);
    }
}
void deleteatposi(int posi)
{
    NODE locp,loc;
    if(start==NULL)
    {
      printf("list is empty");
      exit(0);
    }
    else
    {
        printf("Enter the position:\n");
        scanf("%d",&posi);
        if(posi==1)
        {
            locp=NULL;
            loc=start;
        }
        else
        {
            locp=start;
            loc=start->link;
            count=2;
            while(count!=posi)
            {
                locp=loc;
                loc=loc->link;
                count++;
            }
            if(locp==NULL)
            start=loc->link;
            else
            {
                locp->link=loc->link;
                free(loc);
            }
        }
    }     
}
void deleteatend()
{
    NODE locp,loc;
    if(start==NULL)
    {
      printf("list is empty");
      exit(0);
    }
    else
    {
        if(start->link==NULL)
        {
            loc=start;
            start=NULL;
        }
        else
        {
            locp=start;
            loc=start->link;
            while(loc->link!=NULL)
            {
                locp=loc;
                loc=loc->link;
            }
            if(locp==NULL)
              start=NULL;
            else
            {
                locp->link=NULL;
                free(loc);
            }
        }
    }
}
void traverse()
{
    NODE ptr=start;
    if(ptr==NULL)
    {
        printf("list is empty");
        exit(0);
    }
    else
    {
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
    int choice,item,posi;
    do
    {
        printf("\n ENTER YOUR CHOICE:\n1->Insertion_at_beg\n2->Insertion_at_position\n3->Insertion_at_end\n4-Deletion_at_beg\n5->Deletion_at_position\n6->Deletion_at_end\n0->Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   printf("Enter the element:\n");
                   scanf("%d",&item);
                   insertatbeg(item);
                   traverse();
                   break;
            case 2:
                   printf("Enter the element:\n");
                   scanf("%d",&item);
                   printf("Enter the position:\n");
                   scanf("%d",&posi);
                   insertatposi(item,posi);
                   traverse();
                   break;
            case 3:
                   printf("Enter the element:\n");
                   scanf("%d",&item);
                   insertatend(item);
                   traverse();
                   break;
            case 4:
                   deleteatbeg();
                   traverse();
                   break;
            case 5:
                   deleteatposi(posi);
                   traverse();
                   break;
            case 6:
                   deleteatend();
                   traverse();
                   break;
            case 0:
                   exit(0);       
        }
    } while (choice!=0);
}