#include<stdio.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
      return 1;
    else
      return stack[top--];
}
int priority(char x)
{
    if(x=='+' || x=='-')
      return 1;
    else if(x=='*' || x=='/')
      return 2;
    else if(x=='^')
      return 3;
    else return 0;      
}
int main()
{
    char exp[20],*e,x;
    printf("Enter the expression=\n");
    scanf("%s",exp);
    for(e=exp;*e!='\0';e++)
    {
        if(isalnum(*e))
          printf("%c",*e);
        else if(*e=='(')
          push(*e);
        else if(*e==')')
        {
            while((x=pop())!='(')
              printf("%c",x);
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
              printf("%c",pop());
            push(*e);  
        }
    }
    while(top!=-1)
      printf("%c",pop());
    return 0;  
}