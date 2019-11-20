#include<stdio.h>
#include<stdlib.h>



struct node {
    int data;
    struct node *next;
}*start=NULL,*start1=NULL,*start2=NULL,*t,*last=NULL,*last1=NULL,*last2=NULL,*temp;

void display(struct node *start);
void split(struct node* start,struct node *start1,struct node *start2);
int i,n;
int main()
{
    
    printf("Enter the number of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&t->data);
        t->next=NULL;
        if(start==NULL)
        {
            start=t;
            last=t;
        }
        else{
            last->next=t;
            last=last->next;
        }
    }
    split(start,start1,start2);
   
    return 0;
}

void split(struct node* start,struct node* start1,struct node* start2)
{   
    temp=start;
  for(i=0;i<n;i++)
    {
        if(temp->data%2==0)
        {
            if(start2==NULL)
            {
                start2=temp;
                last2=temp;
            }
            else
            {
                last2->next=temp;
                last2=last2->next;
            }
        }

       else
        {
            if(start1==NULL)
            {
                start1=temp;
                last1=temp;
            }
            else
            {
                last1->next=temp;
                last1=last1->next;
            }
        }
        temp=temp->next;
    }
    last2->next=NULL;
    last1->next=NULL;


    printf("\nOdd Linked List\n");
 display(start1);
 printf("Even Linked List\n");
    display(start2);
    
}

void display(struct node *start)
{   
    temp=start;
    while(temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d->null",temp->data);
    printf("\n\n");
}