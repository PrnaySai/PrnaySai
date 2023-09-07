#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INITIAL_CAPACITY 10
typedef struct 
{
    int* array;
    int* indices;
    int size;
    int capacity;
} RandomizedDataStructure;
RandomizedDataStructure* init() 
{
    RandomizedDataStructure* ds = (RandomizedDataStructure*)malloc(sizeof(RandomizedDataStructure));
    ds->array = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    ds->indices = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    ds->size = 0;
    ds->capacity = INITIAL_CAPACITY;
    return ds;
}
void insert(RandomizedDataStructure* ds, int x) 
{
    if (ds->size == ds->capacity) 
    {
        ds->capacity *= 2;
        ds->array = (int*)realloc(ds->array, sizeof(int) * ds->capacity);
        ds->indices = (int*)realloc(ds->indices, sizeof(int) * ds->capacity);
    }
    ds->array[ds->size] = x;
    ds->indices[x] = ds->size;
    ds->size++;
}
void removeElement(RandomizedDataStructure* ds, int x) 
{
    if (ds->size == 0 || ds->indices[x] == -1) 
    {
        return;
    }
    int indexToRemove = ds->indices[x];
    int lastElement = ds->array[ds->size - 1];
    ds->array[indexToRemove] = lastElement;
    ds->indices[lastElement] = indexToRemove;
    ds->indices[x] = -1;
    ds->size--;
}
int getRandom(RandomizedDataStructure* ds) 
{
    if (ds->size == 0) 
    {
        return -1;
    }
    int randomIndex = rand() % ds->size;
    return ds->array[randomIndex];
}
int main() 
{
    srand(time(NULL));
    RandomizedDataStructure* ds = init();
    insert(ds, 5);
    insert(ds, 10);
    insert(ds, 15);
    printf("Random element: %d\n", getRandom(ds));
    removeElement(ds, 10);
    printf("Random element after removal: %d\n", getRandom(ds));
    free(ds->array);
    free(ds->indices);
    free(ds);
    return 0;
}