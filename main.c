#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void print_usage() {
    printf("Usage: \n");
    printf("  Generate: ./program --generate N --out=file.csv\n");
    printf("  Sort:     ./program --sort --in=file.csv --out=file.csv\n");
    printf("  Print:    ./program --print --in=file.csv\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    // --generate
    if (strcmp(argv[1], "--generate") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Error: Missing arguments for --generate.\n");
            print_usage();
            return 1;
        }

        int count = atoi(argv[2]);
        if (count <= 0) {
            fprintf(stderr, "Error: Invalid count for --generate.\n");
            print_usage();
            return 1;
        }

        const char* output_file = "output.csv";
        for (int i = 3; i < argc; i++) {
            if (strcmp(argv[i], "--out") == 0 && i + 1 < argc) {
                output_file = argv[i + 1];
            }
        }

        handle_generate(count, output_file);
    }
    // --sort
    else if (strcmp(argv[1], "--sort") == 0) {
        const char* input_file = NULL;
        const char* output_file = NULL;

        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "--in") == 0 && i + 1 < argc) {
                input_file = argv[i + 1];
            }
            if (strcmp(argv[i], "--out") == 0 && i + 1 < argc) {
                output_file = argv[i + 1];
            }
        }

        if (input_file && output_file) {
            handle_sort(input_file, output_file);
        } else {
            fprintf(stderr, "Error: Missing --in or --out for --sort.\n");
            print_usage();
            return 1;
        }
    }
    // --print
    else if (strcmp(argv[1], "--print") == 0) {
        const char* input_file = NULL;

        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "--in") == 0 && i + 1 < argc) {
                input_file = argv[i + 1];
            }
        }

        if (input_file) {
            handle_print(input_file);
        } else {
            fprintf(stderr, "Error: Missing --in for --print.\n");
            print_usage();
            return 1;
        }
    }
    // Неизвестный флаг
    else {
        fprintf(stderr, "Error: Unknown option %s\n", argv[1]);
        print_usage();
        return 1;
    }

    return 0;
}
