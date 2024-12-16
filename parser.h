#ifndef PARSER_H
#define PARSER_H

typedef enum {
    ACTION_NONE,
    ACTION_GENERATE,
    ACTION_SORT,
    ACTION_PRINT
} ActionType;

typedef struct {
    ActionType action;
    int count;
    const char* input_file;
    const char* output_file;
} ParsedArgs;

void print_usage();
int parse_arguments(int argc, char* argv[], ParsedArgs* args);

#endif
