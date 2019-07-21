#include <stdio.h>
#include <ctype.h>

#define POSITIVE ('+')
#define NEGATIVE ('-')

// returns first not space char
char* skip_spaces(char* s) {
    while (isspace((*s))) { //skip all spaces
        s++;
    }
    return s;
}
/* a */
int sum(char* s) {
    int my_num;
    int sign = POSITIVE;

    // if s is null      if reached '\0'
    if (!s            || !(*s)) {
        return 0;
    }

    s = skip_spaces(s);

    if (!isdigit(*s)) { // s is now pointing to digit or sign
        sign = *s;
        s++;
        s = skip_spaces(s);
    }

    my_num = *s - '0'; // s is pointing at digit

    return (sign == POSITIVE ? my_num : -my_num) + sum(s+1);
}

int is_sign(char c) {
    return c == '-' || c == '+';
}

/* b */
int is_legal_equ(char* s, int* p_sum) {
    char* tmp = s;

    tmp = skip_spaces(tmp);

    if (!isdigit(*tmp)) {
        return 0;
    }

    tmp++;
    while (*tmp) {
        tmp = skip_spaces(tmp);
        if (!is_sign(*tmp)) {
            return 0;
        }
        tmp++;
        tmp = skip_spaces(tmp);
        if (!isdigit(*tmp)) {
            return 0;
        }
        tmp++;
    }
    *p_sum = sum(s);
    return 1;
}

int main() {
    char s[] = "5 +6-4-3+ 2";
    int sum;
    int is_legal = is_legal_equ(s, &sum);

    if (is_legal) {
        printf("The sum of %s is %d\n", s, sum);
    } else {
        puts("equ isn't legal");
    }
    return 0;
}

