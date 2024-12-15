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

    if (strcmp(argv[1], "--generate") == 0) {
        // Ищем N и --out=file
        int count = 0;
        const char* output_file = "output.csv";

        for (int i = 2; i < argc; i++) {
            if (strncmp(argv[i], "--out=", 6) == 0) {
                output_file = argv[i] + 6; // Всё после "--out="
            } else {
                // Предполагаем, что это число
                int val = atoi(argv[i]);
                if (val > 0) count = val;
            }
        }

        if (count <= 0) {
            fprintf(stderr, "Error: Invalid count for --generate.\n");
            print_usage();
            return 1;
        }

        handle_generate(count, output_file);
    } 
    else if (strcmp(argv[1], "--sort") == 0) {
        const char* input_file = NULL;
        const char* output_file = NULL;

        // Ищем --in=... и --out=...
        for (int i = 2; i < argc; i++) {
            if (strncmp(argv[i], "--in=", 5) == 0) {
                input_file = argv[i] + 5; 
            } else if (strncmp(argv[i], "--out=", 6) == 0) {
                output_file = argv[i] + 6;
            }
        }

        if (!input_file || !output_file) {
            fprintf(stderr, "Error: Missing --in or --out for --sort.\n");
            print_usage();
            return 1;
        }

        handle_sort(input_file, output_file);
    }
    else if (strcmp(argv[1], "--print") == 0) {
        const char* input_file = NULL;

        // Ищем --in=...
        for (int i = 2; i < argc; i++) {
            if (strncmp(argv[i], "--in=", 5) == 0) {
                input_file = argv[i] + 5;
            }
        }

        if (!input_file) {
            fprintf(stderr, "Error: Missing or invalid --in for --print.\n");
            print_usage();
            return 1;
        }

        handle_print(input_file);
    } 
    else {
        fprintf(stderr, "Error: Unknown option %s\n", argv[1]);
        print_usage();
        return 1;
    }

    return 0;
}
