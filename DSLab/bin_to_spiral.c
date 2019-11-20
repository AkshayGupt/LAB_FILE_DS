#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left; //also left side
    struct node *right; //also right side
};


int size = 1000;
struct node * stack[1000];

struct node * deque[1000];
int d_front = -1;
int d_back = -1;

struct node* push_front(struct node* Node){
    if(front==rear && front!=-1 && (d_front+1)==size){
        return NULL;
    }else if(){
        deque[++d_front] = Node;
    }
}

struct node* pop_back(strcut node* Node){

}

void push(struct node** head_ref, struct node* Node){
    Node->right = (*head_ref);
    Node->left = NULL;

    if((*head_ref) != NULL)
        (*head_ref)->left = Node;
    (*head_ref) = Node;
}

void printList(struct node * Node){
    while(Node!=NULL){
        printf("%d ",Node->data);
        Node = Node->right;
    }
}

void spiralLevelOrder(struct node* root){
    if(root == NULL)
        return;
    
}

int main(){


    return 0;
}