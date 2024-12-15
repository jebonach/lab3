#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include "publication.h"

typedef struct Node {
    Publication data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} List;

void init_list(List* list);
void append(List* list, Publication data);
void clear_list(List* list);

#endif // LIST_H
