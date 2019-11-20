#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();

struct node
{
    int data ,pri;
    struct node *ptr;

}*start=NULL,*t,*t1,*t2;


int main()
{   
    int num,n,choice,i;

    do{
        printf("Enter \n  1. Insert\n 2. Delete\n 3.exit");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insert();
            break;
            case 2: delete();
            break;
        }
    }
    while(choice!=3);
    
    return 0;
}

void insert()
{
  int ele,prio;
    printf("Enter the element and the priority");
    scanf("%d %d",&ele,&prio);
    t=(struct node*) malloc(sizeof(struct node));
    if(t==NULL)
    printf("Overflow");
    else if(start==NULL ||start->pri>prio)
    {
        t->data=ele;
        t->pri=prio;
        t->ptr=start;
        start=t;
    }

    else
    {
        for(t1=start;t1!=NULL&&t1->pri<=prio;t1=t1->ptr)
        {
            t2=t1;
            t1=t1->ptr;
        }
        t->data=ele;
        t->pri=prio;
        t1->ptr=t2->ptr;
        t2->ptr=t;
    }
}


void delete()
{
    if(start!=NULL)
    {
        printf("%d",start->data);
        start=start->ptr;
    }
}