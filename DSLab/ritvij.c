#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
    struct node *next;
};

struct node *front = NULL, *rear = NULL; // for DEQUE
struct node *top = NULL; //for STACK
struct node *head = NULL; // for Doubly Linked List
struct node *root = NULL; //For Binary Tree

int size_deque = 0; //Deque Size
int size_stack = 0; //Stack Size


/**DEQUE METHODS*/

void push_front(struct node *newNode){
    
    if(front == NULL){
        front = rear = newNode;
    }else{
        newNode->right = front;
        newNode->left = newNode;
        front = newNode;
    }
    size_deque += 1;
}

void push_rear(struct node *newNode){
    if(rear == NULL){
        front = rear = newNode;
    }else{
        newNode->left = rear;
        rear->right = newNode;
        rear = newNode;
    }
    size_deque += 1;
}

struct node* pop_front(){
    if(front == NULL)
        return NULL;
    else{
        struct node *temp = front;
        front = front->right;
        if(front== NULL ){
            rear = NULL;
        }else{
            front->left = NULL;            
        }
        if(size_deque > 0)
            size_deque -= 1;
        return temp;
    }
}

struct node* pop_rear(){
    if(front == NULL)
        return NULL;
    else{
        struct node *temp = rear;
        rear = rear->left;
        if(rear == NULL){
            front = NULL;
        }
        else{
            rear->right = NULL;
        }
        if(size_deque > 0)
            size_deque -= 1;
        return temp;
    }
}

int isDequeEmpty(){
    if (front == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}
/**END OF DEQUE METHODS*/


/** STACK FUNCTIONS*/

void push(struct node *newNode){
    newNode->next = top;
    top = newNode;
    size_stack += 1;
}

struct node* pop(){
    struct node *temp;
    if (top == NULL)
    {
        return NULL;
    }else{
        temp = top;
        top = top->next;
        temp->next = NULL;
        if(size_stack > 0)
            size_stack -= 1;
        return temp;
    }
}

int isStackEmpty(){
    if(top == NULL)
        return 1;
    else
        return 0;
}
/**END OF STACK FUNCTIONS*/


/**PRINT LIST*/
void printList(){
    struct node *temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->right;
    }
}

/**END OF PRINT LIST*/


/**SPIRAL LEVEL ORDER*/
void spiralLevelOrder(){
    if(root == NULL){
        return;
    }

    push_front(root);

    int level = 0;

    while(isDequeEmpty() != 1){    
        int nodeCount = size_deque;

        if(level &  1){
            while(nodeCount > 0){

                struct node *temp;
                temp = pop_front();

                push(temp);

                if(temp->left!=NULL)
                    push_rear(temp->left);
                if(temp->right!=NULL)
                    push_rear(temp->right);

                nodeCount -= 1;
            }
        }else{
            while(nodeCount > 0){

                struct node *temp;
                temp = pop_rear();

                push(temp);

                if(temp->right !=NULL)
                    push_front(temp->right);
                if(temp->left !=NULL)
                    push_front(temp->left);
                nodeCount -= 1;
            }
        }
        level += 1;
    }

    head = NULL;

    while(isStackEmpty() != 1){
        struct node *temp = pop();
        push(temp);
    }

    printf("DLL CREATED\n");
    printList();
}
/**END OF SPIRAL LEVEL ORDER*/


/**CREATE BINARY TREE*/
struct node* newNode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
/**END OF BINARY TREE*/


/**DRIVER CODE*/
int main(){

    root =  newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    //root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    //root->right->right->right  = newNode(15); 

    spiralLevelOrder();

    return 0;
}