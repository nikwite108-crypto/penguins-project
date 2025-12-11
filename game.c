// game.c

#include "game.h"
#include "board.h"
#include "utils.h"
#include <stdio.h>

static void print_current_player(bool player) {
    printf("\nCurrent Player: %s\n", player ? "1" : "0");
}

void game_loop(bool **board, size_t rows, size_t cols, bool start_player) {
    bool current = start_player;
    
    while (1) {
        print_current_player(current);
        board_print(board, rows, cols, true);

        printf("\nOptions:\n 1 - place penguin\n 0 - pass & change player\n 9 - exit game\n");
        int action;
        if (!printf_modified("Enter option: ", &action, 0, 9)) continue;

        if (action == 9) {
            printf("Exiting game.\n");
            break;
        } else if (action == 0) {
            current = !current;
            continue;
        } else if (action == 1) {
            int xval, yval;
            if (!printf_modified("Enter X (cols): ", &xval, 1, (int)cols)) continue;
            if (!printf_modified("Enter Y (rows): ", &yval, 1, (int)rows)) continue;

            if (!board_in_bounds(rows, cols, yval, xval)) {
                printf("Coordinates out of bounds.\n");
                continue;
            }

            if (board_get(board, yval, xval)) {
                printf("There is already a penguin at (%d,%d)\n", xval, yval);
                continue;
            }

            int confirm;
            if (!printf_modified("Confirm place penguin?\n 1 - yes\n 0 - no:\n", &confirm, 0, 1)) continue;
            if (confirm == 1) {
                board_set(board, yval, xval, true);
                current = !current;
            } else {
                printf("Placement cancelled.\n");
            }
            continue;
        } else {
            printf("Unknown option.\n");
            continue;
        }
    }
}