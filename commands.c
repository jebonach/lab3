#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "commands.h"
#include "list.h"
#include "io.h"
#include "sort.h"
#include "publication.h"

int compare_by_year(Publication a, Publication b) {
    return a.year - b.year;
}

void handle_generate(int count, const char* output_file) {
    List list;
    init_list(&list);
    srand((unsigned)time(NULL));

    const char* titles[] = {"Article", "Research", "Study", "Investigation", "Analysis"};
    const char* authors[] = {"Guryev", "Seliverstov", "Cherkasov", "Bogatyrev", "Minkin"};
    const char* initials[] = {"T.A.", "I.A.", "I.S.", "S.A.", "M.K."};
    const char* journals[] = {"Journal A", "Journal B", "Journal C", "Journal D", "Journal E"};

    for (int i = 0; i < count; i++) {
        Publication p;
        strcpy(p.title, titles[rand() % 5]);
        strcpy(p.author_last_name, authors[rand() % 5]);
        strcpy(p.author_initials, initials[rand() % 5]);
        strcpy(p.journal_name, journals[rand() % 5]);

        p.year = 2000 + rand() % 24;
        p.volume = rand() % 10 + 1;
        p.is_in_rinc = rand() % 2;
        p.pages = rand() % 300 + 1;
        p.citations = rand() % 500;

        append(&list, p);
    }

    write_to_file(output_file, &list);
    printf("Generated %d records and saved to %s\n", count, output_file);
    clear_list(&list);
}

void handle_sort(const char* input_file, const char* output_file) {
    List list;
    init_list(&list);

    read_from_file(input_file, &list);
    if (list.size == 0) {
        fprintf(stderr, "No data to sort.\n");
        return;
    }

    bubble_sort(&list, compare_by_year);
    write_to_file(output_file, &list);
    printf("Sorted records saved to %s\n", output_file);

    clear_list(&list);
}

void handle_print(const char* input_file) {
    List list;
    init_list(&list);

    read_from_file(input_file, &list);
    if (list.size == 0) {
        fprintf(stderr, "No data to print.\n");
        return;
    }

    printf("%-20s %-15s %-10s %-15s %-5s %-5s %-8s %-6s %-10s\n",
           "Title", "Author", "Initials", "Journal", "Year", "Vol", "RINC", "Pages", "Citations");
    printf("---------------------------------------------------------------------------------------------\n");

    for (Node* node = list.head; node; node = node->next) {
        printf("%-20s %-15s %-10s %-15s %-5d %-5d %-8s %-6d %-10d\n",
               node->data.title, node->data.author_last_name, node->data.author_initials,
               node->data.journal_name, node->data.year, node->data.volume,
               node->data.is_in_rinc ? "YES" : "NO", node->data.pages, node->data.citations);
    }

    clear_list(&list);
}
