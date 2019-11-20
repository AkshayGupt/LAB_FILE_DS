#include<stdio.h>
#include<stdlib.h>
void push(int ele);
int pop();
int *arr;
int top=-1;
int main()
{   
    int i=0;
    char exp[100];
    
    arr=(int*)malloc(sizeof(int)*100);
    int op1,op2;
    printf("Enter the expression");
    scanf("%s",exp);
    while(exp[i]!='\0')
    {
        if(exp[i] == '+'|| exp[i] == '-' || exp[i] == '/' || exp[i] == '*')
        {
            op1=pop();
            op2=pop();
            switch(exp[i])
            {
                case '+' : push(op1+op2);
                break;
                case '-' :push(op1-op2);
                break;
                case '*' :push(op1 * op2);
                break;
                case '/' :push(op1/op2);
                break;
            }
        }
        else
        {
            push(exp[i]- '0');
        }
        i++;
    }

printf("%d",pop());
return 0;
}


void push(int ele)
{
    arr[++top]=ele;
}

int pop()
{
    return arr[top--];
}