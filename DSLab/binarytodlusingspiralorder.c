// #include<stdio.h>
// #include<stdlib.h>

// int ele;
// struct node{
//     int data;
//     struct node *lc;
//     struct node *rc;
// }*root;

// struct q{
//     struct node * ptr_data;
//     struct q* prv;
//     struct q* next;
// }*q_head=NULL,*q_tail=NULL;


// struct node * stack[1000];
// int top   = -1 ;




// struct node * create(){

//     printf("Enter element (if no enter -1)");
//     scanf("%d",&ele);
//     if(ele == -1)
//     return NULL;
//     struct node*t;
//     t=(struct node*)malloc(sizeof(struct node));
//     t->data = ele;
//     printf("Enter left child of %d ",ele);
//     t->lc = create();
//     printf("Enter right child of %d ",ele);
//     t->rc = create();
//     return t;

// }

// void stack_push(struct node *ptr)
// {
   
//         top++;
//         stack[top]=ptr;
   
// }

// struct node * stack_pop()
// {
   
//         return stack[top--];
    
// }

// int stack_empty()
// {
//     if(top>=0)
//     return 0;
//     else
//     return 1;
// }
// void q_push_back(struct node *ptr)
// {
//     struct q *t;
//     t=(struct q*)malloc(sizeof(struct q));
//     t->ptr_data=ptr;
//     t->prv=q_tail;
//     t->next=NULL;
//     q_tail->next=t;
//     q_tail=t;
// }

// void q_push_front(struct node *ptr)
// {
//     struct q *t;
//     t=(struct q*)malloc(sizeof(struct q));
//     t->ptr_data=ptr;
//     t->next=q_head;
//     t->prv=NULL;
//     q_head=t;
    
// }
// struct node* q_pop_back()
// {
//     struct q* t=q_tail;
//     q_tail=q_tail->prv;
//     return t->ptr_data;
// }
// struct node * q_pop_front()
// {
//     struct q* t=q_head;
//     q_head=q_head->next;
//     return t->ptr_data;
// }

// int q_empty(){
//     if(q_head == NULL)
//     return 1;
//     else 
//     return 0;
// }
// int q_size()
// {
//     struct q*t = q_head;
//     int count=0;
//     if(t == NULL)
//     return count;
//     else
//     {
//          count=1;
//         while(t != q_tail)
//         {
//             count++;
//             t=t->next;
//         }
    
//     }
//    return count;
// }
// // int q_empty()
// // {
// //     if(q_head == NULL)
// //     return 1;
// //     else
// //     return 0;
// // }

// void push(struct node** head_ref, struct node* node) 
// { 
//     // Make right of given node as head and left as 
//     // NULL 
//     node->rc = (*head_ref); 
//     node->lc = NULL; 
  
//     // change left of head node to given node 
//     if ((*head_ref) !=  NULL) 
//         (*head_ref)->lc = node ; 
  
//     // move the head to point to the given node 
//     (*head_ref) = node; 
// } 
// void spiralOrder(struct node *root)
// {
//     if(root == NULL)
//     return;

//     q_push_front(root);
//     int level = 0;
//     while(!q_empty())
//     {
//         printf("Level %d",level);
//         int nodeCount = q_size();

//         if(level%2!=0)//Odd 
//         {
//             while(nodeCount>0)
//             {
//                struct node * temp = q_pop_front();
//                 stack_push(temp);

//                 if(temp->lc != NULL)
//                 q_push_back(temp->lc);
//                 if(temp->rc != NULL)
//                 q_push_back(temp->rc);
                
//                 nodeCount--;
//             }
//         }
//         else//even
//         {
//             while(nodeCount>0)
//             {
//                 struct node *temp = q_pop_back();
//                 stack_push(temp);

//                 if(temp->rc !=NULL)
//                 q_push_front(temp->rc);
//                 if(temp->lc != NULL)
//                 q_push_front(temp->lc);

//                 nodeCount-- ;
//             }

//         }
//         level++;
//     }
//     // head pointer for DLL 
//     struct node * head = NULL; 
//     while (!stack_empty()) 
//     { 
//         push(&head, stack_pop()); 
//     } 

//     // printf("Created DLL is :\n");
//     // printList(head);

// }

