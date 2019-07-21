#include <stdio.h>
#include <stdlib.h>

int* find(int* a, int size, int n) {
    int i;
    for (i=0; i<size; i++) {
        if (a[i] == n) {
            return a+i;
        }
    }
    return NULL;
}

int swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int are_equal(int *a, int *b, int size_a, int size_b) {
    if (size_a != size_b) {
        return 0;
    }

    if (size_a <= 0 || size_b <= 0) {
        return 1;
    }

    int *loc_cur_a_in_b = find(b, size_b, a[0]);

    if (!loc_cur_a_in_b) {
        return 0;
    }
    swap(b, loc_cur_a_in_b);

    return are_equal(a+1, b+1, size_a-1, size_b-1);
}

void print_array(int* a, int size) {
    int i;

    for (i=0; i<size; i++) {
        printf("%d\t", a[i]);
    }
    puts("");
}

int main() {
    int i;
    int *a = (int*) malloc (5*sizeof(int));
    int *b = (int*) malloc (5*sizeof(int));

    for (i=0; i<5; i++) {
        a[i] = i;
        b[i] = i;
    }
    swap(b, b+3);
    swap(b+1, b+2);
    swap(b+4, b);

    print_array(a, 5);
    print_array(b, 5);
    printf("The arrays are%s equal\n",
            are_equal(a, b, 5, 5) ? "" : "n't");

    return 0;
}

