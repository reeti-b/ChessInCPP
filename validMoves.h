#ifndef VALID_H
#define VALID_H 
#include <stdbool.h>
#include "board.h"

move* list_valid_moves(chessPiece** board, int* player, move *valid_moves, int* valid_move_count, move* log_moves, int* numberMoves);
bool isValidMove(move* valid_moves, int valid_move_count, int cur_row, int end_row, int cur_col, int end_col, chessPiece** board, move* log_moves, int* numberMoves, int* player);


#endif