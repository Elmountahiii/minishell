#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = malloc(sizeof(int)); // Allocate memory

    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *ptr = 10; // Use allocated memory
    printf("Value: %d\n", *ptr);

    free(ptr); // Free memory

    // Use after free
    // *ptr = 20; // This is undefined behavior
    printf("Value: %d\n", *ptr); // This is undefined behavior

    return 0;
}