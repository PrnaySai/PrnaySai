#include <stdio.h>
#include <stdlib.h>
long long int merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long int inversions = 0;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        else 
        {
            inversions += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) 
    {
        temp[k++] = arr[i++];
    }
    while (j <= right) 
    {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) 
    {
        arr[i] = temp[i];
    }
    return inversions;
}
long long int mergeSort(int arr[], int temp[], int left, int right) 
{
    long long int inversions = 0;
    if (left < right) 
    {
        int mid = (left + right) / 2;
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        inversions += merge(arr, temp, left, mid, right);
    }
    return inversions;
}
int main() 
{
    int n,temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    long long int inversions = mergeSort(arr,temp, 0, n - 1);
    printf("Number of inversions in the array: %lld\n", inversions);
    return 0;
}
