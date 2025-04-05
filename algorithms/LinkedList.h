// DOUBLY LINKED LIST
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
typedef struct node_str {
    void* value;
    struct node_str* next;
    struct node_str* prev;
} Node; 

typedef struct list_str {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* initList(LinkedList*);
Node* addToHead(LinkedList*, void*);
Node* addToTail(LinkedList*, void*);
void removeHead(LinkedList*);
void removeTail(LinkedList*);

void freeList(LinkedList*);
void printList(const LinkedList*, void(*print)(const Node*));
#endif
