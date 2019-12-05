#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*llink;
    struct node*rlink;
};
typedef struct node*NODE;
NODE root=NULL;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d",root->info);
        inorder(root->rlink);
    }
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d",root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d",root->info);
    }
}
void insert(int item)
{
    NODE temp=getnode();
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
      root=temp;
    else
    {
        NODE prev;
        NODE ptr=root;
        while (ptr!=NULL)
        {
            prev=ptr;
            if(item<ptr->info)
              ptr=ptr->llink;
            else
              ptr=ptr->rlink;
        } 
        if(item<prev->info)
          prev->llink=temp;
        else
          prev->rlink=temp;
    }
}
void main()
{
    int n,i,item;
    printf("\nHow many elements you want to insert:\n");
    scanf("%d",&n);
    printf("Enter the item:\n");
    for(i=1;i<=n;i++)
    {   
        scanf("%d",&item);
        insert(item);
    }
    printf("\nInorder\n");
    inorder(root);
    printf("\nPreorder\n");
    preorder(root);
    printf("\nPostorder\n");
    postorder(root);
}
