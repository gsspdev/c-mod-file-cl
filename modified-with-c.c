#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *originalFile, *modifiedFile;
    char originalFileName[] = "example.txt"; // Replace with your file name
    char modifiedFileName[50];

    // Creating the modified file name
    strcpy(modifiedFileName, originalFileName);
    strcat(modifiedFileName, "-modified-by-C");

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