// // Function to prints contents of DLL 
// // void printList(struct node *head) 
// // { 
// //     while (head != NULL) 
// //     { 
// //         printf("%d ",head->data);
// //         head = head->rc; 
// //     } 
// // } 
// struct node* newNode(int data) 
// { 
//     struct node *temp = (struct node*)malloc(sizeof(struct node)); 
//     temp->data = data; 
//     temp->lc = temp->rc = NULL; 
  
//     return temp; 
// } 
// int main(){

//     printf(" Please insert the tree! ");
//     // root = create();
//       root =  newNode(1); 
//     root->lc = newNode(2); 
//     root->rc = newNode(3); 
//     root->lc->lc = newNode(4); 
//     root->lc->rc = newNode(5); 
//     root->rc->lc = newNode(6); 
//     root->rc->rc = newNode(7); 
  
//     root->lc->lc->lc  = newNode(8); 
//     root->lc->lc->rc  = newNode(9); 
//     root->lc->rc->lc  = newNode(10); 
//     root->lc->rc->rc  = newNode(11); 
//     //root->rc->lc->lc  = newNode(12); 
//     root->rc->lc->rc  = newNode(13); 
//     root->rc->rc->lc  = newNode(14);
//     spiralOrder(root);
//     return 0;
// }









// #include<stdio.h>
// #include<stdlib.h>
// #define stack_size 100000

// struct node* newNode(int data) ;
// struct node * create();
// void stack_push(struct node *ptr);
// struct node * stack_pop();
// int stack_empty();
// int q_empty();
// void q_push_back(struct node *ptr);
// void q_push_front(struct node *ptr);
// struct node* q_pop_back();
// struct node * q_pop_front();
// int q_size();
// void push(struct node** head_ref, struct node* node);
// void printList(struct node *head) ;
// void spiralOrder(struct node *root);

// int ele;
// struct node{
//     int data;
//     struct node *lc;
//     struct node *rc;
// }*root;

// struct q{
//     struct node * ptr_data;
//     struct q* prv;
//     struct q* next;
// }*q_head=NULL,*q_tail=NULL;


// struct node * stack[100000];
// int top   = -1 ;




// int main(){

//     printf(" Please insert the tree! ");
//     printf(" Inside main ");
//     // root = create();
//       root =  newNode(1); 
//     root->lc = newNode(2); 
//     root->rc = newNode(3); 
//     root->lc->lc = newNode(4); 
//     root->lc->rc = newNode(5); 
//     root->rc->lc = newNode(6); 
//     root->rc->rc = newNode(7); 
  
//     root->lc->lc->lc  = newNode(8); 
//     root->lc->lc->rc  = newNode(9); 
//     root->lc->rc->lc  = newNode(10); 
//     root->lc->rc->rc  = newNode(11); 
//     //root->rc->lc->lc  = newNode(12); 
//     root->rc->lc->rc  = newNode(13); 
//     root->rc->rc->lc  = newNode(14);
//     spiralOrder(root);
//     return 0;
// }
// struct node * create(){

//     printf("Enter element (if no enter -1)");
//     scanf("%d",&ele);
//     if(ele == -1)
//     return NULL;
//     struct node*t;
//     t=(struct node*)malloc(sizeof(struct node));
//     t->data = ele;
//     printf("Enter left child of %d ",ele);
//     t->lc = create();
//     printf("Enter right child of %d ",ele);
//     t->rc = create();
//     return t;

// }

// void stack_push(struct node *ptr)
// {
//     if(top<=stack_size)
//     {
//         top++;
//         stack[top]=ptr;
//     }
        
   
// }

// struct node * stack_pop()
// {
   
//         return stack[top--];
    
// }

// int stack_empty()
// {
//     if(top>=0)
//     return 0;
//     else
//     return 1;
// }
// int q_empty(){
//     if(q_head == NULL)
//     return 1;
//     else 
//     return 0;
// }
// void q_push_back(struct node *ptr)
// {
//     struct q *t;
//     t=(struct q*)malloc(sizeof(struct q));
//     t->ptr_data=ptr;
//     t->prv=q_tail;
//     t->next=NULL;
    
//     if(!q_empty)
//     {
//           q_tail->next=t;
//         q_tail=t;
//     }
//     else
//     {
//         q_head = t; 
//         q_tail = t;

