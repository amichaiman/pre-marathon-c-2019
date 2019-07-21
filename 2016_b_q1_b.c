#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strchr(char* str, char c) {
    return strchr(str, c);
}

char** get_strings_that_contain_char(char strings[][20], int size, char c, int* result_size) {
    char **result = NULL;
    int i;
    *result_size = 0;

    for (i=0; i<size; i++) {
        if (my_strchr(strings[i], c)) {
            result = (char**) realloc (result, (++(*result_size))*sizeof(char*));
            result[*result_size-1] = (char*) malloc ((strlen(strings[i])+1)*sizeof(char));
            strcpy(result[*result_size-1], strings[i]);
        }
    }
    return result;
}

void print_strings(char **strings, int size) {
    int i;
    for (i=0; i<size; i++) {
        puts(strings[i]);
    }
}

int main() {
    char strings[4][20] = {
        "amichai",
        "yossi",
        "daniel",
        "dani"
    };
    int strings_that_contain_char_size;
    int size = 4, i;
    char **strings_that_contain_char;

    for (i=0; i<size; i++) {
        puts(strings[i]);
    }

    puts("-----------------------------------");
    strings_that_contain_char = get_strings_that_contain_char(strings, size, 'a', &strings_that_contain_char_size);
    print_strings(strings_that_contain_char, strings_that_contain_char_size);
    return 0;
}

