#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* addLists(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* prev = NULL;
    Node* temp;
    int carry = 0, sum;

    while (list1 != NULL || list2 != NULL) {
        sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
        carry = sum / 10;
        sum %= 10;

        temp = newNode(sum);

        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }

        prev = temp;

        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }

    if (carry > 0) {
        temp->next = newNode(carry);
    }

    return result;
}

void printList(Node* list) {
    while (list != NULL) {
        printf("%d", list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    Node* num1 = newNode(9);
    num1->next = newNode(9);
    num1->next->next = newNode(9);

    Node* num2 = newNode(1);

    Node* result = addLists(num1, num2);

    printf("Number 1: ");
    printList(num1);

    printf("Number 2: ");
    printList(num2);

    printf("Sum: ");
    printList(result);

    return 0;
}
