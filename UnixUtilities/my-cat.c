/* My-cat.c
 * Author:Emil Haapalainen
 *
 * Simple alternative to UNIX cat command. Prints the contents of file(s) to stdout.
 * Files are given as arguments, multiple allowed.
 * 
 * Usage:
 * ./my-cat {file1} {file2} ...
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input;
    int ch;

    // No arguments given, exit 0
    if (argc == 1)
    {
        exit(0);
    }

    for (int i = 1; i < argc; i++)
    {
        input = fopen(argv[i], "r");
        if (input == NULL)
        { // File opening failed
            fprintf(stderr, "my-cat: cannot open file\n");
            exit(1);
        }
        while ((ch = fgetc(input)) != EOF)
        { // Read until EOF
            printf("%c", ch);
        }
        fclose(input);
        printf("\n");
    }
    return 0;
}