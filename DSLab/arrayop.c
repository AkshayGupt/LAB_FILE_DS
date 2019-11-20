#include <stdio.h>
#include <stdlib.h>
void create();
void insert();
void delete();
void print();
void search();
void update();
void exit();
int *arr;
int choice;
int n,i;
int exitc=1;
void exitm();
int main()
{	
	printf("Enter your choice:\n");
	printf("1. create \n2. insert\n3. delete\n4. print\n5. search\n6. update\n7. exit\n");	
	scanf("%d",&choice);

	
	while(exitc)
	{	
		switch(choice)
		{
			case 1:create();
			break;
			case 2:insert();
			break;
			case 3:delete();
			break;
			 case 4:print();
			 break;
			case 5:search();
			break;
			case 6:update();
			break;
			case 7:exitm();
			break;
			default:printf("Wrong Choice!");
		}
		if(exitc!=0)
		{
			printf("1. create \n2. insert\n3. delete\n4. print\n5. search\n6. update\n7. exit\n");	
			scanf("%d",&choice);
		}
	}
	return 0;
}


void create()
{	
	
	printf("Enter the size of array: ");
	scanf(" %d",&n);

	arr=(int*)calloc(n,sizeof(int));
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&arr[i]);
	}
	printf("\n");
}

void insert()
{	
	int pos,e;
	printf("Enter the position and the element: ");
	scanf(" %d %d",&pos,&e);
	if(pos>n)
	{
	printf("wrong position inserted\narray size is less than your entered position\nRetry\n");
	return;
	}	
	arr = realloc(arr, (n+1) * sizeof(int));
	n++;
	for(i=n-1;i>pos-1;i--)
	{
		arr[i]=arr[i-1];
	} 
	arr[i]=e;
	printf("Element inserted\n");
}

void delete()
{
	int pos;
	printf("Enter the position: ");
	scanf("%d",&pos);
		if(pos>n)
	{
	printf("wrong position inserted\narray size is less than your entered position\nRetry\n");
	return;
	}
	for(i=pos-1;i<n-1;i++)
	{
		arr[i]=arr[i+1];
	}
	arr=realloc(arr,(n-1)*sizeof(int));
	n--;
	printf("Element deleted \n");
}

void print()
{
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	printf("\n");
}

void search()
{	
	int ele;
	int count=0;
	printf("Enter the element to be searched: ");
	scanf(" %d",&ele);
	for(i=0;i<n;i++)
	{
		if(arr[i]==ele)
		{
			count=1;
			printf("Element found at position: %d\n",i+1);
			break;
		}
	}
	if(count==0)
	printf("Not found\n");
}

void update()
{
	printf("Enter the size of new array: ");
	scanf(" %d",&n);
	arr=(int*)calloc(n,sizeof(int));
	printf("Enter the elements");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&arr[i]);
	}
	printf("New array created\n");
}
void exitm()
{
	exitc=0;
	printf("Bye\n");
}