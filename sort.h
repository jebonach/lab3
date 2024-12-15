#ifndef SORT_H
#define SORT_H

#include "list.h"

void bubble_sort(List* list, int (*cmp)(Publication, Publication));

#endif // SORT_H
