#include<stdio.h>
void TOH(int n,char S,char M,char D);
int main()
{   
    int n;
    printf("Enter number of Disks");
    scanf("%d",&n);
   
    TOH(n,'A','B','C');
    return 0;
}

void TOH(int n,char S,char M,char D)
{
    if(n==1)
    printf("\nMove %d disk from %c to %c",n,S,D);
    else
    {
        TOH(n-1,S,D,M);
        printf("\nMove %d disk From %c to %c",n,S,D);
        TOH(n-1,M,S,D);
    }
}