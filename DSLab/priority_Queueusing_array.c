#include<stdio.h>
#include<stdlib.h>
#define size 10
void delete();
void insert();
int *arr[5];
int *fr[5];
int main()
{   
    int num,n,choice,i;


    for (i=0; i<5; i++) 
         arr[i] = (int *)malloc(10 * sizeof(int)); 
    for (i=0; i<5; i++) 
         fr[i] = (int *)malloc(10 * sizeof(int)); 
  
    for(int i=0;i<5;i++)
    {
        printf("Enter the number of elements with priority%d",i);
        scanf("%d",&n);
        if(n>0)
        {
            fr[i][0]=0;
            fr[i][1]=n-1;

        }
        for(int j=0;j<n;j++)
        scanf("%d",&arr[i][j]);
    }

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
    if((fr[prio][1]+1)%size == fr[prio][0])
    printf("OverFlow");
    else if(fr[prio][1]== -1)
    {
        fr[prio][0] =fr[prio][1]=0;
        arr[prio][0]=ele;
    }
    else
    {
        fr[prio][1]=(fr[prio][1]+1)%size;
        arr[prio][fr[prio][1]]=ele;
    }
    
}


void delete()
{
     int ele,prio,i;
    for(i=0;i<size;i++)
    {
        if(fr[i][0] != -1)
        {
            if(fr[i][0] == fr[i][1])
            {
                printf("%d",arr[i][fr[i][0]]);
                fr[i][0] = fr[i][1]=-1;
            }
            else
            {
                printf("%d",arr[i][fr[i][0]]);
                fr[i][0] = (fr[i][0]+1)%size;
            }
            break;
        }
    }

    if(i==size)
    printf("Underflow");
}