#include <stdio.h>
#include <stdlib.h>

// Estrutura Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Estrutura LinkedList
typedef struct LinkedList {
    Node *head;
    Node *tail;
    int length;
} LinkedList;

Node *createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
    }
    return list;
}

void addNode(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
}

void printList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(LinkedList *list) {
    Node *current = list->head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

int main() {
    LinkedList *list = createLinkedList();

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);

    printList(list);

    freeList(list); // Libera a memória alocada para a lista

    return 0;
}