//     }
  
// }

// void q_push_front(struct node *ptr)
// {
//     struct q *t;
//     t=(struct q*)malloc(sizeof(struct q));
//     t->ptr_data=ptr;
//     t->next=q_head;
//     t->prv=NULL;
//     q_head=t;
//     if(q_tail == NULL)
//     q_tail = q_head;
    
// }
// struct node* q_pop_back()
// {
//     if(!q_empty)
//     {
//         struct q* t=q_tail;
//         q_tail=q_tail->prv;
//         return t->ptr_data; 
//     }
//     else
//     {
//         q_head = q_tail = NULL;
//     }
//     return NULL;
    
// }
// struct node * q_pop_front()
// {
//     if(!q_empty)
//     {
//          struct q* t=q_head;
//         q_head=q_head->next;
//         return t->ptr_data;
//     }
   
//      else
//     {
//         q_head = q_tail = NULL;
//     }
//        return NULL;
   
// }


// int q_size()
// {
//     struct q*t = q_head;
//     int count=0;
//     if(t == NULL)
//     return count;
//     else
//     {
//          count=1;
//         while(t != q_tail)
//         {
//             count++;
//             t=t->next;
//         }
    
//     }
    
//    return count;
// }


// void push(struct node** head_ref, struct node* node) 
// { 
//     // Make right of given node as head and left as 
//     // NULL 
//     node->rc = (*head_ref); 
//     node->lc = NULL; 
  
//     // change left of head node to given node 
//     if ((*head_ref) !=  NULL) 
//         (*head_ref)->lc = node ; 
  
//     // move the head to point to the given node 
//     (*head_ref) = node; 
// } 

// // Function to prints contents of DLL 
// void printList(struct node *head) 
// { 
//     while (head != NULL) 
//     { 
//         printf("%d ",head->data);
//         head = head->rc; 
//     } 
// } 

// void spiralOrder(struct node *root)
// {
//     if(root == NULL)
//     return;

//     q_push_front(root);
//     int level = 0;
//     while(!q_empty())
//     {
//         printf("Level %d\n",level);
//         int nodeCount = q_size();

//         if(level%2!=0)//Odd 
//         {
//             while(nodeCount>0)
//             {
//                struct node * temp = q_pop_front();
//                 stack_push(temp);
            
//              if(temp != NULL)
//                 {
//                 if(temp->lc != NULL)
//                 q_push_back(temp->lc);
//                 if(temp->rc != NULL)
//                 q_push_back(temp->rc);
//                 }
                
//                 nodeCount--;
//             }
//         }
//         else//even
//         {
//             while(nodeCount>0)
//             {
//                 struct node *temp = q_pop_back();
//                 stack_push(temp);
//                 if(temp != NULL)
//                 {
//                      if(temp->rc !=NULL)
//                      q_push_front(temp->rc);
//                     if(temp->lc != NULL)
//                     q_push_front(temp->lc);
//                 }
               

//                 nodeCount-- ;
//             }

//         }
//         level++;
//         printf(" Deque %d\n",q_size);
//         printf("***********");
//     }
//     // head pointer for DLL 
//     struct node * head = NULL; 
//     while (!stack_empty()) 
//     { 
//         push(&head, stack_pop()); 
//     } 

//     printf("Created DLL is :\n");
//     printList(head);

// }


// struct node* newNode(int data) 
// { 
//     struct node *temp = (struct node*)malloc(sizeof(struct node)); 
//     temp->data = data; 
//     temp->lc = temp->rc = NULL; 
  
//     return temp; 
// } 






// #include<stdio.h>
// #include<stdlib.h>
// #define stack_size 100000

// struct node* newNode(int data) ;
// struct node * create();
// void stack_push(struct node *ptr);
// struct node * stack_pop();
// int stack_empty();
// int q_empty();
// void q_push_back(struct node *ptr);
// void q_push_front(struct node *ptr);
// struct node* q_pop_back();
// struct node * q_pop_front();
// int q_size();
// void push(struct node** head_ref, struct node* node);
// void printList(struct node *head) ;
// void spiralOrder(struct node *root);

// int ele;
// struct node{
//     int data;
//     struct node *lc;
//     struct node *rc;
// }*root;

