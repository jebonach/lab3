#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void print_usage() {
    printf("Usage: \n");
    printf("  Generate: ./program --generate N --out=file.csv\n");
    printf("  Sort:     ./program --sort --in=file.csv --out=file.csv\n");
    printf("  Print:    ./program --print --in=file.csv\n");
}


int parse_arguments(int argc, char* argv[], ParsedArgs* args) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    args->action = ACTION_NONE;
    args->count = 0;
    args->input_file = NULL;
    args->output_file = NULL;

    if (strcmp(argv[1], "--generate") == 0) {
        args->action = ACTION_GENERATE;
        for (int i = 2; i < argc; i++) {
            if (strncmp(argv[i], "--out=", 6) == 0) {
                args->output_file = argv[i] + 6;
            } else {
                int val = atoi(argv[i]);
                if (val > 0) {
                    args->count = val;
                }
            }
        }
        if (args->count <= 0) {
            fprintf(stderr, "Error: Invalid count for --generate.\n");
            print_usage();
            return 1;
        }
        if (!args->output_file) {
            args->output_file = "output.csv";
        }
    }
    else if (strcmp(argv[1], "--sort") == 0) {
        args->action = ACTION_SORT;
        for (int i = 2; i < argc; i++) {
            if (strncmp(argv[i], "--in=", 5) == 0) {
                args->input_file = argv[i] + 5;
            } else if (strncmp(argv[i], "--out=", 6) == 0) {
                args->output_file = argv[i] + 6;
            }
        }
        if (!args->input_file || !args->output_file) {
            fprintf(stderr, "Error: Missing --in or --out for --sort.\n");
            print_usage();
            return 1;
        }
    }
    else if (strcmp(argv[1], "--print") == 0) {
        args->action = ACTION_PRINT;
        for (int i = 2; i < argc; i++) {
            if (strncmp(argv[i], "--in=", 5) == 0) {
                args->input_file = argv[i] + 5;
            }
        }
        if (!args->input_file) {
            fprintf(stderr, "Error: Missing or invalid --in for --print.\n");
            print_usage();
            return 1;
        }
    }
    else {
        fprintf(stderr, "Error: Unknown option %s\n", argv[1]);
        print_usage();
        return 1;
    }

    return 0;
}
