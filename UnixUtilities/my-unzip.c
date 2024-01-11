/* my-unzip.c
 * Author: Emil Haapalainen
 *
 * Tool to decompress compressed files zipped with ./my-zip
 *
 *
 * Usage:
 * ./my-unzip file.z
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unzip(FILE *input) {
    int count;
    char character;

    // Read integer count
    while (fread(&count, sizeof(int), 1, input) == 1) {
        // Output char * count
        fread(&character, sizeof(char), 1, input);
        for (int i = 0; i < count; i++) {
            putchar(character);
        }
    }
}

int main(int argc, char *argv[]) {
    // Check that at least one file specified
    if (argc < 2) {
        fprintf(stderr, "my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
        { // Loop through each file if multiple
            FILE *input = fopen(argv[i], "rb");
            if (input == NULL)
            {
                fprintf(stderr, "my-unzip: cannot open file\n");
                exit(1);
            }
            unzip(input);
            fclose(input);
        }

    exit(0);
}

