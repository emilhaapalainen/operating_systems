/* my-zip.c
 * Author: Emil Haapalainen
 *
 * Utility to compress files using run-length encoding (RLE)
 * n characters of same type in a row converts to number n and single character
 *
 * aaaaaaaaaabbbb => 10a4b
 *
 * Usage:
 * ./my-zip file.txt > file.z
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zip(FILE *input) {
    int count = 1;
    char current, previous;

    current = fgetc(input);
    // Ensure file is not empty
    if (current == EOF) {
        return;
    }
    
    // Iterate until char is EOF
    while (current != EOF) {
        previous = current;
        current = fgetc(input);
        // If concurrent characters, increment count
        if (previous == current) {
            count++;
        } else {
            // Write count to stdout, 4-byte integer, 1 element, 5-byte entry
            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&previous, sizeof(char), 1, stdout);
            //previous = current;
            count = 1;
        }
    }

    // Handle last character
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&previous, sizeof(char), 1, stdout);

}

int main(int argc, char *argv[]) {
    // Check that at least one file specified
    if (argc < 2) {
        fprintf(stderr, "my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
        { // Loop through each file if multiple
            FILE *input = fopen(argv[i], "r");
            if (input == NULL)
            {
                fprintf(stderr, "my-zip: cannot open file\n");
                exit(1);
            }
            zip(input);
            fclose(input);
        }
        
    exit(0);
}