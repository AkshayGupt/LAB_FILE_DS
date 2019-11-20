#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lc,*rc;
}*root=NULL;
int x=0;
struct node * create();

void Inorder();
void PreOrder();
void PostOrder();
int search();
int ele;

int main()
{
   root=create();
   int choice;
    while(1)
    {
        printf("\nEnter 1.Inorder\n2.PreOrder\n3.PostOrder\n4.search\n5.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:Inorder(root);
            break;
            case 2:PreOrder(root);
            break;
            case 3:PostOrder(root);
            break;
            case 4:
                    printf("Enter the element");
                    scanf("%d",&ele);
                   int res=search(root);
                   if(x == 1) printf("Found\n");
                   if(x == 0) printf("Not Found\n");
            break;
            case 5:exit(0);
            break;
            default: printf("Wrong ");
        }
    }
}

struct node * create()
{
    int ele; struct node *t;
      printf("Enter data (if no enter -1)");
      scanf("%d",&ele);
      if(ele==-1)
      return NULL;
     t=(struct node*) malloc(sizeof(struct node));
     t->data=ele;
     printf("Enter left child of %d",ele);
     t->lc=create();
     printf("Enter right child of %d",ele);
     t->rc=create();

    return t;
}

void Inorder(struct node *t)
{
    if(t==NULL)
    return;
    Inorder(t->lc);
    printf("%d",t->data);
    Inorder(t->rc);
}
void PreOrder(struct node *t)
{
    if(t==NULL)
    return;
     printf("%d",t->data);
    PreOrder(t->lc); 
    PreOrder(t->rc);
}
void PostOrder(struct node *t)
{
    if(t==NULL)
    return;
    PostOrder(t->lc);
    PostOrder(t->rc);
    printf("%d",t->data);
}

int search(struct node *rt,int ele)
{   
    if(rt == NULL)
    return 0;
    if(rt->data == ele)
    {x=1;
    return 1;}
    else if(x!=1)
    {
    int left=search(rt->lc,ele);
    int right=search(rt->rc,ele);
    }
    return 0;
}