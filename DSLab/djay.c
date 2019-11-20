#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXSIZE 100

/*  creating a data structure stack */
struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;

/*  Function to generate a rendom number */
int generateRandoms(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

/*  Function to push an element to the stack */
void push(int num)
{
    if (s.top == (MAXSIZE - 1))
    {
        printf("Stack is Full\n");
        return;
    }
    s.stk[++s.top] = num;
    return;
}

/*  Function to pop an element from the stack */
int pop()
{
    if (s.top == -1)
    {
        printf("Stack is Empty\n");
        return s.top;
    }
    return s.stk[s.top--];
}

/*  Function to display the contents of the stack */
void display()
{
    if (s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("\nTHE NUMBERS ARE :\n");
    for (size_t i = 0; i <= s.top; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d ", s.stk[i]);
    }
    return;
}

/*  Function to insert elements into the heap */
void Insert(int element, int heap[], int *heapSize)
{
    (*heapSize)++;
    heap[*heapSize] = element; /*Insert in the last place*/
    /*Adjust its position*/
    int now = *heapSize;
    while (heap[now / 2] > element)
    {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}

int main()
{
    int min, heap[4][26], heapSize[4] = {0};
    heap[0][0] = heap[1][0] = heap[2][0] = heap[3][0] = -INT_MAX;
    s.top = -1;

    /*  pushing random numbers into the stack */
    for (size_t i = 0; i < 100; i++)
    {
        push(generateRandoms(100, 999));
    }

    display();
    printf("\n \nDISTRIBUTING NUMBERS AMONG THE PLAYERS\n");

    /*  distributing numbers to the players in circular manner */
    for (size_t i = 0; i < 25; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            Insert(pop(), heap[j], &heapSize[j]);
        }
    }

    /*  locating the winner!!! */
    min = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (heap[i][1] < heap[min][1])
            min = i;
    }
    printf("\n \tAND THE WINNER IS : PLAYER %d", min + 1);

    return 0;
}