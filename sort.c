#include "sort.h"

void bubble_sort(List* list, int (*cmp)(Publication, Publication)) {
    if (!list->head || list->size < 2) return;

    for (Node* i = list->head; i; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            if (cmp(i->data, j->data) > 0) {
                Publication temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
