
//for creating valid moves
// bool player_is_in_check(board, player) {
//     return false;
// }

// char ** return_valid_moves(board, player) {
//     char ** valid_moves;
//     bool player_is_in_check = player_is_in_check(board, player)
//     if (player_is_in_check) {

//     } else {

//     }
//     return valid_moves
// }
// ////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"




chessPiece** create_board() {

    char* pieces;
    pieces = (char*)malloc(16*sizeof(char));
    pieces[0] = 'p';
    pieces[1] = 'p';
    pieces[2] = 'p';
    pieces[3] = 'p';
    pieces[4] = 'p';
    pieces[5] = 'p';
    pieces[6] = 'p';
    pieces[7] = 'p';
    pieces[8] = 'R';
    pieces[9] = 'N';
    pieces[10] = 'B';
    pieces[11] = 'Q';
    pieces[12] = 'K';
    pieces[13] = 'B';
    pieces[14] = 'N';
    pieces[15] = 'R';

    chessPiece magenta_pieces[16];
    chessPiece cyan_pieces[16];

    for(int i = 0; i < 16; ++i) {
        magenta_pieces[i].color = (char*)(malloc(20*sizeof(char)));
        strcpy(magenta_pieces[i].color, "\e[0;35m");
        magenta_pieces[i].typePiece = pieces[i];
        magenta_pieces[i].numberOfTimesPieceMoved = 0;
        magenta_pieces[i].numberOfTimesPieceMoved = 0;

        cyan_pieces[i].color = (char*)(malloc(20*sizeof(char)));
        strcpy(cyan_pieces[i].color, "\e[0;36m");
        cyan_pieces[i].typePiece = pieces[i];
        cyan_pieces[i].numberOfTimesPieceMoved = 0;
        cyan_pieces[i].numberOfTimesPieceMoved = 0;
    }
free(pieces);

    chessPiece** board;
    board = (chessPiece **)malloc(8*sizeof(chessPiece*));
    for(int i = 0; i < 8; ++i) {
        board[i] = (chessPiece *)malloc(8 * sizeof(chessPiece));
        for(int j = 0; j < 8; j++) {
            board[i][j].color = (char*)(malloc(20*sizeof(char)));
        }
    }

    for(int a = 0; a < 8; ++a) {

        //cyan pieces
        board[0][a] = cyan_pieces[a+8];
        board[1][a] = cyan_pieces[a];

        //blank on board
        for(int i = 2; i < 6; i++) {
            for(int j = 0; j < 8; j++) {
                strcpy(board[i][j].color, "");
                board[i][j].typePiece = ' ';
                board[i][j].numberOfTimesPieceMoved = 0;
                board[i][j].numberOfTimesPieceMoved = 0;
            }
        }

        //magenta pieces
        board[6][a] = magenta_pieces[a];
        board[7][a] = magenta_pieces[a+8];


    }
    
    return board;


    
}


void display_board(chessPiece** board, int* player) {

    if((*player) == 0) {
        for(int a = 0; a < 8; a++) {
        printf(" ");
        for(int i = 0; i < 8; i++) {
            printf("+---");
        }

        printf("+\n");

        printf("%d",8-a);

        for(int i = 0; i < 8; i++) {
            printf("| %s%c\e[0m ", board[a][i].color,board[a][i].typePiece);
        }

        printf("|\n");

    }

    printf(" ");
    for(int i = 0; i < 8; i++) { 
        printf("+---");
        }
        
        printf("+\n");

        printf("   a   b   c   d   e   f   g   h  \n");

    }
    else if((*player) == 1) {
        for(int a = 7; a >= 0; a--) {
        printf(" ");
        for(int i = 7; i >= 0; i--) {
            printf("+---");
        }

        printf("+\n");

        printf("%d",8-a);

        for(int i = 7; i >= 0; i--) {
            printf("| %s%c\e[0m ",board[a][i].color,board[a][i].typePiece);
        }

        printf("|\n");

    }

    printf(" ");
    for(int i = 7; i >= 0; i--) { 
        printf("+---");
        }
        
        printf("+\n");

        printf("   h   g   f   e   d   c   b   a  \n");

    }


}
