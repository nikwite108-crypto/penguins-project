// game.h

#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <stddef.h>

/* game_loop(board, rows, cols)
   Start the interactive loop using the provided board.
   Alternates players automatically. */
void game_loop(bool **board, size_t rows, size_t cols, bool start_player);

#endif