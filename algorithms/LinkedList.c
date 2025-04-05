#include "LinkedList.h"
#include <stdlib.h>

// NEVER call this on a linked list that's already in use!
LinkedList* initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node* addToHead(LinkedList* list, void* value) {
    if (!list->head) {
        list->head = (Node*)malloc(sizeof(Node));
        list->head->value = value;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->tail = list->head;
        return list->head;
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = list->head;
    temp->prev = NULL;
    list->head = temp;
    return list->head;
}

Node* addToTail(LinkedList* list, void* value) {
    if (!list->tail) {
        return addToHead(list, value); // list is empty so head is tail
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    temp->prev = list->tail;
    list->tail = temp;
    return list->tail;
}

void freeList(LinkedList* list) {
    Node* traverse = list->head;
    while (traverse) {
        list->head = list->head->next;
        free(traverse);
        traverse = list->head;
    }
}
void printList(const LinkedList* list, void(*print)(const Node*)) {
    Node* traverse = list->head;
    while (traverse) {
        print(traverse);
        traverse = traverse->next;
    }
}
