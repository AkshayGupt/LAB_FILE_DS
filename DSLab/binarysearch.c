#include<stdio.h>
int binarySearch(int a[],int ele,int ,int);
int mid;
int main()
{   int n,ele,i;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&ele);

    int loc=binarySearch(arr,ele,0,n-1);
    if(loc==-1)
    {
        printf("Element not found");
    }
    else{
        printf("element found at position : %d",loc+1);
    }
    return 0;
}

int binarySearch(int arr[],int ele,int l,int u) 
{
    
    if(l<=u)
    {
        mid=(l+u)/2;
        if(ele>arr[mid]){
        l=mid+1;
         return binarySearch(arr,ele,l,u);}
        if(ele<arr[mid]){
        u=mid-1;
         return binarySearch(arr,ele,l,u);}
        else
        return mid;

       
    }
    else
    {
        return -1;
    }
}