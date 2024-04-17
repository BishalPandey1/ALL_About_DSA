#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list with n nodes
void createLinkedList(struct Node** head, int n) {
    struct Node* current = NULL;
    for (int i = 1; i <= n; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (*head == NULL) {
            // First node
            *head = newNode;
            current = newNode;
        } else {
            // Link the current node to the new node
            current->next = newNode;
            current = newNode;
        }
    }
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    printf("Linked List elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter the number of nodes (4 in your case): ");
    scanf("%d", &n);

    createLinkedList(&head, n);
    displayLinkedList(head);

    // Free memory (optional, but good practice)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
