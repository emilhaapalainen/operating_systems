#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *input = stdin;
    FILE *output = stdout;
    char line[1024];
    char **lines = NULL;
    int lineCount = 0;

    //Check if no arguments given
    if (argc == 1) {
        fprintf(stderr, "No arguments given, at least input file expected. Usage ./reverse {input.txt} {output.txt}\n");
        return 1;
    }

    //Check for too many arguments
    if (argc > 3) {
        fprintf(stderr, "Too many arguments given. Usage ./reverse {input.txt} {output.txt}\n");
        return 1;
    }

    //Handle input file opening
    if (argc == 2) {
        input = fopen(argv[1], "r");
        if (input == NULL) {
            perror("Error opening input file.");
            return 1;
        }
    }

    //Handle output file opening
    if(argc == 3) {
        input = fopen(argv[1], "r");
        output = fopen(argv[2], "w");
        if (output == NULL) {
            perror("Error opening output file.");
            fclose(input);
            return 1;
        }
    }


}