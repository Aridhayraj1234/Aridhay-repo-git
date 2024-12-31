#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void append(Node** head, int data);
void printList(Node* head);
void deleteThirdNode(Node** head);
void deleteSecondLastNode(Node** head);
void addSecondLastNode(Node** head, int data);
void swapNodes(Node** head, int data1, int data2);

int main() {
    Node* head = NULL;

    // Creating a sample linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original List:\n");
    printList(head);

    // Deleting the third node
    deleteThirdNode(&head);
    printf("After deleting the third node:\n");
    printList(head);

    // Deleting the second last node
    deleteSecondLastNode(&head);
    printf("After deleting the second last node:\n");
    printList(head);

    // Adding a node at the second last position
    addSecondLastNode(&head, 99);
    printf("After adding a node at the second last position:\n");
    printList(head);

    // Swapping nodes with data 2 and 99
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

// Function to append a node to the end of the list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the third node if it exists
void deleteThirdNode(Node** head) {
    if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL) {
        printf("The third node does not exist.\n");
        return;
    }
    Node* temp = (*head)->next->next;
    (*head)->next->next = temp->next;
    free(temp);
}

// Function to delete the second last node if it exists
void deleteSecondLastNode(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("The second last node does not exist.\n");
        return;
    }
    Node* prev = NULL;
    Node* current = *head;
    while (current->next != NULL && current->next->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev != NULL) {
        prev->next = current->next;
        free(current);
    }
}

// Function to add a node at the second last position
void addSecondLastNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || (*head)->next == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to swap two nodes (not just data)
void swapNodes(Node** head, int data1, int data2) {
    if (data1 == data2) {
        printf("Both nodes are the same. No swap needed.\n");
        return;
    }

    Node* prev1 = NULL, * prev2 = NULL, * node1 = *head, * node2 = *head;

    // Find nodes with data1 and data2
    while (node1 && node1->data != data1) {
        prev1 = node1;
        node1 = node1->next;
    }
    while (node2 && node2->data != data2) {
        prev2 = node2;
        node2 = node2->next;
    }

    if (!node1 || !node2) {
        printf("One or both nodes not found.\n");
        return;
    }

    // Swap the nodes
    if (prev1) prev1->next = node2;
    else *head = node2;

    if (prev2) prev2->next = node1;
    else *head = node1;

    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}
