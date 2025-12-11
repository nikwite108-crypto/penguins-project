// main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/board.h"
#include "src/game.h"
#include "src/utils.h"

// todo: 
// 1) change how many space do they want
// 2) add fish, ice & game victory

int main(void) {
    int xv, yv;

    while (!printf_modified("Enter number of vertical lines X: (max. 10): ", &xv, 1, 10)) {}
    while (!printf_modified("Enter number of horizontal lines Y (max. 10): ", &yv, 1, 10)) {}

    size_t cols = (size_t)xv;
    size_t rows = (size_t)yv;

    bool **board = board_init(rows, cols);
    if (!board) {
        printf("Failed to allocate board memory\n");
        return 1;
    }

    board_clear(board, rows, cols);

    bool start_player = (time(NULL) % 2);

    game_loop(board, rows, cols, start_player);

    board_free(board, rows);
    
    return 0;
}