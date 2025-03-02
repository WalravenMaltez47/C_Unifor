#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *creatNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addNode(Node **head, int data) {
    Node *newNode = creatNode(data);

    if(*head==NULL) {
        *head = newNode;
    }

    else {
        Node *current = *head;
        while(current->next!=NULL) {
            current = current->next;
        }
        current->next = newNode;        
    }
}

void printList(Node *head) {
    Node *current = head;
    while(current!=NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printList(head);
    return 0;
}