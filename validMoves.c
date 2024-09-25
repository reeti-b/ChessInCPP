#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "move.h"

bool isValidMove(move* valid_moves, int valid_move_count, int cur_row, int end_row, int cur_col, int end_col, chessPiece** board, move* log_moves, int* numberMoves, int* player) {
    for(int c = 0; c < valid_move_count;c++){
        if(  (valid_moves[c].cRow == cur_row) && (valid_moves[c].eRow == end_row) && (valid_moves[c].c_col == cur_col) && (valid_moves[c].e_col == end_col)) {
            if (valid_moves[c].passant == true) /*&& ((*player) == 0) && (cur_row==3) && (log_moves[(*numberMoves)-1].cRow == 1) && (log_moves[(*numberMoves)-1].eRow == 3) && (log_moves[(*numberMoves)-1].c_col == log_moves[(*numberMoves)-1].e_col) && ((log_moves[(*numberMoves)-1].e_col == (cur_col+1)) || (log_moves[(*numberMoves)-1].e_col == (cur_col-1)))  
                    && (board[2][log_moves[(*numberMoves)-1].e_col].typePiece == ' ') && (board[1][log_moves[(*numberMoves)-1].e_col].numberOfTimesPieceMoved == 1) */ {
                        printf("En passant is the player's move!\n");
                        log_moves[(*numberMoves)].passant = true;
            }
            // if (valid_moves[c].passant == true) /* && ((*player) == 1) && (cur_row==4) && (log_moves[(*numberMoves)-1].cRow == 6) && (log_moves[(*numberMoves)-1].eRow == 4) && (log_moves[(*numberMoves)-1].c_col == log_moves[(*numberMoves)-1].e_col) && ((log_moves[(*numberMoves)-1].e_col == (cur_col+1)) || (log_moves[(*numberMoves)-1].e_col == (cur_col-1)))  
            //         && (board[5][log_moves[(*numberMoves)-1].e_col].typePiece == ' ') && (board[6][log_moves[(*numberMoves)-1].e_col].numberOfTimesPieceMoved == 1 )*/   {
            //             printf("En passant the player's move!\n");
            //             log_moves[(*numberMoves)].passant = true;
            // }

            return true;
        }
}
return false;
}

bool player_is_in_Check() {
    return false;
}


