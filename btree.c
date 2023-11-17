#include <stdio.h>
#include <stdlib.h>
#define M 3
struct BTreeNode {
int leaf;
int keys[M - 1];
struct BTreeNode* child[M];
int key_count;
};
struct BTreeNode* createNode() {
struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
newNode->key_count = 0;
newNode->leaf = 1;
return newNode;
}
void insertNonFull(struct BTreeNode* node, int key) {
int i = node->key_count;
if (node->leaf) {
while (i >= 1 && key < node->keys[i - 1]) {
node->keys[i] = node->keys[i - 1];
i--;
}
node->keys[i] = key;
node->key_count++;
} else {
while (i >= 1 && key < node->keys[i - 1])
i--;
if (node->child[i]->key_count == M - 1) {
splitChild(node, i, node->child[i]);
if (key > node->keys[i])
i++;
}
insertNonFull(node->child[i], key);
}
}
void splitChild(struct BTreeNode* parent, int index, struct BTreeNode* child) {
struct BTreeNode* newNode = createNode();
struct BTreeNode* middleChild = child->child[M / 2];
int middleKey = child->keys[M / 2 - 1];
child->key_count = M / 2 - 1;
newNode->leaf = child->leaf;
newNode->key_count = M / 2 - 1;
for (int i = 0; i < M / 2 - 1; i++) {
newNode->keys[i] = child->keys[i + M / 2];
newNode->child[i] = child->child[i + M / 2];
}
newNode->child[M / 2 - 1] = child->child[M - 1];
parent->child[index] = child;
for (int i = parent->key_count; i > index; i--) {
parent->keys[i] = parent->keys[i - 1];
parent->child[i + 1] = parent->child[i];
}
parent->keys[index] = middleKey;
parent->child[index + 1] = newNode;
parent->key_count++;
}
void insert(struct BTreeNode** root, int key) {
struct BTreeNode* rootPtr = *root;
if (rootPtr->key_count == M - 1) {
struct BTreeNode* newNode = createNode();
newNode->leaf = 0;
newNode->child[0] = rootPtr;
*root = newNode;
splitChild(newNode, 0, rootPtr);
insertNonFull(newNode, key);
} else {
insertNonFull(rootPtr, key);
}
}
void display(struct BTreeNode* node, int level) {
int i;
if (node) {
for (i = node->key_count - 1; i >= 0; i--) {
display(node->child[i + 1], level + 1);
for (int j = 0; j <  ; j++) {
printf(" ");
}
printf("%d\n", node->keys[i]);
}
display(node->child[0], level + 1);
}
}
int search(struct BTreeNode* node, int key) {
if (!node)
return 0;
int i = 0;
while (i < node->key_count && key > node->keys[i])
i++;
if (i < node->key_count && key == node->keys[i])
return 1;
else if (node->leaf)
return 0;
else
return search(node->child[i], key);
}
int main() {
struct BTreeNode* root = createNode();
int choice, key;
while (1) {
printf("\nB-Tree Operations\n");
printf("1. Insertion\n");
printf("2. Display\n");
printf("3. Search\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter key to insert: ");
scanf("%d", &key);
insert(&root, key);
break;
case 2:
printf("B-Tree structure:\n");
display(root, 0);
break;
case 3:
printf("Enter key to search: ");
scanf("%d", &key);
if (search(root, key))
printf("Key %d found in the B-Tree.\n", key);
else
printf("Key %d not found in the B-Tree.\n", key);
break;
case 4:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}