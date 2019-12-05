#include<stdio.h>
#include<ctype.h>
int max=10,top=-1,stack[10];
void push(int item)
{
    stack[++top]=item;
}
int pop()
{
    return stack[top--];
}
void main()
{
    int i;
    char exp[20],*e;
    int n1,n2,n3;
    printf("Enter the expression : use these operands '+','-'.'*','/' \n");
    scanf("%s",exp);
    for(e=exp;*e!='\0';e++)
    {
        if(isdigit(*e))
        {
            push(*e-'0');
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(*e)
            {
                case '+' :
                          n3=n2+n1;
                          break;
                case '-' :
                          n3=n2-n1;
                          break;
                case '*' :
                          n3=n2*n1;
                          break;
                case '/' :
                          n3=n2/n1;
                          break;                             
            }
            push(n3);
        }
    }
    printf("result is = %d",stack[top]);
}