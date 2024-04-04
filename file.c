#include <stdio.h>

int main() {
    FILE *filePointer;

    // Open file in write mode
    filePointer = fopen("test.txt", "a");

    // Check if file opened successfully
    if (filePointer == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write to the file
    fprintf(filePointer, "Hello!\n");

    // Close the file
    fclose(filePointer);

    printf("File created and text written successfully.\n");

    return 0;
}