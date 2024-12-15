#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void write_to_file(const char* filename, const List* list) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        exit(1);
    }

    for (Node* node = list->head; node; node = node->next) {
        fprintf(file, "%s,%s,%s,%s,%d,%d,%d,%d,%d\n",
                node->data.title, node->data.author_last_name, node->data.author_initials,
                node->data.journal_name, node->data.year, node->data.volume,
                node->data.is_in_rinc, node->data.pages, node->data.citations);
    }

    fclose(file);
}

void read_from_file(const char* filename, List* list) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for reading");
        exit(1);
    }

    Publication pub;
    int line = 0;

    while (fscanf(file, "%99[^,],%99[^,],%99[^,],%99[^,],%d,%d,%d,%d,%d\n",
                  pub.title, pub.author_last_name, pub.author_initials,
                  pub.journal_name, &pub.year, &pub.volume,
                  &pub.is_in_rinc, &pub.pages, &pub.citations) == 9) {
        append(list, pub);
        line++;
    }

    if (line == 0) {
        fprintf(stderr, "Error: No data read from file %s. Check the file format.\n", filename);
        exit(1);
    }

    fclose(file);
}