// struct q{
//     struct node * ptr_data;
//     struct q* prv;
//     struct q* next;
// }*q_head=NULL,*q_tail=NULL;


// struct node * stack[100000];
// int top   = -1 ;




// int main(){

//     printf(" Please insert the tree! ");
//     printf(" Inside main ");
//     // root = create();
//       root =  newNode(1); 
//     root->lc = newNode(2); 
//     root->rc = newNode(3); 
//     root->lc->lc = newNode(4); 
//     root->lc->rc = newNode(5); 
//     root->rc->lc = newNode(6); 
//     root->rc->rc = newNode(7); 
  
//     root->lc->lc->lc  = newNode(8); 
//     root->lc->lc->rc  = newNode(9); 
//     root->lc->rc->lc  = newNode(10); 
//     root->lc->rc->rc  = newNode(11); 
//     //root->rc->lc->lc  = newNode(12); 
//     root->rc->lc->rc  = newNode(13); 
//     root->rc->rc->lc  = newNode(14);
//     spiralOrder(root);
//     return 0;
// }
// struct node * create(){

//     printf("Enter element (if no enter -1)");
//     scanf("%d",&ele);
//     if(ele == -1)
//     return NULL;
//     struct node*t;
//     t=(struct node*)malloc(sizeof(struct node));
//     t->data = ele;
//     printf("Enter left child of %d ",ele);
//     t->lc = create();
//     printf("Enter right child of %d ",ele);
//     t->rc = create();
//     return t;

// }

// void stack_push(struct node *ptr)
// {
//     if(top<=stack_size)
//     {
//         top++;
//         stack[top]=ptr;
//     }
        
   
// }

// struct node * stack_pop()
// {
//         if(top>=0)
//         return stack[top--];
//         else
//         return NULL;
    
// }

// int stack_empty()
// {
//     if(top>=0)
//     return 0;
//     else
//     return 1;
// }
// int q_empty(){
//     if(q_head == NULL)
//     return 1;
//     else 
//     return 0;
// }
// void q_push_back(struct node *ptr)
// {
//     struct q *t;
//     t=(struct q*)malloc(sizeof(struct q));
//     t->ptr_data=ptr;
//     t->prv=q_tail;
//     t->next=NULL;
    
//     if(!q_empty())
//     {
//           q_tail->next=t;
//         q_tail=t;
//     }
//     else
//     {
//         q_head = t; 
//         q_tail = t;

//     }
  
// }

// void q_push_front(struct node *ptr)
// {
//     struct q *t;
//     t=(struct q*)malloc(sizeof(struct q));
//     t->ptr_data=ptr;
//     t->next=q_head;
//     t->prv=NULL;
//     q_head=t;
//     if(q_tail == NULL)
//     q_tail = q_head;
    
// }
// struct node* q_pop_back()
// {
//     if(!q_empty())
//     {
//         struct q* t=q_tail;
//         q_tail=q_tail->prv;
//         return t->ptr_data; 
//     }
//     else
//     {
//         q_head = q_tail = NULL;
//     }
//     return NULL;
    
// }
// struct node * q_pop_front()
// {
//     if(!q_empty())
//     {
//          struct q* t=q_head;
//         q_head=q_head->next;
//         return t->ptr_data;
//     }
   
//      else
//     {
//         q_head = q_tail = NULL;
//     }
//        return NULL;
   
// }


// int q_size()
// {
//     struct q*t = q_head;
    
//     printf("t: %d",t);
//     printf("tail: %d",q_tail);
//     int counter=0;
//     if(t == NULL)
//     return counter;
//     else
//     {
//          counter=1;
//         while(t != q_tail)
//         {
//             counter++;
//             t=t->next;
//         }
    
//     }
//     printf("Counter: %d\n",counter);
//    return counter;
// }


// void push(struct node** head_ref, struct node* node) 
// { 
//     // Make right of given node as head and left as 
//     // NULL 
//     if(node !=NULL){
//     node->rc = (*head_ref); 
//     node->lc = NULL; 
//     }
//     // change left of head node to given node 
//     if ((*head_ref) !=  NULL) 
//         (*head_ref)->lc = node ; 
  
//     // move the head to point to the given node 
//     (*head_ref) = node; 
// } 

