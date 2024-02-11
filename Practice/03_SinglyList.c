#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Global head pointer
struct node* head = NULL;

// Function to create a new node
struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Function to display the linked list
void display_list() {
    struct node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a new node after a specific node
void insert_after_node(int key, int value) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            struct node* new_node = create_node(value);
            new_node->next = current->next;
            current->next = new_node;
            printf("Node with value %d inserted after node with value %d\n", value, key);
            return;
        }
        current = current->next;
    }
    printf("Node with value %d not found in the list\n", key);
}

// Function to delete a node with a specific value
void delete_node(int value) {
    struct node* current = head;
    struct node* prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found in the list\n", value);
        return;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Node with value %d deleted from the list\n", value);
}

int main() {
    int choice;
    int value, key;

    do {
        printf("\n*** MENU ***\n");
        printf("1. Create a new node\n");
        printf("2. Display the linked list\n");
        printf("3. Insert a new node after a specific node\n");
        printf("4. Delete a node with a specific value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value for the new node: ");
                scanf("%d", &value);
                if (head == NULL)
                    head = create_node(value);
                else {
                    struct node* temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = create_node(value);
                }
                printf("Node with value %d created\n", value);
                break;
            case 2:
                display_list();
                break;
            case 3:
                printf("Enter the value of the existing node after which you want to insert: ");
                scanf("%d", &key);
                printf("Enter the value of the new node: ");
                scanf("%d", &value);
                insert_after_node(key, value);
                break;
            case 4:
                printf("Enter the value of the node you want to delete: ");
                scanf("%d", &value);
                delete_node(value);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
