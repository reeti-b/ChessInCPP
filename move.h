#ifndef MOVE_H
#define MOVE_H 

typedef struct move_struct {
   int cRow;
   int eRow;
   int c_col;
   int e_col;
   chessPiece piece_at_end_index;
   bool passant;
} move;


void undo_command(chessPiece** board, move* log_moves, int* numberMoves, int* player);
void curr_player_takes_turn(chessPiece** board, int* player, move* log_moves, int* numberMoves);
void switch_player(int* player);


#endif
