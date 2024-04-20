#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Unable to allocate memory for the new node.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to remove the first node of the list
void removeFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    struct Node* temp = *head; // Hold the first node
    *head = (*head)->next;     // Move the head to the second node
    free(temp);                // Free the memory of the removed node
}

// Function to display the linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create three nodes
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Original list:\n");
    displayList(head);

    // Remove the first node
    removeFirstNode(&head);

    printf("List after removing the first node:\n");
    displayList(head);

    return 0;
}
