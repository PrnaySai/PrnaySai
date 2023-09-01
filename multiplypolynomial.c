#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int coefficient;
    int exponent;
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node** poly, int coeff, int exp) 
{
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) 
	{
        *poly = newNode;
    } 
	else 
	{
        struct Node* current = *poly;
        while (current->next != NULL) 
		{
            current = current->next;
        }
        current->next = newNode;
    }
}
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) 
{
    struct Node* result = NULL;
    while (poly1 != NULL) 
	{
        struct Node* temp = poly2;
        while (temp != NULL) 
		{
            int coeff = poly1->coefficient * temp->coefficient;
            int exp = poly1->exponent + temp->exponent;
            insertTerm(&result, coeff, exp);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }
    return result;
}
void displayPolynomial(struct Node* poly) 
{
    struct Node* current = poly;
    while (current != NULL) 
	{
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL)
		{
            printf(" + ");
        }
    }
    printf("\n");
}
void freePolynomial(struct Node* poly) 
{
    struct Node* current = poly;
    while (current != NULL) 
	{
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}
int main() 
{
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    int n, coeff, exp,i;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms of the first polynomial (coeff exp): ");
    for (i = 0; i < n; i++) 
	{
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms of the second polynomial (coeff exp): ");
    for (i = 0; i < n; i++) 
	{
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }
    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    struct Node* result = multiplyPolynomials(poly1, poly2);
    printf("Product of Polynomials: ");
    displayPolynomial(result);
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);
    return 0;
}
