#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Operation
{
    char name[100];
}Operation;
typedef struct Stack
{
    Operation data[100];
    int top;
    int capacity;
}Stack;
typedef struct Queue
{
    Operation data[100];
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
    Queue* nextQueue = initQueue(100);
    Stack* historyStack = createQueue(100);
    char temp;
    do
    {
        printMenu();
        scanf("%d", &choice);
        while ((temp = getchar()) != '\n' && temp != EOF);

        switch (choice)
        {
            case 1:
            {
                char name[100];
                printf("ten bai hat: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = '\0';

                if (nextQueue->rear + 1 >= nextQueue->capacity)
                {
                    printf("hang doi bai hat da day\n");
                    break;
                }
                nextQueue->rear++;
                strcpy(nextQueue->data[nextQueue->rear].name, name);
                printf("da them bai hat: %s\n", name);
                break;
            }
            case 2:
            {
                if (nextQueue->front > nextQueue->rear)
                {
                    printf("khong co bai hat nao de phat tiep\n");
                    break;
                }
                Operation playing = nextQueue->data[nextQueue->front];
                nextQueue->front++;

                if (historyStack->top + 1 >= historyStack->capacity)
                {
                    printf("lich su da day\n");
                    break;
                }
                historyStack->top++;
                strcpy(historyStack->data[historyStack->top].name, playing.name);
                printf("dang phat: %s\n", playing.name);
                break;
            }
            case 4:
            {
                if (historyStack->top < 0)
                {
                    printf("chua co lich su\n");
                    break;
                }
                printf("lich su phat:\n");
                for (int i = 0; i <= historyStack->top; i++)
                {
                    printf("%d. %s\n", i + 1, historyStack->data[i].name);
                }
                break;
            }
            case 5:
                printf("thoat truong trinh thanh cong!\n");
                break;
            default:
                printf("loi cu phap\n");
        }
    } while (choice != 5);

    free(nextQueue);
    free(historyStack);
    return 0;
}
