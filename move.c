#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "board.h"
#include "move.h"
#include "validMoves.h"

void undo_command(chessPiece** board, move* log_moves, int* numberMoves, int* player) {


    int a = *numberMoves;

     //fix has moved once, or twice

    board[log_moves[a-1].cRow][log_moves[a-1].c_col].typePiece = board[log_moves[a-1].eRow][log_moves[a-1].e_col].typePiece;
    strcpy(board[log_moves[a-1].cRow][log_moves[a-1].c_col].color,board[log_moves[a-1].eRow][log_moves[a-1].e_col].color);

    board[log_moves[a-1].eRow][log_moves[a-1].e_col].typePiece = log_moves[a-1].piece_at_end_index.typePiece;
    strcpy(board[log_moves[a-1].eRow][log_moves[a-1].e_col].color, log_moves[a-1].piece_at_end_index.color);

    if(((*player) == 0) && (log_moves[a-1].passant == true)   ){
        board[4][log_moves[a-1].e_col].typePiece = 'p';
        strcpy(board[4][log_moves[a-1].e_col].color,"\e[0;35m");
    }
    if(((*player) == 1) && (log_moves[a-1].passant == true) ){
        board[3][log_moves[a-1].e_col].typePiece = 'p';
        strcpy(board[3][log_moves[a-1].e_col].color,"\e[0;36m");
    }


    move* new_log_moves = (move*)malloc((sizeof(log_moves)-1)*sizeof(move));

    for(int i = 0; i <(sizeof(log_moves))-1;++i) {
        new_log_moves[i] = log_moves[i];
    }

    log_moves = new_log_moves;

    (*numberMoves)--;


    
    /*

    for every user command (e.g. e2 to e4) {
        it saves what was at e4 (if blank, then good)
        moves piece from e2 to e4

        so now, if you say undo, then moves the piece at recent move(e4) back to move_before_that(e2)
        and it puts piece at e4(blank/whatever piece was there) back at e4.
    }
    
    
    
    
    */
}


