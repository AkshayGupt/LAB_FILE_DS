#include<stdio.h>
#include<stdlib.h>
void display();
void push();
void pop();

int top=-1;
int *arr;
int ele;
int size;

int main()
{   
    // int size;
    int choice;
    printf("Enter the size of Stack");
    scanf("%d",&size);
    arr=(int*)malloc(sizeof(int)*size);
    do{
        printf("Enter 1.push\n2.pop\n3.Display\n4.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element");
                    scanf("%d",&ele);
                    push();
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

void push()
{
    if(top==size-1)
    {
        printf("Sorry!,Stack is Full\n");
    }

    else
    {   top++;
        arr[top]=ele;
        printf("Element Pushed\n");
    }
}

void pop()
{
    if(top==-1)
    printf("Stack is Empty\n");
    else
    {
        printf("%d is deleted\n",arr[top--]);
    }
}

void display()
{
    int i;
    printf("Elements:\n");
    for(i=0;i<=top;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
