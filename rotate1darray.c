#include <stdio.h>
void rotateArray(int arr[], int size, int n) 
{
    n = n % size;
    int i;
    if (n < 0)
	{

        n += size;
	}
    int temp[size];
    for (i = 0; i < n; i++) 
	{
        temp[i] = arr[size - n + i];
    }

    for (i= size - 1; i >= n; i--) 
	{
        arr[i] = arr[i - n];
    }

    for (i = 0; i < n; i++) 
	{
        arr[i] = temp[i];
    }
}

int main() 
 {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 5,i;
    printf("Original array: ");
    for (i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
    rotateArray(arr, size, n);
    printf("\nRotated array: ");
    for (i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
}
