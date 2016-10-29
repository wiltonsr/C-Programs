#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SZ 256

int main() {
    char *name = malloc(MAX_NAME_SZ);
    if (name == NULL) {
        printf ("No memory\n");
        return EXIT_FAILURE;
    }

    printf("What is your name? ");

    fgets (name, MAX_NAME_SZ, stdin);

    if ((strlen(name)>0) && (name[strlen (name) - 1] == '\n'))
        name[strlen (name) - 1] = '\0';

    printf("Hello %s. Nice to meet you.\n", name);

    free (name);
    return EXIT_SUCCESS;
}
