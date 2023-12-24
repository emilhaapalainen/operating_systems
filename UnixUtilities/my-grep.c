/* my-grep.c
 * Author: Emil Haapalainen
 *
 * Simple alternative to UNIX grep command. 
 * Looks for user-specified search term in file(s) and prints the line if found.
 * Search is case sensitive, thus "dog" and "Dog" will not match.
 * If nothing is found, program simply exits.
 * Multiple files are allowed.
 * 
 *
 * Usage:
 * ./my-grep {search} {file1} {file2} ...
 *
 * Example: ./my-grep "spaniel" "dogBreeds.txt"
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grepFunction(FILE *input, char *searchTerm) {
    char *line = NULL;
    size_t lineSize = 0;


}

int main(int argc, char *argv[]) {

    FILE *input;

    if (argc == 1) {    //No arguments specified, exit 1
        fprintf(stderr, "my-grep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc == 2)  {
        input = stdin;  //No file specified, reading from stdin
        grepFunction(input, argv[1]);
    }

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {    //Loop through each file if multiple
            input = fopen(argv[i], "r");
            if (input == NULL) {
                fprintf(stderr, "my-grep: cannot open file\n");
                exit(1);
            }
            grepFunction(input, argv[i]);
            fclose(input);
        }
        return 0;
    }

}