// // Function to prints contents of DLL 
// void printList(struct node *head) 
// { 
//     while (head != NULL) 
//     { 
//         printf("%d ",head->data);
//         head = head->rc; 
//     } 
// } 

// void display_dequeue()
// {
//     struct q *t =q_head;
//     while(t != q_tail)
//     {
//         printf("%u\n",t->ptr_data);
//         t=t->next;
//     }
//     //  printf("%u\n",t->ptr_data);
// }

// void spiralOrder(struct node *root)
// {
//     if(root == NULL)
//     return;

//     q_push_front(root);
//     // int q_size=q_size();
      
//     int level = 0;
//     while(!q_empty())
//     {
//         printf("Level %d\n",level);
//         int nodeCount = q_size();

//         if(level%2!=0)//Odd 
//         {
//             while(nodeCount>0)
//             {
//                struct node * temp = q_pop_front();
//                 stack_push(temp);
            
//              if(temp != NULL)
//                 {
//                 if(temp->lc != NULL)
//                 q_push_back(temp->lc);
//                 if(temp->rc != NULL)
//                 q_push_back(temp->rc);
//                 }
                
//                 nodeCount--;
//             }
              
//         }
//         else//even
//         {
//             while(nodeCount>0)
//             {
//                 struct node *temp = q_pop_back();
//                 stack_push(temp);
//                 if(temp != NULL)
//                 {
//                      if(temp->rc !=NULL)
//                      q_push_front(temp->rc);
//                     if(temp->lc != NULL)
//                     q_push_front(temp->lc);
//                 }
               

//                 nodeCount-- ;
//             }
              
//         }
//         level++;
    
//     }
//     // head pointer for DLL 
//     struct node * head = NULL; 
//     while (!stack_empty()) 
//     { 
//         push(&head, stack_pop()); 
//     } 

//     printf("Created DLL is :\n");
//     printList(head);

// }


// struct node* newNode(int data) 
// { 
//     struct node *temp = (struct node*)malloc(sizeof(struct node)); 
//     temp->data = data; 
//     temp->lc = temp->rc = NULL; 
  
//     return temp; 
// } 




#include<stdio.h>
#include<stdlib.h>
#define stack_size 100000

struct node* newNode(int data) ;
struct node * create();
void stack_push(struct node *ptr);
struct node * stack_pop();
int stack_empty();
int q_empty();
void q_push_back(struct node *ptr);
void q_push_front(struct node *ptr);
struct node* q_pop_back();
struct node * q_pop_front();
int q_size();
void push(struct node** head_ref, struct node* node);
void printList(struct node *head) ;
void spiralOrder(struct node *root);

int ele;
struct node{
    int data;
    struct node *lc;
    struct node *rc;
}*root;

struct q{
    struct node * ptr_data;
    struct q* prv;
    struct q* next;
}*q_head=NULL,*q_tail=NULL;


struct node * stack[100000];
int top   = -1 ;




int main(){

    printf(" Please insert the tree! ");
    printf(" Inside main ");
    // root = create();
      root =  newNode(1); 
    root->lc = newNode(2); 
    root->rc = newNode(3); 
    root->lc->lc = newNode(4); 
    root->lc->rc = newNode(5); 
    root->rc->lc = newNode(6); 
    root->rc->rc = newNode(7); 
  
    root->lc->lc->lc  = newNode(8); 
    root->lc->lc->rc  = newNode(9); 
    root->lc->rc->lc  = newNode(10); 
    root->lc->rc->rc  = newNode(11); 
    //root->rc->lc->lc  = newNode(12); 
    root->rc->lc->rc  = newNode(13); 
    root->rc->rc->lc  = newNode(14);
    spiralOrder(root);
    return 0;
}
struct node * create(){

    printf("Enter element (if no enter -1)");
    scanf("%d",&ele);
    if(ele == -1)
    return NULL;
    struct node*t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data = ele;
    printf("Enter left child of %d ",ele);
    t->lc = create();
    printf("Enter right child of %d ",ele);
    t->rc = create();
    return t;

}

void stack_push(struct node *ptr)
{
    if(top<=stack_size)
    {
        top++;
        stack[top]=ptr;
    }
        
   
}

struct node * stack_pop()
{
        if(top>=0)
        return stack[top--];
        else
        return NULL;
    
}

