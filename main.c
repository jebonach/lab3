#include <stdio.h>
#include <stdlib.h>
#include "commands.h"
#include "parser.h"

int main(int argc, char* argv[]) {
    ParsedArgs args;
    if (parse_arguments(argc, argv, &args) != 0) {
        return 1;
    }

    switch (args.action) {
        case ACTION_GENERATE:
            handle_generate(args.count, args.output_file);
            break;
        case ACTION_SORT:
            handle_sort(args.input_file, args.output_file);
            break;
        case ACTION_PRINT:
            handle_print(args.input_file);
            break;
        default:
            print_usage();
            return 1;
    }

    return 0;
}
