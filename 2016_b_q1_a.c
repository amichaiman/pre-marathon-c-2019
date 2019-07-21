#include <stdio.h>
#include <string.h>

char* my_strchr_1(char* str, char c) {
    while (*str) {
        if (*str == c) {
            return str;
        }
        str++;
    }
    return NULL;
}

char* my_strchr_2(char* str, char c) {
    int i;

    for (i=0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return &str[i];
        }
    }

    return NULL;
}

/* the best solution ever */
char* my_strchr_3(char* str, char c) {
    return strchr(str, c);
}

int main() {
    char s[] = "amichai";
    char c = 'c';

    printf("the char %c is%s in the string %s\n",
            c, my_strchr_1(s, c) ? "" : "n't", s);

    puts("------------------------");
    printf("the char %c is%s in the string %s\n",
            c, my_strchr_2(s, c) ? "" : "n't", s);

    puts("------------------------");
    printf("the char %c is%s in the string %s\n",
            c, my_strchr_3(s, c) ? "" : "n't", s);
    return 0;
}

