// utils.c

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

bool printf_modified(const char *prompt, int *out, int min_allowed, int max_allowed) {
    printf("%s", prompt);

    int tmp;
    int rc = scanf("%d", &tmp);

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    if (rc != 1) {
        printf("Invalid input (not an integer).\n");
        return false;
    }

    if (tmp < min_allowed || tmp > max_allowed) {
        printf("Value out of allowed range [%d..%d]\n", min_allowed, max_allowed);
        return false;
    }

    *out = tmp;
    return true;
}
