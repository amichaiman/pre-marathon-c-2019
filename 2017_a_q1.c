#include <stdio.h>
#define SIZE (9)
#define BLOCK_SIZE (3)
#define LEGAL (0)

void print_board(int board[][SIZE]) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        putchar('\n');
    }
}

int legal_num(int n) {
    return n >= 1 && n <= SIZE;
}

int is_legal_row(int row[]) {
    int nums[SIZE] = {0};
    int i;

    /* mark which numbers are in row */
    for (i=0; i<SIZE; i++) {
        if (legal_num(row[i])) {
            nums[row[i]-1] = 1;
        }
    }

    /* check for missing numbers */
    for (i=0; i<SIZE; i++) {
        if (!nums[i]) {
            return i+1;
        }
    }

    /* all numbers between 1-9 appear */
    return LEGAL;
}

int all_rows_legal(int board[][SIZE]) {
    int i;

    for (i=0; i<SIZE; i++) {
        if (is_legal_row(board[i]) != LEGAL) {
            return i;
        }
    }
    return -1;
}

int is_legal_block(int board[][SIZE], int row, int col) {
    int nums[SIZE] = {0};
    int i, j;

    /* mark which numbers are in block */
    for (i=0; i<BLOCK_SIZE; i++) {
        for (j=0; j<BLOCK_SIZE; j++) {
            if (legal_num(board[row+i][col+j])) {
                nums[board[row+i][col+j]-1] = 1;
            }
        }
    }

    /* check for missing numbers */
    for (i=0; i<SIZE; i++) {
        if (!nums[i]) {
            return 0;
        }
    }

    /* all numbers between 1-9 appear */
    return 1;
}

int main() {
    int index;
    int board[][SIZE] = {
        { 5, 6, 2, 1, 7, 3, 9, 8, 5 },
        { 1, 7, 3, 5, 8, 9, 4, 2, 6 },
        { 8, 5, 9, 2, 6, 4, 3, 7, 1 },
        { 2, 4, 6, 7, 9, 8, 1, 5, 3 },
        { 5, 8, 1, 3, 2, 6, 7, 9, 4 },
        { 3, 9, 7, 4, 1, 5, 8, 6, 2 },
        { 6, 2, 4, 8, 3, 7, 5, 1, 9 },
        { 7, 1, 5, 9, 4, 2, 6, 3, 8 },
        { 9, 3, 8, 6, 5, 1, 2, 4, 7 }
    };
    print_board(board);

//    if ((index = all_rows_legal(board)) == -1) {
//        puts("all rows are legal");
//    } else {
//        printf("index %d isn't legal\n", index);
//    }

    puts("---------------------------------");

    if (is_legal_block(board, 0, 0)) {
        puts("block is legal");
    }
    return 0;
}
