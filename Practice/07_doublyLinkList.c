#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node with data %d inserted at the end\n", data);
}

// Function to display the doubly linked list
void display() {
    if (head == NULL) {
        printf("Doubly linked list is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete a specific node by value
void deleteNode(int data) {
    if (head == NULL) {
        printf("Doubly linked list is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found in the list\n", data);
        return;
    }
    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }
    free(temp);
    printf("Node with data %d deleted from the list\n", data);
}

// Function to display the menu
void displayMenu() {
    printf("\n*** MENU ***\n");
    printf("1. Insert node at the end\n");
    printf("2. Display doubly linked list\n");
    printf("3. Delete specific node\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}
