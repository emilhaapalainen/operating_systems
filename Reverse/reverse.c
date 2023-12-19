/* Reverse.c
 * Author: Emil Haapalainen
 *
 * Simple program to reverse the contents of input stream or a file with the ability to write the
 * changes to an output file or print them to the terminal.
 *
 * Usage:    prompt> ./reverse       (CTRL+D to stop inputting new lines)
 *           prompt> ./reverse input.txt
 *           prompt> ./reverse input.txt output.txt
 *
 *
 * Help sources:
 *    - man pages
 *    - Pointers and pointers of pointers: https://www.tutorialspoint.com/cprogramming/c_pointers.htm
 *    - File operations: https://users.cs.utah.edu/~germain/PPS/Topics/C_Language/file_IO.html
 *    - LUT C Programming course book
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input = stdin;
    FILE *output = stdout;
    char *line = NULL;
    char **lines = NULL;
    size_t lineSize = 0;
    int ch;
    int lineCount = 0;
    int i;

    // Check if no arguments given, read from stdin, write to stdout
    if (argc == 1)
    {
        while ((ch = fgetc(stdin)) != EOF)
        {
            line = realloc(line, lineSize + 1);
            if (line == NULL)
            { // If lines is NULL, malloc failed => exit(1)
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }
            line[lineSize++] = ch;

            if (ch == '\n') {
                line[lineSize - 1] = 0; // Removing newline char from each line
                // Dynamic memory allocation to lines which increases the size each line
                lines = realloc(lines, (lineCount + 1) * sizeof(char *));
                if (lines == NULL)
                { // If lines is NULL, malloc failed => exit(1)
                    fprintf(stderr, "malloc failed\n");
                    exit(1);
                }
                lines[lineCount] = line; // Returns pointer to new string
                line = NULL; // Reset line for next use
                lineSize = 0; // Reset line size for next use
                lineCount++;
            }
        }
        // Printing lines from bottom to top
        for (i = lineCount - 1; i >= 0; i--)
        {
            puts(lines[i]);
            free(lines[i]); // Free used lines after done
        }
        free(lines); // Free array
        free(line); // Free last line
    }
    else if (argc == 2)
    {
        // Input file provided, use that instead of stdin
        input = fopen(argv[1], "r");
        if (input == NULL)
        { // Check if input file was opened
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
        while ((ch = fgetc(input)) != EOF)
        {
            line = realloc(line, lineSize + 1);
            if (line == NULL)
            { // If lines is NULL, malloc failed => exit(1)
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }
            line[lineSize++] = ch;

            if (ch == '\n') {
                line[lineSize - 1] = 0; // Removing newline char from each line
                // Dynamic memory allocation to lines which increases the size each line
                lines = realloc(lines, (lineCount + 1) * sizeof(char *));
                if (lines == NULL)
                { // If lines is NULL, malloc failed => exit(1)
                    fprintf(stderr, "malloc failed\n");
                    exit(1);
                }
                lines[lineCount] = line; // Returns pointer to new string
                line = NULL; // Reset line for next use
                lineSize = 0; // Reset line size for next use
                lineCount++;
            }
        }
        // Printing lines from bottom to top
        for (i = lineCount - 1; i >= 0; i--)
        {
            puts(lines[i]);
            free(lines[i]); // Free used lines after done
        }
        free(lines); // Free array
        free(line); // Free last line
        fclose(input);
    }

    // Check for too many arguments
    if (argc > 3)
    {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    // Handle output file opening
    if (argc == 3)
    { // Ensure that input and output are not the same file
        if (strcmp(argv[1], argv[2]) == 0)
        {
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }
        input = fopen(argv[1], "r");
        output = fopen(argv[2], "w");
        if (output == NULL)
        {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
            fclose(input);
            exit(1);
        }
        while ((ch = fgetc(input)) != EOF)
        {
            line = realloc(line, lineSize + 1);
            if (line == NULL)
            { // If lines is NULL, malloc failed => exit(1)
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }
            line[lineSize++] = ch;

            if (ch == '\n') {
                line[lineSize - 1] = 0; // Removing newline char from each line
                // Dynamic memory allocation to lines which increases the size each line
                lines = realloc(lines, (lineCount + 1) * sizeof(char *));
                if (lines == NULL)
                { // If lines is NULL, malloc failed => exit(1)
                    fprintf(stderr, "malloc failed\n");
                    exit(1);
                }
                lines[lineCount] = line; // Returns pointer to new string
                line = NULL; // Reset line for next use
                lineSize = 0; // Reset line size for next use
                lineCount++;
            }
        }
        // Printing lines from bottom to top
        for (i = lineCount - 1; i >= 0; i--)
        {
            fprintf(output, "%s\n", lines[i]); // Write to file instead of stdout
            free(lines[i]);                    // Free used lines after done
        }
        free(lines);
        free(line);
        fclose(input);
        fclose(output);
    }
}