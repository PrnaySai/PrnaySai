#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    int priority;
    struct Node* next;
};
struct Node* newNode(int data, int priority) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}
void enqueue(struct Node** head, int data, int priority) 
{
    struct Node* newNodePtr = newNode(data, priority);
    if (*head == NULL || priority < (*head)->priority) 
    {
        newNodePtr->next = *head;
        *head = newNodePtr;
    } 
    else 
    {
        struct Node* current = *head;
        while (current->next != NULL && current->next->priority <= priority) 
        {
            current = current->next;
        }
        newNodePtr->next = current->next;
        current->next = newNodePtr;
    }
}
void dequeue(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("Priority queue is empty\n");
    } 
    else 
    {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
void display(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("Priority queue is empty\n");
    } 
    else 
    {
        printf("Priority Queue: ");
        while (head != NULL) 
        {
            printf("(%d, %d) ", head->data, head->priority);
            head = head->next;
        }
        printf("\n");
    }
}

int main() 
{
    struct Node* pq = NULL;
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    display(pq);
    dequeue(&pq);
    display(pq);
    return 0;
}
