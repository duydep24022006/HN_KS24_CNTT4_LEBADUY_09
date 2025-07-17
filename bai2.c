#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Operation
{
    char name[100];
}Operation;
typedef struct Stack
{
    Operation data;
    int top;
    int capacity;
}Stack;
typedef struct Queue
{
    Operation data;
    int front;
    int rear;
    int capacity;
}Queue;
Stack* createQueue(int capacity)
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL)
        return NULL;
    newStack->top = -1;
    newStack->capacity = capacity;
    return newStack;
}
Queue* initQueue(int capacity)
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL)
        return NULL;
    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->capacity = capacity;
    return newQueue;
}


void printMenu()
{
    printf("        MENU\n");
    printf("1. ADD\n");
    printf("2. PLAY NEXT\n");
    printf("3. PLAY PREVIOUS\n");
    printf("4. HISTORY\n");
    printf("5. Exit\n");


}
int main()
{
    int choice;
    Queue* queue = initQueue(100);

    do
    {
        printMenu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                char name[100];
                printf("ten bai hat: ");
                fgets(name,100,stdin);
                name[strcspn(name, "\n")] = '\0';

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("thoat truong trinh thanh cong!\n");
                break;
            default:
                printf("loi cu phap\n");

        }
    }
    while (choice!=5);
}