#include<stdio.h>
int *q;
int front=-1;
int rear=-1;
int i;
int ele;
int n;
int main()
{       int choice;
    printf("\nEnter the number of elements");
    scanf("%d",&n);
    q=(int *)malloc(sizeof(int)*n);
    while(1)
    {
        printf("\nEnter 1.Insertion\n2.Deletion\n3.Display");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default: printf("Wrong ");
        }
    }
    return 0;
}

void insert()
{
    printf("Enter the element to be inserted\n");
    scanf("%d",&ele);
    if((rear+1)%n==front)
    {
        printf("Overflow");
    }
    else if(rear==-1)
    {
        front=rear=0;
        q[rear]=ele;
    }
    else
    {
        rear=(rear+1)%n;
        q[rear]=ele;
    }
}

void delete()
{
    if(front==-1)
    printf("Underflow");
    else if(front == rear)
    {
        printf("%d",q[rear]);
        front=rear=-1;
    }
    else
    {
        printf("%d",q[front]);
        front=(front+1)%n;
    }
}

void display()
{
    if(front>rear)
    {
        for(i=front;i<n;i++)
        printf("%d ",q[i]);
        for(i=0;i<=rear;i++)
        printf("%d ",q[i]);
    }
    else
    {
        for(i=front;i<=rear;i++)
        printf("%d ",q[i]);
    }
}