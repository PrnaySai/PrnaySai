#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
void split(struct Node* source, struct Node** front, struct Node** back) 
{
    struct Node* slow = source;
    struct Node* fast = source->next;
    while (fast != NULL) 
    {
        fast = fast->next;
        if (fast != NULL) 
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}
struct Node* merge(struct Node* a, struct Node* b) 
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    struct Node* result = NULL;
    if (a->data <= b->data) 
    {
        result = a;
        result->next = merge(a->next, b);
    } 
    else 
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}
void mergeSort(struct Node** headRef) 
{
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;
    if (head == NULL || head->next == NULL) 
    {
        return;
    }
    split(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = merge(a, b);
}
void append(struct Node** headRef, int newData) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;
    if (*headRef == NULL) 
    {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}
void printList(struct Node* node) 
{
    while (node != NULL) 
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() 
{
    struct Node* head = NULL;
    append(&head, 12);
    append(&head, 11);
    append(&head, 13);
    append(&head, 5);
    append(&head, 6);
    append(&head, 7);
    printf("Given linked list: ");
    printList(head);
    mergeSort(&head);
    printf("Sorted linked list: ");
    printList(head);
    return 0;
}
