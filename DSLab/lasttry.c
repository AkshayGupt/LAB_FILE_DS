#include <stdio.h>
#include <stdlib.h>
#define size 1000

//for tree
struct node {
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;


// for deque
struct deque{
    struct node *ptr_data;
    struct deque * prv;
    struct deque * next;
}*front=NULL,*rear=NULL;

//for stack
struct node * stack[size];

int size_deque = 0;
int top=-1;


void q_push_front(struct node *val)
{
    struct deque *q;
    q=(struct deque*)malloc(sizeof(struct deque));
    q->ptr_data = val;
    q->prv = NULL;
    q->next = NULL;

    if(front ==NULL)
    {
        front = rear = q;
    } 
    else
    {
        front->prv = q;
        q->next =front;
        front = front ->prv;
    }
    size_deque++;
}

void q_push_back(struct node *val)
{
    struct deque *q;
    q=(struct deque*)malloc(sizeof(struct deque));
    q->ptr_data = val;
    q->prv = NULL;
    q->next = NULL;

    if(rear ==NULL)
    {
        front=rear =q;
    }
    else{
        rear->next = q;
        q->prv =rear;
        rear=rear->next;
    }
    size_deque++;
}

struct node * q_pop_back()
{
    if(rear == NULL)
    return NULL;
    else if(size_deque == 1)
    {
        struct deque * q = rear;
        front=rear=NULL;
         size_deque--;
         return q->ptr_data;
    }
    else
    {
        struct deque * q = rear;
        rear=rear->prv;
        rear->next = NULL;
        size_deque--;
         return q->ptr_data;
    }
    
}

struct node * q_pop_front()
{
     if(front == NULL)
    return NULL;
    else if(size_deque == 1)
    {
        
        struct deque * q = front;
        front=rear=NULL;
        size_deque--;
        return q->ptr_data;
    }
    else
    {
        struct deque * q = front;
        front=front->next;
        front->prv = NULL;
        size_deque--;
        return q->ptr_data;
    }
  
}

int q_size()
{
    if(front == NULL)
    return 0;
    struct deque *q =front;
    int count = 0;
    while(q != rear)
    {
        q=q->next;
        count++;
    }
    size_deque = ++count;
    return count;
    
}
int q_empty()
{
    return (size_deque == 0);
}

void stk_push(struct node * val)
{
    stack[++top]=val;
}

struct node * stk_pop()
{
    if(top>=0)
    return stack[top--];
    else 
    return NULL;
}
int stk_empty()
{
    return (top == -1);
}


// Function to prints contents of DLL 
void printList(struct node *node) 
{ 
	while (node != NULL) 
	{ 
		
        printf("%d ",node->data);
		node = node->right; 
	} 
} 



/* Given a reference to the head of a list and a node, 
inserts the node on the front of the list. */
void push(struct node** head_ref, struct node* node) 
{ 
	// Make right of given node as head and left as 
	// NULL 
	node->right = (*head_ref); 
	node->left = NULL; 

	// change left of head node to given node 
	if ((*head_ref) != NULL) 
		(*head_ref)->left = node ; 

	// move the head to point to the given node 
	(*head_ref) = node; 
} 

void spiralLevelOrder(struct node *root) 
{ 

	if (root == NULL) 
		return; 

	
	struct deque * q; 
	q_push_front(root); 

	
	int level = 0; 
    while (!q_empty()) 
	{ 
	 
		int nodeCount = q_size(); 
		
		if (level&1) //odd level 
		{ 
			while (nodeCount > 0) 
			{ 
				// dequeue node from front & push it to 
				// stack 
				struct node *node = q_pop_front() ; 				
				stk_push(node); 
				// insert its left and right children 
				// in the back of the deque 
				if (node->left != NULL) 
					q_push_back(node->left); 
				if (node->right != NULL) 
					q_push_back(node->right); 

				nodeCount--; 
			} 
		} 
		else	 //even level 
		{ 
			while (nodeCount > 0) 
			{ 
				// dequeue node from the back & push it 
				// to stack 
				struct node *node = q_pop_back(); 
				stk_push(node); 
				// inserts its right and left children 
				// in the front of the deque 
				if (node->right != NULL) 
					q_push_front(node->right);
				if (node->left != NULL) 
					q_push_front(node->left); 
				nodeCount--; 
			} 
		} 
		level++; 
	} 
    // head pointer for DLL 
	struct node * head = NULL; 

	// pop all nodes from stack and 
	// push them in the beginning of the list 
	while (!stk_empty()) 
	{ 
		push(&head, stk_pop()); 
	} 

	printf("Created DLL is:\n") ; 
	printList(head); 
} 

// Utility function to create a new tree Node 
struct node* newNode(int data) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
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
     t->left=create();
     printf("Enter right child of %d",ele);
     t->right=create();
    return t;
}

// Driver program to test above functions 
int main() 
{  
     root = create();//Creating binaryTree
	spiralLevelOrder(root); 
	return 0; 
} 
