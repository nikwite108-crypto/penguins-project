// board.h

#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stddef.h>

bool **board_init(size_t rows, size_t cols);
/* Allocate and return pointer to board. Returns NULL on failure. */

void board_free(bool **board, size_t rows);
/* Free memory allocated by board_init */

void board_clear(bool **board, size_t rows, size_t cols);
/* Set all cells to false */

bool board_in_bounds(size_t rows, size_t cols, int r, int c);
/* Return true if 1 <= r <= rows and 1 <= c <= cols */

bool board_get(bool **board, int r, int c);
/* Return value at [r][c] */

void board_set(bool **board, int r, int c, bool val);
/* Set value at [r][c] */

void board_print(bool **board, size_t rows, size_t cols, bool reveal);
/* Print board to stdout
   true -> print 'P(coordinates)' for penguins,
   false -> print (coordinates) only */

#endif