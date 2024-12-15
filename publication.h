#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <stdbool.h>

#define MAX_STRING_LEN 100

typedef struct {
    char title[MAX_STRING_LEN];
    char author_last_name[MAX_STRING_LEN];
    char author_initials[MAX_STRING_LEN];
    char journal_name[MAX_STRING_LEN];
    int year;
    int volume;
    bool is_in_rinc;
    int pages;
    int citations;
} Publication;

#endif // PUBLICATION_H
