#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void addNode(Node** head, int data);
void deleteLastNode(Node** head);
void addSecondLastNode(Node** head, int data);
void swapNodes(Node** head, int data1, int data2);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // Add nodes to the circular linked list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printf("Original Circular Linked List:\n");
    printList(head);

    // Delete the last node
    deleteLastNode(&head);
    printf("After deleting the last node:\n");
    printList(head);

    // Add a node at the second last position
    addSecondLastNode(&head, 99);
    printf("After adding a node at the second last position:\n");
    printList(head);

    // Swap nodes with data 2 and 99
    swapNodes(&head, 2, 99);
    printf("After swapping nodes 2 and 99:\n");
    printList(head);

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the circular linked list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;  // Point to itself for a circular list
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete the last node of the circular linked list
void deleteLastNode(Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {  // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        prev->next = *head;
        free(temp);
    }
}

// Function to add a node at the second last position
void addSecondLastNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || (*head)->next == *head) {
        addNode(head, data);
        return;
    }
    Node* temp = *head;

    while (temp->next->next != *head) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to swap two nodes by their values
void swapNodes(Node** head, int data1, int data2) {
    if (*head == NULL || data1 == data2) {
        printf("Cannot swap. List is empty or nodes are the same.\n");
        return;
    }

    Node *prev1 = NULL, *prev2 = NULL, *node1 = *head, *node2 = *head;

    // Find nodes with data1 and data2
    do {
        if (node1->data != data1) {
            prev1 = node1;
            node1 = node1->next;
        }
        if (node2->data != data2) {
            prev2 = node2;
            node2 = node2->next;
        }
        if (node1->data == data1 && node2->data == data2) break;
    } while (node1 != *head || node2 != *head);

    if (node1->data != data1 || node2->data != data2) {
        printf("One or both nodes not found.\n");
        return;
    }

    // Swap nodes
    if (prev1) prev1->next = node2;
    else *head = node2;

    if (prev2) prev2->next = node1;
    else *head = node1;

    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

// Function to print the circular linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
