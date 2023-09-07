#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define TABLE_SIZE 10000
bool table[TABLE_SIZE];
void initSet() 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        table[i] = false;
    }
}
void insert(int x) 
{
    int index = abs(x) % TABLE_SIZE;
    table[index] = true;
}
bool search(int x) 
{
    int index = abs(x) % TABLE_SIZE;
    return table[index];
}

int main() 
{
    initSet();
    insert(5);
    insert(10);
    insert(15);
    printf("Searching for 5: %s\n", search(5) ? "Found" : "Not Found");
    printf("Searching for 10: %s\n", search(10) ? "Found" : "Not Found");
    printf("Searching for 20: %s\n", search(20) ? "Found" : "Not Found");
    return 0;
}
