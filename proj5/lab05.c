#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sort an array of words by length
void sortWordsByLength(char** words, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap words
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of words: ");
    scanf("%d", &n);

    // Allocate memory for an array of pointers to strings
    char** words = (char**)malloc(n * sizeof(char*));
    if (words == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    printf("Enter the words:\n");
    for (int i = 0; i < n; i++) {
        words[i] = (char*)malloc(100 * sizeof(char));
        if (words[i] == NULL) {
            printf("Memory allocation error.\n");
            return 1;
        }
        scanf("%s", words[i]);
    }

    sortWordsByLength(words, n);

    printf("Words after sorting by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
        free(words[i]); // Free memory for each word
    }

    free(words); // Free memory for the array of pointers

    return 0;
}