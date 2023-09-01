#include <stdio.h>
#include <stdlib.h>
struct Node {
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
    } else {
        struct Node* current = *poly;
        while (current->next != NULL) 
		{
            current = current->next;
        }
        current->next = newNode;
    }
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) 
{
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) 
	{
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;
        if (exp1 == exp2) 
		{
            insertTerm(&result, coeff1 + coeff2, exp1);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } 
		else if (exp1 > exp2)
		{
            insertTerm(&result, coeff1, exp1);
            poly1 = poly1->next;
        } 
		else 
		{
            insertTerm(&result, coeff2, exp2);
            poly2 = poly2->next;
        }
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
int main() 
{
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);
    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 1, 0);
    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    struct Node* result = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    displayPolynomial(result);
    return 0;
}
