#include<stdio.h>
#include<stdlib.h>
void display();
int* push(int *arr,int size,int *top,int ele);
int* pop(int *arr,int *top);




int main()
{   
    // int size;
    int choice;
    int top=-1;
    int *arr;
    int ele;
    int size;
    printf("Enter the size of Stack");
    scanf("%d",&size);
    arr=(int*)malloc(sizeof(int)*size);
    do{
        printf("\nEnter 1.push\n2.pop\n3.Display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element");
                    scanf("%d",&ele);
                   arr=push(arr,size,&top,ele);
                    break;
            case 2:arr=pop(arr,&top);
                    break;
            case 3:display(arr,&top);
                    break;
            case 4:
            break;
        }
    }while(choice!=4);
    return 0;
}

int * push(int *arr,int size,int *top,int ele)
{
    if(*top==size-1)
    {
        printf("Sorry!,Stack is Full\n");
    }

    else
    {   (*top)++;
        arr[*top]=ele;
        printf("Element Pushed\n");
    }
    return arr;
}

int * pop(int *arr,int *top)
{
    if((*top)==-1)
    printf("Stack is Empty\n");
    else
    {
        printf("%d is deleted\n",arr[(*top)--]);
    }
    return arr;
}

void display(int *arr,int *top)
{
    int i;
    printf("Elements:\n");
    for(i=0;i<=*top;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
