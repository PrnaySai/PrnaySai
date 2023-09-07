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
void removeElement(int x) 
{
    int index = abs(x) % TABLE_SIZE;
    table[index] = false;
}
bool contains(int x) 
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
    removeElement(10);
    printf("5 is in the set: %s\n", contains(5) ? "Yes" : "No");
    printf("10 is in the set: %s\n", contains(10) ? "Yes" : "No");
    return 0;
}