//maybe make separate valid move functions for separate colors? 
move* list_valid_moves(chessPiece** board, int* player, move *valid_moves, int *valid_move_count,move* log_moves,int* numberMoves) {

    // if(((*player) == 0) && (strcmp(board[curRow][curCol].color,"\e[0;36m") == 0) ) {
    //     return false;
    // }
    // if(((*player) == 1) && (strcmp(board[curRow][curCol].color,"\e[0;35m") == 0) ) {
    //     return false;
    // }

    if((*player) == 0) {
       
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((board[i][j].typePiece == 'p') && (strcmp(board[i][j].color,"\e[0;35m") == 0)) {


                if(player_is_in_Check()) {
                    //valid moves when in check
                }  
                else {


                    if((i == 6) && (board[i-2][j].typePiece == ' ') && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6) || (j == 7) ) )  {

                        
                        (*valid_move_count)++;
                        
                        
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = (i-2);
                        valid_moves[(*valid_move_count)-1].e_col = j;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = ' ';
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); 
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,"");

                      //  printf("For moving two spaces: \n cur Row: %d, cur Col: %d, end Row: %d, end Col: %d\n",valid_moves[valid_move_count-1].cRow,valid_moves[valid_move_count-1].c_col,valid_moves[valid_move_count-1].eRow,valid_moves[valid_move_count-1].e_col);
                       
                        //2nd row pawn moves two spaces forward
                    }

                    if(i!=0) {

                    if((board[i-1][j].typePiece == ' ') && (strcmp(board[i][j].color,"\e[0;35m") == 0) ) {
                      //  printf("Magenta can move one space!\n");
                        (*valid_move_count)++;
                        
                        
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = (i-1);
                        valid_moves[(*valid_move_count)-1].e_col = j;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = ' ';
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); 
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,"");

                     //   printf("For moving one space: \n cur Row: %d, cur Col: %d, end Row: %d, end Col: %d\n",valid_moves[valid_move_count-1].cRow,valid_moves[valid_move_count-1].c_col,valid_moves[valid_move_count-1].eRow,valid_moves[valid_move_count-1].e_col);
                        //any pawn moves one space forward

                    } 
                    }

                    if(i!=0) {
                    if((board[i-1][j+1].typePiece != ' ') && (strcmp(board[i-1][j+1].color,"\e[0;36m") == 0) && (i!=0) && (strcmp(board[i][j].color,"\e[0;35m") == 0)) {
                        
                        (*valid_move_count)++;
                        
                        
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = (i-1);
                        valid_moves[(*valid_move_count)-1].e_col = (j+1);
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = board[i-1][j+1].typePiece;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); 
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,"\e[0;36m");

                     //   printf("For capturing top right: \n cur Row: %d, cur Col: %d, end Row: %d, end Col: %d\n",valid_moves[valid_move_count-1].cRow,valid_moves[valid_move_count-1].c_col,valid_moves[valid_move_count-1].eRow,valid_moves[valid_move_count-1].e_col);
                        //any pawn captures a piece to the top right
                    }
                    }
                    if(i!=0) {
                    if((board[i-1][j-1].typePiece != ' ') && (strcmp(board[i-1][j-1].color,"\e[0;36m") == 0) && (i!=0) && (j!=0) && (strcmp(board[i][j].color,"\e[0;35m") == 0) ) {
                        
                        (*valid_move_count)++;
                        
                        
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = (i-1);
                        valid_moves[(*valid_move_count)-1].e_col = (j-1);
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = board[i-1][j-1].typePiece;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); 
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,"\e[0;36m");

                     //   printf("For capturing top left: \n cur Row: %d, cur Col: %d, end Row: %d, end Col: %d\n",valid_moves[valid_move_count-1].cRow,valid_moves[valid_move_count-1].c_col,valid_moves[valid_move_count-1].eRow,valid_moves[valid_move_count-1].e_col);
                        //any pawn captures a piece to the top left
                    }
                    }
                    //we'll do en passant later
                    if( (i==3) && (log_moves[(*numberMoves)-1].cRow == 1) && (log_moves[(*numberMoves)-1].eRow == 3) && (log_moves[(*numberMoves)-1].c_col == log_moves[(*numberMoves)-1].e_col) && ((log_moves[(*numberMoves)-1].e_col == (j+1)) || (log_moves[(*numberMoves)-1].e_col == (j-1)))  
                    && (board[2][log_moves[(*numberMoves)-1].e_col].typePiece == ' ') && (board[3][log_moves[(*numberMoves)-1].e_col].typePiece == 'p') && (board[3][log_moves[(*numberMoves)-1].e_col].numberOfTimesPieceMoved == 1)  ) {

                        printf("En passant is a valid move here for Magenta!\n");
                         (*valid_move_count)++;
                        valid_moves[(*valid_move_count)-1].passant = true;
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = 2;
                        valid_moves[(*valid_move_count)-1].e_col = log_moves[(*numberMoves)-1].e_col;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = board[3][log_moves[(*numberMoves)-1].e_col].typePiece;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char));
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,board[3][log_moves[(*numberMoves)-1].e_col].color);
                    }

                    //en passant




                    //valid moves when normal
                }
                //add to array of valid moves all of the pawn's valid moves
            }
            // if((board[i][j].typePiece == 'R') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
            // if((board[i][j].typePiece == 'N') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
            // if((board[i][j].typePiece == 'B') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
            // if((board[i][j].typePiece == 'Q') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
            // if((board[i][j].typePiece == 'K') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
        }
    }
     
    }






    if((*player) == 1) {

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
            if((board[i][j].typePiece == 'p') && (strcmp(board[i][j].color,"\e[0;36m") == 0)) {


                if(player_is_in_Check()) {
                    //valid moves when in check
                }  
                else {


                    if((i == 1) && (board[i+2][j].typePiece == ' ') && ((j == 0) || (j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6) || (j == 7) ) )  {
                        (*valid_move_count)++;
                        
                        
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = (i+2);
                        valid_moves[(*valid_move_count)-1].e_col = j;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = ' ';
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); 
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,"");

                      //  printf("For moving two spaces: \n cur Row: %d, cur Col: %d, end Row: %d, end Col: %d\n",valid_moves[valid_move_count-1].cRow,valid_moves[valid_move_count-1].c_col,valid_moves[valid_move_count-1].eRow,valid_moves[valid_move_count-1].e_col);
                       
                        //2nd row pawn moves two spaces forward
                    }


                    if(i!=7) {
                    if((board[i+1][j].typePiece == ' ') && (strcmp(board[i][j].color,"\e[0;36m") == 0) ) {
                       // printf("Cyan can move one space!\n");
                        
                        (*valid_move_count)++;
                        
                        
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = (i+1);
                        valid_moves[(*valid_move_count)-1].e_col = j;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = ' ';
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); 
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,"");

                     //   printf("For moving one space: \n cur Row: %d, cur Col: %d, end Row: %d, end Col: %d\n",valid_moves[valid_move_count-1].cRow,valid_moves[valid_move_count-1].c_col,valid_moves[valid_move_count-1].eRow,valid_moves[valid_move_count-1].e_col);
                        //any pawn moves one space forward

                    } 

                }
                    

                    
                    if((board[i+1][j+1].typePiece != ' ') && (strcmp(board[i+1][j+1].color,"\e[0;35m") == 0) && (strcmp(board[i][j].color,"\e[0;36m") == 0) && (i!=7) && (j!=7)  ) {
                        
                        (*valid_move_count)++;
                        
                        
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = (i+1);
                        valid_moves[(*valid_move_count)-1].e_col = (j+1);
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = board[i+1][j+1].typePiece;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); 
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,"\e[0;35m");

                     //   printf("For capturing top right: \n cur Row: %d, cur Col: %d, end Row: %d, end Col: %d\n",valid_moves[valid_move_count-1].cRow,valid_moves[valid_move_count-1].c_col,valid_moves[valid_move_count-1].eRow,valid_moves[valid_move_count-1].e_col);
                        //any pawn captures a piece to the top right
                    }
                    
                    
                    if((board[i+1][j-1].typePiece != ' ') && (strcmp(board[i+1][j-1].color,"\e[0;35m") == 0) && (j!=0) && (strcmp(board[i][j].color,"\e[0;36m") == 0) ) {
                        
                        (*valid_move_count)++;

                        
                        
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = (i+1);
                        valid_moves[(*valid_move_count)-1].e_col = (j-1);
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = board[i+1][j-1].typePiece;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); 
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,"\e[0;35m");

                     //   printf("For capturing top left: \n cur Row: %d, cur Col: %d, end Row: %d, end Col: %d\n",valid_moves[valid_move_count-1].cRow,valid_moves[valid_move_count-1].c_col,valid_moves[valid_move_count-1].eRow,valid_moves[valid_move_count-1].e_col);
                        //any pawn captures a piece to the top left
                    }
                    
                    //we'll do en passant later
                    if( (i==4) && (log_moves[(*numberMoves)-1].cRow == 6) && (log_moves[(*numberMoves)-1].eRow == 4) && (log_moves[(*numberMoves)-1].c_col == log_moves[(*numberMoves)-1].e_col) && ((log_moves[(*numberMoves)-1].e_col == (j+1)) || (log_moves[(*numberMoves)-1].e_col == (j-1)))  
                    && (board[5][log_moves[(*numberMoves)-1].e_col].typePiece == ' ') && ((board[4][log_moves[(*numberMoves)-1].e_col].typePiece == 'p')) && (board[4][log_moves[(*numberMoves)-1].e_col].numberOfTimesPieceMoved == 1 )) {

                        printf("En passant is a valid move here for Cyan!\n");

                         (*valid_move_count)++;
                        valid_moves[(*valid_move_count)-1].passant = true;
                        valid_moves[(*valid_move_count)-1].cRow = i;
                        valid_moves[(*valid_move_count)-1].c_col = j;
                        valid_moves[(*valid_move_count)-1].eRow = 5;
                        valid_moves[(*valid_move_count)-1].e_col = log_moves[(*numberMoves)-1].e_col;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.typePiece = board[4][log_moves[(*numberMoves)-1].e_col].typePiece;
                        valid_moves[(*valid_move_count)-1].piece_at_end_index.color = (char*)malloc(20*sizeof(char));
                        strcpy(valid_moves[(*valid_move_count)-1].piece_at_end_index.color,board[4][log_moves[(*numberMoves)-1].e_col].color);
                    }


                    //valid moves when normal
                }
                //add to array of valid moves all of the pawn's valid moves
            }
            // if((board[i][j].typePiece == 'R') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
            // if((board[i][j].typePiece == 'N') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
            // if((board[i][j].typePiece == 'B') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
            // if((board[i][j].typePiece == 'Q') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
            // if((board[i][j].typePiece == 'K') && (strcmp(board[i][j].color,"\e[0;35m"))) {
            //     //add to array of valid moves all of the pawn's valid moves
            // }
        }
    }

    }


    // if(board[curRow][curCol].typePiece == 'p') {
    //     //print valid pawn moves
    //     return is_valid_pawn_move(board, curRow, curCol, endRow, endCol);//valid moves for pawn 
    // }
    // if(board[curRow][curCol].typePiece == 'R') {
    //     return true;//valid moves for rook
    // }
    // if(board[curRow][curCol].typePiece == 'N') {
    //     return true;//valid moves for knight
    // }
    // if(board[curRow][curCol].typePiece == 'B') {
    //     return true;//valid moves for bishop
    // }
    // if(board[curRow][curCol].typePiece == 'Q') {
    //     return true;//valid moves for queen
    // }
    // if(board[curRow][curCol].typePiece == 'K') {
    //     return true;//valid moves for king
    // }
    

    // return true;
   

    return valid_moves;
}
