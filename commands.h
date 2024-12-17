#ifndef COMMANDS_H
#define COMMANDS_H

#include "parser.h"

void handle_generate(int count, const char* output_file);
void handle_sort(const char* input_file, const char* output_file, SortOrder order);
void handle_print(const char* input_file);

#endif
