
#include<stdio.h> 
#include<stdlib.h> 


struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 


int max(int a, int b); 

int height(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 


struct Node* newNode(int key) 
{ 
	struct Node* node = (struct Node*) 
						malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; 
	return(node); 
} 


struct Node *rightRotate(struct Node *y) 
{ 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	// Return new root 
	return x; 
} 


struct Node *leftRotate(struct Node *x) 
{ 
	struct Node *y = x->right; 
	struct Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	// Return new root 
	return y; 
} 
int getBalance(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 


struct Node* insert(struct Node* node, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else // Equal keys are not allowed in BST 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	
	int balance = getBalance(node); 



	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

struct Node * minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct Node* deleteNode(struct Node* root, int key) 
{ 
   
    if (root == NULL) 
        return root; 
  
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
  
   
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
  
   
    else
    { 
       
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct Node *temp = root->left ? root->left : 
                                             root->right; 
  
            
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
             *root = *temp;  
            free(temp); 
        } 
        else
        { 
          
            struct Node* temp = minValueNode(root->right); 
  
            
            root->key = temp->key; 
  
          
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 
  
   
    if (root == NULL) 
      return root; 
  
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
  
   
    int balance = getBalance(root); 
  
   
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
  
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
   
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
}


void preOrder(struct Node *root) 
{ 
	if(root != NULL) 
	{ 
		printf("%d ", root->key); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 


int main() 
{ 
struct Node *root = NULL; 

/* Constructing tree given in the above figure */
    int choice;
    int ele;
while(1)
{


printf("\nEnter\n 1.insert \n 2.delete\n 9.Exit\n");
scanf("%d",&choice);
if(choice == 1)
{
    printf("Enter the element to be inserted");
    scanf("%d",&ele);
    root=insert(root,ele);
    preOrder(root); 

}
else if(choice == 2)
{
     printf("Enter the element to be deleted");
    scanf("%d",&ele);
    root=deleteNode(root,ele);
    preOrder(root); 

}
else
{
    exit(0);
}
}

return 0; 
} 
