#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the file name was provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *originalFile, *modifiedFile;
    char *originalFileName = argv[1]; // Get the file name from command line
    char modifiedFileName[100]; // Buffer for modified file name

    // Creating the modified file name
    snprintf(modifiedFileName, sizeof(modifiedFileName), "%s-modified-by-C", originalFileName);

    // Open the original file for reading
    originalFile = fopen(originalFileName, "r");
    if (originalFile == NULL) {
        perror("Error opening original file");
        return 1;
    }

    // Open the modified file for writing
    modifiedFile = fopen(modifiedFileName, "w");
    if (modifiedFile == NULL) {
        perror("Error opening modified file");
        fclose(originalFile);
        return 1;
    }

    // Read from the original and write to the modified file
    char ch;
    while ((ch = fgetc(originalFile)) != EOF) {
        fputc(ch, modifiedFile);
    }

    // Append the specified line
    fprintf(modifiedFile, "\nmodified with C\n");

    // Close the files
    fclose(originalFile);
    fclose(modifiedFile);

    printf("File has been modified and saved as %s\n", modifiedFileName);
    return 0;
}
