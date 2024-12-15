#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(List* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void append(List* list, Publication data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        perror("Error allocating memory");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }

    list->tail = new_node;
    list->size++;
}

void clear_list(List* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
