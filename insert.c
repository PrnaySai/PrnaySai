#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Stack 
{
    struct Node* head;
    int count;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void initializeStack(struct Stack* stack) 
{
    stack->head = NULL;
    stack->count = 0;
}
void insert(struct Stack* stack, int value) 
{
    struct Node* newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
    stack->count++;
}
int main() 
{
    struct Stack stack;
    initializeStack(&stack);
    insert(&stack, 5);
    insert(&stack, 10);
    insert(&stack, 15);
    struct Node* current = stack.head;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    return 0;
}
