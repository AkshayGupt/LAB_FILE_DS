#include<stdio.h>
#include<stdlib.h>
void display();
void push(int);
void pop();
struct node
{
    int data;
    struct node *ptr;
}*top=NULL,*t,*temp;
int main()
{   int ele,choice;
     do{
        printf("Enter 1.push\n2.pop\n3.Display\n4.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:
            break;
        }
    }while(choice!=4);
    return 0;
}

void push(int ele)
{
    
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    printf("Overflow");
    else
    {
        t->data=ele;
        t->ptr=top;
        top=t;
    }
}

void pop()
{
    if(top==NULL)
    printf("Underflow");
    else
    {
        printf("%d",top->data);
        t=top;
        top=top->ptr;
        free(t);
    }
}
void display()
{
    temp=top;
    while(temp->ptr!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->ptr;
    }
    printf("%d\n",temp->data);
}
