// board.c

#include "board.h"
#include <stdio.h>
#include <stdlib.h>

bool **board_init(size_t rows, size_t cols) {
    bool **b = malloc((rows + 1) * sizeof(bool *));
    if (!b) return NULL;

    for (size_t i = 0; i <= rows; ++i) {
        b[i] = calloc((cols + 1), sizeof(bool));
        if (!b[i]) {
            for (size_t k = 0; k < i; ++k) {
                free(b[k]);
            }
            free(b);
            return NULL;
        }
    }
    return b;
}

void board_free(bool **board, size_t rows) {
    if (!board) return;
    for (size_t i = 0; i <= rows; ++i) {
        free(board[i]);
    }

    free(board);
}

void board_clear(bool **board, size_t rows, size_t cols) {
    if (!board) return;
    for (size_t r = 1; r <= rows; ++r)
        for (size_t c = 1; c <= cols; ++c)
            board[r][c] = false;
}

bool board_in_bounds(size_t rows, size_t cols, int r, int c) {
    if (r < 1 || c < 1) return false;
    if ((size_t)r > rows || (size_t)c > cols) return false;

    return true;
}

bool board_get(bool **board, int r, int c) {
    return board[r][c];
}

void board_set(bool **board, int r, int c, bool val) {
    board[r][c] = val;
}

void board_print(bool **board, size_t rows, size_t cols, bool reveal) {
    if (!board) return;
    
    for (size_t r = 1; r <= rows; ++r) {
        for (size_t c = 1; c <= cols; ++c) {
            if (reveal && board[r][c]) {
                printf("P(%zu,%zu)      ", c, r);
            } else {
                printf("(%zu,%zu)       ", c, r);
            }
        }
        printf("\n");
    }
}
