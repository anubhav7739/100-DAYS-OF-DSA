/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        // 2. Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        // 3. Link the node
        if (head == NULL) {
            head = newNode; // First node becomes the head
            temp = head;
        } else {
            temp->next = newNode; // Link previous node to the new one
            temp = temp->next;    // Move temp to the new end
        }
    }

    // 4. Traverse and Print
    temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }

    // 5. Clean up memory (Good practice in C!)
    temp = head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}