#ifndef PARSER_H
#define PARSER_H

typedef enum {
    ACTION_NONE,
    ACTION_GENERATE,
    ACTION_SORT,
    ACTION_PRINT
} ActionType;

typedef enum {
    SORT_ASC,
    SORT_DESC
} SortOrder;

typedef struct {
    ActionType action;
    int count;              
    const char* input_file; 
    const char* output_file;
    SortOrder order; 
} ParsedArgs;

void print_usage();
int parse_arguments(int argc, char* argv[], ParsedArgs* args);

#endif
