#ifndef IO_H
#define IO_H

#include "list.h"

void write_to_file(const char* filename, const List* list);
void read_from_file(const char* filename, List* list);

#endif // IO_H
