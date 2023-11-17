#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}
int hasPairWithSum(int arr[], int n, int X) 
{
    qsort(arr, n, sizeof(int), compare);
    int left = 0;
    int right = n - 1;
    while (left < right) 
    {
        int currentSum = arr[left] + arr[right];
        
        if (currentSum == X) 
        {
            return 1;
        } 
        else if (currentSum < X) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    return 0;
}
int main()
{
    int n, X;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of X: ");
    scanf("%d", &X);
    if (hasPairWithSum(arr, n, X)) 
    {
        printf("There exist two integers whose sum is %d.\n", X);
    } 
    else 
    {
        printf("There do not exist two integers whose sum is %d.\n", X);
    }
    return 0;
}
