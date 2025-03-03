#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

Node *createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

LinkedList *createList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

int insertBegin(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return -1; 
    }

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode; 
    }
    
    list->size++;
    return 0;
}

int insertEnd(LinkedList *list, int data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
    return 0;
}


void printList(LinkedList *list) {
    Node *current = list->head; 
    while (current != NULL) {
        printf("%d\n", current->data); 
        current = current->next; 
    }
}

int removeFirst(LinkedList *list) {
    if (list->head == NULL) {
        return -1; 
    }

    Node *current = list->head; // Guarda o endereço do primeiro nó
    list->head = list->head->next; // Atualiza o head para o segundo nó

    if (list->head == NULL) {
        list->tail = NULL; 
    }

    free(current); 
    list->size--;
    return 0;
}
int removeEnd(LinkedList *list) {
    if (list->head == NULL) {
        return -1;
    }

    Node *current = list->head;
    Node *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        prev->next = NULL;
        list->tail = prev;
    }

    free(current);
    list->size--;
    return 0;
}

int removeNode(LinkedList *list, int data) {
    if (list->head == NULL) {
        return -1; 
    }

    Node *current = list->head;
    Node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return -1;
    }

    if (prev == NULL) {
        list->head = current->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
    } else {
        prev->next = current->next;
        if (current->next == NULL) {
            list->tail = prev;
        }
    }

    free(current);
    list->size--;
    return 0;
}

int search(LinkedList *list, int data) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
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
    LinkedList *list = createList();
    if (list == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    insertEnd(list, 10);
    insertBegin(list, 20);
    insertEnd(list, 30);

    printList(list);

    removeFirst(list);
    removeEnd(list);
    removeNode(list, 10);

    printList(list);

    if (search(list, 20)) {
        printf("20 found in the list\n");
    } else {
        printf("20 not found in the list\n");
    }

    freeList(list);
    return 0;
}