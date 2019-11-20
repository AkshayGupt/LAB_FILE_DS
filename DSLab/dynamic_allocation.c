#include<stdio.h>
#include<stdlib.h>
void transpose(int*,int);
int row;
int main()
{   
    int i,j;
    printf("Enter the number of rows or columns: ");
    scanf("%d",&row);
    int *arr[row];
    // arr=(int *)malloc(sizeof(int*)*row);
    for(i=0;i<row;i++)
    {
        *(arr+i)=(int*)malloc(sizeof(int)*row);
    }
    printf("Enter the elements\n");
    for(i=0;i<row;i++)
    {   
        
      for(j=0;j<row;j++)
      {
        //   scanf("%d",&arr[i][j]);
          scanf("%d",(arr+i*row+j));
      }
    }
    transpose(arr,row);
    // for(i=0;i<row;i++)
    // {
    //     for(j=0;j<row;j++)
    //     {
    //         printf("%d ",arr[j][i]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
void transpose(int *arr,int row){
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<row;j++)
        {
            printf("%d",*(arr+j*row+i));
        }
        printf("\n");
    }
    return;
}
