#include<stdio.h>
int priority(char x);
void push(char);
char pop();

char s[101];
int top=-1;

int main()
{
    s[++top]='#';
    char p[100];
    char q[100];
    printf("Enter the expression");
    scanf("%s",p);

    int i=0;
    int j=0;
    char sop;

    while(p[i]!='\0')
    {
        if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/')
        {
            sop=pop();
            while(priority(sop)>=priority(p[i]))
            {
                q[j++]=sop;
                sop=pop();
            }
            push(sop);
            push(p[i]);
        }
        else if(p[i] == '(')
        {
            push('(');
        }
        else if(p[i]==')')
        {
            sop=pop();
            while(sop!='(')
            {
                q[j++]=sop;
                sop=pop();
            }
        }
        else
        {
            q[j++]=p[i];

        }
        
        i++;
    }
    sop=pop();
    while(sop!='#')
    {
        q[j++]=sop;
        sop=pop();
    }
    q[j]='\0';
    printf("%s",q);
    // display(q);
    return 0;
}

int priority(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if (x=='/'||x=='*')
    return 2;
    else
    return 0;
}

void push(char ele)
{   
        s[++top]=ele;

}

char pop()
{
    return s[top--];
}

// void display(char *q)
// {
//     while(q[i]!='\0')
//     {
//         printf("%c")
//     }
// }