#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*lc;
    struct node*rc;
}*root1;
int max=0;
int main()
{

     int choice;
     int element;
     int res;
    while(1)
    {
        printf("\nEnter 1.insertion\n2.Deletion\n3.Display\n4.search\n5.sort\n6.find maximum\n7.find minimum\n8.find height\n9.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter element");
                  scanf("%d",&element);
                root1 = insert(root1,element);
            break;
            case 2:printf("Enter element");
                  scanf("%d",&element);
                  root1 = delete(root1,element);
            break;
            case 3:Inorder(root1);  
            break;
            case 4:printf("Enter element");
                  scanf("%d",&element);
                     search(root1,element);
                   
            break;
            case 5:PostOrder(root1);
            break;
            case 6: res=findMax(root1);
            printf("%d",res);
            break;
            case 7:res=findMin(root1);
            printf("%d",res);
            break;
            case 8:res=maxDepth(root1);
            printf("%d",res);
            break;
            case 9:exit(0);
            break;
            default: printf("Wrong ");
        }
    }
return 0;
}

struct node * insert(struct node *root1,int ele)
{
    struct node*t;
    if(root1!=NULL)
    {
        t=(struct node *)malloc(sizeof(struct);
        t->data=ele;
        t->lc=t->rc=NULL;
        return t;
    }
    else if(ele>root1->data)
    root1->rc=insert(root1->rc,ele);
    else if(ele<root1->data)
    root1->lc=insert(root1->lc,ele);
    return root1;
}

struct node *delete(struct node*root1,int ele)
{
    if(root1 == NULL)
    {
        printf("NOT FOUND");
        return root1;
    }
    else if(ele>root1->data)
    root1->rc=delete(root1->rc,ele);
    else if(ele<root1->data)
    root1->lc=delete(root1->lc,ele);

    else
    {

        //check if it has right child
       if (root->rc == NULL)
        {
            struct  node *t;
            t=root1->lc;
            free(root1);
            return t;
        }

        //check if it has left child
        else if(root->lc == NULL)
        {
            struct  node *t;
            t=root1->rc;
            free(root1);
            return t;
        }
         struct node *t1;
    t1=minValue(root1->rc);
    root1->data=t1->data;
    root1->rc=delete(root1->rc,t1->data);
    }
   
    return root1;
}


void search(struct node* root, int ele) 
{ 
	 
	if (root == NULL)
	printf("Not Found"); 
    if (root->data == ele)
    printf("Found");
	
	// element is greater than root's data 
	if (root->data < ele) 
	return search(root->right, ele); 

	// element is smaller than root's data 
	return search(root->left, ele); 
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
int findMax(struct Node* root) 
{ 
    // Base case 
    if (root == NULL) 
      return INT_MIN; 

    int res = root->data; 
    int lres = findMax(root->left); 
    int rres = findMax(root->right); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
} 


int findMin(struct Node* root) 
{ 
    // Base case 
    if (root == NULL) 
      return INT_MAX; 
  
    
    int res = root->data; 
    int lres = findMin(root->left); 
    int rres = findMin(root->right); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
} 

int maxDepth(struct node *t)
{
    if(t == NULL)
    return 0;

    else
    {
        int ld,rd;
        ld=maxDepth(t->lc);
        rd=maxDepth(t->rc);
        if(ld>rd)
        return ld+1;
        else
        return rd+1;
    }
}