int stack_empty()
{
    if(top>=0)
    return 0;
    else
    return 1;
}
int q_empty(){
    if(q_head == NULL)
    return 1;
    else 
    return 0;
}
void q_push_back(struct node *ptr)
{
    struct q *t;
    t=(struct q*)malloc(sizeof(struct q));
    t->ptr_data=ptr;
    t->prv=q_tail;
    t->next=NULL;
    
    if(!q_empty())
    {
          q_tail->next=t;
        q_tail=t;
    }
    else
    {
        q_head = t; 
        q_tail = t;

    }
  
}

void q_push_front(struct node *ptr)
{
    struct q *t;
    t=(struct q*)malloc(sizeof(struct q));
    t->ptr_data=ptr;
    t->next=q_head;
    t->prv=NULL;
    q_head=t;
    if(q_tail == NULL)
    q_tail = q_head;
    
}
struct node* q_pop_back()
{
    if(!q_empty())
    {
        
        struct q* t=q_tail;
        
        q_tail=t->prv;
        if(q_tail != NULL)
        q_tail->next =NULL;
        return t->ptr_data; 
    }
    else
    {
        q_head = q_tail = NULL;
    }
    return NULL;
    
}
struct node * q_pop_front()
{
    if(!q_empty())
    {
         struct q* t=q_head;
        q_head=q_head->next;
          if(q_head != NULL)
        q_head->prv = NULL;
        return t->ptr_data;
    }
   
     else
    {
        q_head = q_tail = NULL;
    }
       return NULL;
   
}


int q_size()
{
    struct q*t = q_head;
    
    printf("t: %d",t);
    printf("tail: %d",q_tail);
    int counter=0;
    if(t == NULL)
    return counter;
    else
    {
         counter=1;
        while(t != q_tail)
        {
            counter++;
            if(t->next != NULL)
            t=t->next;
            else
            break;
        }
    
    }
    printf("Counter: %d\n",counter);
   return counter;
}


void push(struct node** head_ref, struct node* node) 
{ 
    // Make right of given node as head and left as 
    // NULL 
    if(node !=NULL){
    node->rc = (*head_ref); 
    node->lc = NULL; 
    }
    // change left of head node to given node 
    if ((*head_ref) !=  NULL) 
        (*head_ref)->lc = node ; 
  
    // move the head to point to the given node 
    (*head_ref) = node; 
} 

// Function to prints contents of DLL 
void printList(struct node *n) 
{ 
    while (n != NULL) 
    { 
        printf("%d ",n->data);
        n = n->rc; 
    } 
} 

void display_Stack()
{
    int i;
    printf("^^^^^^^^^^^^^^\n");
    for(i=top-1;i>=0;i--)
    printf("%d\n",stack[i]->data);
    printf("^^^^^^^^^^^^^^");
}
void spiralOrder(struct node *root)
{
    if(root == NULL)
    return;

    q_push_front(root);
    // int q_size=q_size();
      
    int level = 0;
    while(!q_empty())
    {
        printf("Level %d\n",level);
        int nodeCount = q_size();

        if(level%2!=0)//Odd 
        {
            while(nodeCount>0)
            {
               struct node * temp = q_pop_front();
                stack_push(temp);
            
             if(temp != NULL)
                {
                if(temp->lc != NULL)
                q_push_back(temp->lc);
                if(temp->rc != NULL)
                q_push_back(temp->rc);
                }
                
                nodeCount--;
            }
              
        }
        else//even
        {
            while(nodeCount>0)
            {
                struct node *temp = q_pop_back();
                stack_push(temp);
                if(temp != NULL)
                {
                     if(temp->rc !=NULL)
                     q_push_front(temp->rc);
                    if(temp->lc != NULL)
                    q_push_front(temp->lc);
                }
               

                nodeCount-- ;
            }
              
        }
        level++;
    
    }
    
    display_Stack();
    // head pointer for DLL 
    struct node * head = NULL; 
    while (!stack_empty()) 
    { 
        push(&head, stack_pop()); 
    } 

    // printf("Created DLL is :\n");
    // printList(head);

}


struct node* newNode(int data) 
{ 
    struct node *temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->lc = temp->rc = NULL; 
  
    return temp; 
} 





