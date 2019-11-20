#include<stdio.h>
#include<stdlib.h>
int ele;
struct node
{
    int data;
    struct node *ptr;
}*front=NULL,*rear=NULL,*t;
int main()
{
     int choice;
    // printf("\nEnter the number of elements");
    // scanf("%d",&n);
    // q=(int *)malloc(sizeof(int)*n);
    while(1)
    {
        printf("\nEnter\n1.Insertion\n2.Deletion\n3.Display\n4.exit\n");
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
    printf("Enter the element to be inserted");
    scanf("%d",&ele);
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    printf("Overflow");
    else if(rear==NULL)
    {
        front=rear=t;
        t->data=ele;
        t->ptr=NULL;

    }
    
    else
    {
        rear->ptr=t;
        rear=t;
        t->data =ele;
        t->ptr=NULL;
    }
}

void delete()
{
    if(front == NULL)
    printf("Underflow");
    else if(front == rear)
    {
        printf("%d",front->data);
        free(front);
        front=rear=NULL;
    }
    else
    {
        printf("%d",front->data);
        t=front;
        front=front->ptr;
        free(t);
    }
}

void display()
{
   
    t=front;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->ptr;
    }
    //printf("%d ",t->data);
}
