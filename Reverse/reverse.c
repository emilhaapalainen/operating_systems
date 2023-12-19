/*
Help sources:
    - man pages
    - Pointers and pointers of pointers: https://www.tutorialspoint.com/cprogramming/c_pointers.htm
    - File operations: https://users.cs.utah.edu/~germain/PPS/Topics/C_Language/file_IO.html
    - 

*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *input = stdin;
    FILE *output = stdout;
    char line[MAX_LENGTH];
    char **lines = NULL;
    int lineCount = 0;
    int i;

    //Check if no arguments given, read from stdin, write to stdout
    if (argc == 1) {
        while (fgets(line, MAX_LENGTH, stdin)) {
            line[strcspn(line, "\n")] = 0;                          //Removing newline char from each line

            //Dynamic memory allocation to lines which increases the size each line
            lines = realloc(lines, (lineCount + 1) * sizeof(char *));
            if (lines == NULL) {                                    //If lines is NULL, malloc failed => exit(1)
                fprintf(stderr, "Memory allocation failure\n");
                exit(1);
            }
            lines[lineCount] = strdup(line);                        //Returns pointer to new duplicated string
            if (lines[lineCount] == NULL) {
                fprintf(stderr, "Memory allocation failure");       //if lines is NULL, strdup malloc failed => exit(1)
                exit(1);
            }
            lineCount++;
        }
        //Printing lines from bottom to top
        for (i = lineCount - 1; i >= 0; i--) {
            puts(lines[i]);
            free(lines[i]);                                         //Free used lines after done
        }
        free(lines);                                                //Free array
    }   else if (argc == 2) {
        //Input file provided, use that instead of stdin
            input = fopen(argv[1], "r");
            if (input == NULL) {                                    //Check if input file was opened
                fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
                exit(1);
            }
            while (fgets(line, MAX_LENGTH, input)) {
                line[strcspn(line, "\n")] = 0;                          //Removing newline char from each line

                //Dynamic memory allocation to lines which increases the size each line
                lines = realloc(lines, (lineCount + 1) * sizeof(char *));
                if (lines == NULL) {                                    //If lines is NULL, malloc failed => exit(1)
                    fprintf(stderr, "Memory allocation failure\n");
                    exit(1);
                }
                lines[lineCount] = strdup(line);                        //Returns pointer to new duplicated string
                if (lines[lineCount] == NULL) {
                    fprintf(stderr, "Memory allocation failure");       //if lines is NULL, strdup malloc failed => exit(1)
                    exit(1);
                }
                lineCount++;
        }
        //Printing lines from bottom to top
        for (i = lineCount - 1; i >= 0; i--) {
            puts(lines[i]);
            free(lines[i]);                                         //Free used lines after done
        }
        free(lines);
        fclose(input);
    }

    //Check for too many arguments
    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    //Handle output file opening
    if(argc == 3) {
        if (strcmp(argv[1], argv[2]) == 0) {
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }
        input = fopen(argv[1], "r");
        output = fopen(argv[2], "w");
        if (output == NULL) {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
            fclose(input);
            exit(1);
        }
        while (fgets(line, MAX_LENGTH, input)) {
                line[strcspn(line, "\n")] = 0;                          //Removing newline char from each line

                //Dynamic memory allocation to lines which increases the size each line
                lines = realloc(lines, (lineCount + 1) * sizeof(char *));
                if (lines == NULL) {                                    //If lines is NULL, malloc failed => exit(1)
                    fprintf(stderr, "Memory allocation failure\n");
                    exit(1);
                }
                lines[lineCount] = strdup(line);                        //Returns pointer to new duplicated string
                if (lines[lineCount] == NULL) {
                    fprintf(stderr, "Memory allocation failure");       //if lines is NULL, strdup malloc failed => exit(1)
                    exit(1);
                }
                lineCount++;
        }
        //Printing lines from bottom to top
        for (i = lineCount - 1; i >= 0; i--) {
            fprintf(output, "%s\n", lines[i]);                          //Write to file instead of stdout
            free(lines[i]);                                             //Free used lines after done
        }
        free(lines);
        fclose(input);
        fclose(output);
    }

}