/*
1. Create the board. done.
2. Display the board. not done.
3. While game not over: 
    1. Current player takes turn
    2. Switch player
4. 

## Create board
1. make a 8x8 character array
2. Put black pieces in first two rows 
3. Put white pieces in first two rows

##Display board
1. show indexing: a-h, 1-8
2. Show pieces
3. Show square boxes

##While game not over:

##Current player takes turn, switch player
1. white or black puts indexing, e.g. Ka1, or Qg6, and it will erase that piece from
current position and move it to the desired position
2. If it is black, then switch to white, if it is white, then switch to black

##Game over: 
1. Someone wins
2. Tie game

##Someone wins:
1. Through checkmate

##Tie game
1. Stalemate


switch, capture, undo(switch player) (use stack) (print u for undo)



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "board.c"
#include "board.h"

#include "move.c"
#include "move.h"

#include "validMoves.c"
#include "validMoves.h"




/*

 bool is_valid_move(chessPiece** board, int curRow, int cur_col, int endRow, int end_col) {

     if((curRow != 0) && (curRow != 1) && (curRow != 2) && (curRow != 3) && (curRow != 4) &&
     (curRow!=5) && (curRow != 6) && (curRow != 7)) {
         return false;
     }

     if((cur_col != 0) && (cur_col != 1) && (cur_col != 2) && (cur_col != 3) && (cur_col != 4) && (cur_col != 5) && 
     (cur_col != 6) && (cur_col != 7)) {
        return false;
     }

     if((endRow != 0) && (endRow != 1) && (endRow != 2) && (endRow != 3) && (endRow != 4) &&
     (endRow!=5) && (endRow != 6) && (endRow != 7)) {
         return false;
     }

     if((end_col != 0) && (end_col != 1) && (end_col != 2) && (end_col != 3) && (end_col != 4) && (end_col != 5) && 
     (end_col != 6) && (end_col != 7)) {
        return false;
     }



    //  char* pieceColor;
    //  char pieceType;
    //  pieceColor = (char*)malloc(20*sizeof(char));

    //  strcpy(pieceColor, board[curRow][cur_col].color);
    //  pieceType = board[curRow][cur_col].typePiece;

    //  if((strcmp(pieceColor, "\e[0;35m") != 0) && (strcmp(pieceColor, "\e[0;36m") != 0)) {
    //      return false;
    //  }

//     if((pieceType != 'p') && (pieceType != 'R') && (pieceType != 'N') && (pieceType != 'B') &&
//     (pieceType != 'Q') && (pieceType != 'K')) {

//     }


//     
//     if not valid piece or color, then return false






 }
 */

// void capture() {


//     /*

//     what do you need for a piece to capture another piece?
//     1. It needs to be the opposite color, there needs to be an actual piece there.
//     2. The piece should be able to capture in the specific piece's way
//     3. Once it captures, that piece disappears, and the piece goes to that location
//     4. This means that every time a player makes a move, we need to evaluate, is it a capture?
//     Then, if it is indeed a capture, we let it move that way, or else we don't.
    
    


//     When a player makes a move, there are two possibilities:
//     1. It moves to a blank spot.
//     2. It moves to a spot where there is already a piece there.

//     In the case where there already is a piece there, there are two possibilities:
//     1. The piece could be of the same color, in which case, tell the player that they can't play that move.
//     2. The piece could of a different color, in which case, we need to evaluate if it is a valid capture.
    
    
//     */
// }

/*

void play_game(chessPiece** board, int player) {


    while(!is_game_over(board, player)) {
        curr_player_takes_turn(board, player);
        switch_player();
    }

}

*/



int main() {
    move* log_moves = (move*)malloc(sizeof(move));
    int numberMoves = 0;


    int player = 0;
    chessPiece** board = create_board();
    display_board(board,&player);

   // bool is_en_passant = false;

while(true) {
    curr_player_takes_turn(board, &player, log_moves, &numberMoves);
    switch_player(&player);
    display_board(board,&player);

    log_moves = (move*)realloc(log_moves,(1+(sizeof(log_moves)))*sizeof(move));


}

                          
    free(log_moves);
    return 0;
}