void curr_player_takes_turn(chessPiece** board, int* player, move* log_moves, int* numberMoves) {

    char* player_color;

    if (((*player) % 2) == 0) {
        player_color = "Magenta";
    }

    if(((*player) % 2) == 1) {
        player_color = "Cyan";
    }

     move* valid_moves = (move*)malloc(300*sizeof(move));

        int valid_move_count = 0;

         

        char a_valid_move[4];
    valid_moves = list_valid_moves(board,player,valid_moves, &valid_move_count,log_moves, numberMoves);
    printf("Valid Moves: \n");
    for(int b = 0; b < valid_move_count;b++){
        int cr = 8-valid_moves[b].cRow;
        int er = 8-valid_moves[b].eRow;
        char cc = 'a'+valid_moves[b].c_col;
        char ec = 'a'+ valid_moves[b].e_col;
      //  char a_valid_move[8];
        a_valid_move[0] = cc;
        a_valid_move[1] = cr + '0';
        a_valid_move[2] = ec;
        a_valid_move[3] = er + '0';
        printf("%s\n", a_valid_move);
       // printf("%c%d%c%d\n",cc,cr,ec,er);
    }
        

// free(valid_moves);

    printf("%s's turn. Enter your move.\n",player_color);



    char inputS[5];
  
    scanf("%s",inputS);
   

    int cur_col = 0;
    int cur_row = 0;
    int end_col = 0;
    int end_row = 0;

    if (inputS[0] == 'u') {
        undo_command(board, log_moves, numberMoves, player);
    }
    if (inputS[0] != 'u') {

        cur_col = inputS[0] - 'a';
        cur_row = 8-(inputS[1]-'0');
        end_col = inputS[2] - 'a';
        end_row = 8-(inputS[3] - '0');


        
        if(isValidMove(valid_moves,valid_move_count,cur_row,end_row,cur_col,end_col, board, log_moves, numberMoves, player)) {
            printf("This is a VALID move.\n");
            log_moves[*numberMoves].cRow = cur_row;   //just logging this move, from piece at box 1 to box 2, not changing any values, just logging
            log_moves[*numberMoves].c_col = cur_col;
            log_moves[*numberMoves].eRow = end_row;
            log_moves[*numberMoves].e_col = end_col;
            log_moves[*numberMoves].piece_at_end_index.typePiece = board[end_row][end_col].typePiece; //1 of 2 attributes
            log_moves[*numberMoves].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); //make space for color string
            strcpy(log_moves[*numberMoves].piece_at_end_index.color,board[end_row][end_col].color); //copying the color of the end index to log_moves
             board[end_row][end_col].typePiece = board[cur_row][cur_col].typePiece; //piece has moved from current location to new one

            (board[cur_row][cur_col].numberOfTimesPieceMoved)++;
            board[cur_row][cur_col].typePiece = ' '; //because the piece has moved from there

            strcpy(board[end_row][end_col].color,board[cur_row][cur_col].color); //color would also be same as before, cuz whole piece has moved
            strcpy(board[cur_row][cur_col].color,""); //of course the color at original place would be nothing, just space
            (board[end_row][end_col].numberOfTimesPieceMoved)++;

            //if en passant

            if( (log_moves[*numberMoves].passant == true) && ((*player) == 0)) {

                printf("Hey! Looks like Magenta played en passant.\n");
                
                board[3][end_col].typePiece = ' ';
                strcpy(board[3][end_col].color,"");
               // (*is_en_passant) = false;
            }
            if( (log_moves[*numberMoves].passant == true) && ((*player) == 1)) {
                printf("Hey! Looks like Cyan played en passant.\n");
                board[4][end_col].typePiece = ' ';
                strcpy(board[4][end_col].color,"");
               // (*is_en_passant) = false;
            }


            (*numberMoves)++;

        }
        else {
            printf("This is NOT a VALID move. Try again.\n");
            switch_player(player);
        }
        

//         move* valid_moves = (move*)malloc(300*sizeof(move));

//         int valid_move_count = 0;
    
  
//     valid_moves = is_valid_move(board,player,valid_moves, &valid_move_count);
//     printf("Valid Moves: \n");
//     for(int b = 0; b < valid_move_count;b++){
//         int cr = 8-valid_moves[b].cRow;
//         int er = 8-valid_moves[b].eRow;
//         char cc = 'a'+valid_moves[b].c_col;
//         char ec = 'a'+ valid_moves[b].e_col;
//         char a_valid_move[6];
//         a_valid_move[0] = cc;
//         a_valid_move[1] = cr + '0';
//         a_valid_move[2] = ec;
//         a_valid_move[3] = er + '0';
//         printf("%s\n",a_valid_move);
//        // printf("%c%d%c%d\n",cc,cr,ec,er);
//     }
//         printf("It is a valid move. Proceed.\n");
//         //all of this catalogues the  move

// free(valid_moves);


   



    // log_moves[*numberMoves].cRow = cur_row;   //just logging this move, from piece at box 1 to box 2, not changing any values, just logging
    // log_moves[*numberMoves].c_col = cur_col;
    // log_moves[*numberMoves].eRow = end_row;
    // log_moves[*numberMoves].e_col = end_col;
    // log_moves[*numberMoves].piece_at_end_index.typePiece = board[end_row][end_col].typePiece; //1 of 2 attributes
    // log_moves[*numberMoves].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); //make space for color string
    // strcpy(log_moves[*numberMoves].piece_at_end_index.color,board[end_row][end_col].color); //copying the color of the end index to log_moves

    
    
        
    



/*
//all of this catalogues the  move

    log_moves[*numberMoves].cRow = cur_row;   //just logging this move, from piece at box 1 to box 2, not changing any values, just logging
    log_moves[*numberMoves].c_col = cur_col;
    log_moves[*numberMoves].eRow = end_row;
    log_moves[*numberMoves].e_col = end_col;
    log_moves[*numberMoves].piece_at_end_index.typePiece = board[end_row][end_col].typePiece; //1 of 2 attributes
    log_moves[*numberMoves].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); //make space for color string
    strcpy(log_moves[*numberMoves].piece_at_end_index.color,board[end_row][end_col].color); //copying the color of the end index to log_moves


*/

    // board[end_row][end_col].typePiece = board[cur_row][cur_col].typePiece; //piece has moved from current location to new one
    // board[cur_row][cur_col].typePiece = ' '; //because the piece has moved from there

    // strcpy(board[end_row][end_col].color,board[cur_row][cur_col].color); //color would also be same as before, cuz whole piece has moved
    // strcpy(board[cur_row][cur_col].color,""); //of course the color at original place would be nothing, just space

    // (*numberMoves)++;
}

free(valid_moves);

       
}



void switch_player(int* player) {
    if(((*player)%2) == 0) {
        (*player) = 1;
    }
    else {
        (*player) = 0;
    }
}
