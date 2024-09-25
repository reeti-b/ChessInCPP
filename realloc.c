#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct chessPiece_struct {
   char* color;
   char typePiece;
} chessPiece;


typedef struct move_struct {
   int cRow;
   int eRow;
   int c_col;
   int e_col;
   chessPiece piece_at_end_index;
} move;

chessPiece** create_board() {

    chessPiece** board;
    board = (chessPiece **)malloc(2*sizeof(chessPiece*));

    for(int i = 0; i < 2; ++i) {
        board[i] = (chessPiece *)malloc(2 * sizeof(chessPiece));
        for(int j = 0; j < 2; j++) {
            board[i][j].color = (char*)(malloc(20*sizeof(char)));
        }
    }

    board[0][0].typePiece = 'A';
    strcpy(board[0][0].color,"\e[0;31m"); //red

    board[0][1].typePiece = 'B';
    strcpy(board[0][1].color, "\e[0;32m"); //green

    board[1][0].typePiece = 'C';
    strcpy(board[1][0].color, "\e[0;33m"); //yellow

    board[1][1].typePiece = 'D';
    strcpy(board[1][1].color, "\e[0;34m"); //blue 
    
    return board;

}



void display_board(chessPiece** board) {

    for(int a = 0; a < 2; a++) {
        printf(" ");
        for(int i = 0; i < 2; i++) {
            printf("+---");
        }

        printf("+\n");

        printf("%d",2-a);

        for(int i = 0; i < 2; i++) {
            printf("| %s%c\e[0m ",board[a][i].color,board[a][i].typePiece);
        }

        printf("|\n");

    }

    printf(" ");
    for(int i = 0; i < 2; i++) { 
        printf("+---");
        }
        
        printf("+\n");

        printf("   a   b  \n");
}




void make_move(chessPiece** board, move* log_moves, int numberMoves, int cur_row, int cur_col, int end_row, int end_col) {


    log_moves[numberMoves].cRow = cur_row;   //just logging this move, from piece at box 1 to box 2, not changing any values, just logging
    log_moves[numberMoves].c_col = cur_col;
    log_moves[numberMoves].eRow = end_row;
    log_moves[numberMoves].e_col = end_col;
    log_moves[numberMoves].piece_at_end_index.typePiece = board[end_row][end_col].typePiece; //1 of 2 attributes
    log_moves[numberMoves].piece_at_end_index.color = (char*)malloc(20*sizeof(char)); //make space for color string
    strcpy(log_moves[numberMoves].piece_at_end_index.color,board[end_row][end_col].color); //copying the color of the end index to log_moves

    //all of this catalogues the first move

    board[end_row][end_col].typePiece = board[cur_row][cur_col].typePiece; //piece has moved from current location to new one
    board[cur_row][cur_col].typePiece = ' '; //because the piece has moved from there

    strcpy(board[end_row][end_col].color,board[cur_row][cur_col].color); //color would also be same as before, cuz whole piece has moved
    strcpy(board[cur_row][cur_col].color,""); //of course the color at original place would be nothing, just space




   // log_moves[numberMoves].cRow = 3;
   // printf("%d\n",log_moves[numberMoves].cRow);

   // log_moves[numberMoves].eRow = 4;
   // printf("%d\n",log_moves[numberMoves].eRow);

   // log_moves[numberMoves].c_col = 5;
   // printf("%d\n",log_moves[numberMoves].c_col);

   // log_moves[numberMoves].e_col = 6;
   // printf("%d\n",log_moves[numberMoves].e_col);

   // log_moves[numberMoves].piece_at_end_index.typePiece = 'K';
   // printf("%c\n",log_moves[numberMoves].piece_at_end_index.typePiece);

   // log_moves[numberMoves].piece_at_end_index.color = (char*)malloc(20*sizeof(char));
   // strcpy(log_moves[numberMoves].piece_at_end_index.color, "\e[0;35m");
    

}

void undo(chessPiece** board, int numberMoves, move* log_moves) {

    printf("%d\n",log_moves[numberMoves].eRow); //just printing the end row
    printf("%c\n",board[log_moves[numberMoves].eRow][log_moves[numberMoves].e_col].typePiece); //just printing the piece at the end row,column
    printf("%sThis text should be in red\e[0m\n",board[log_moves[numberMoves].eRow][log_moves[numberMoves].e_col].color); //just printing the color of the piece at end row,column
    printf(":%c:\n",board[log_moves[numberMoves].cRow][log_moves[numberMoves].c_col].typePiece); //there should be nothing inside the colons
    printf(":%s:\n",board[log_moves[numberMoves].cRow][log_moves[numberMoves].c_col].color); //there should no spaces between the colons


    //let's assign then!

    board[log_moves[numberMoves].cRow][log_moves[numberMoves].c_col].typePiece = board[log_moves[numberMoves].eRow][log_moves[numberMoves].e_col].typePiece;
    strcpy(board[log_moves[numberMoves].cRow][log_moves[numberMoves].c_col].color,board[log_moves[numberMoves].eRow][log_moves[numberMoves].e_col].color);

    board[log_moves[numberMoves].eRow][log_moves[numberMoves].e_col].typePiece = log_moves[numberMoves].piece_at_end_index.typePiece;
    strcpy(board[log_moves[numberMoves].eRow][log_moves[numberMoves].e_col].color, log_moves[numberMoves].piece_at_end_index.color);

}



int main() {
    
   // move* log_moves = (move*)malloc(sizeof(move));
    int numberMoves = 0;

   move* log_moves = (move*)malloc(sizeof(move));
   chessPiece** board = create_board();

    display_board(board);

    make_move(board,log_moves,numberMoves,0,0,1,1);

    display_board(board);

    undo(board, numberMoves, log_moves);

    display_board(board);

    make_move(board,log_moves,numberMoves,0,1,1,0);

    display_board(board);

    undo(board, numberMoves, log_moves);

    display_board(board);

    make_move(board,log_moves,numberMoves,0,0,1,0);

    display_board(board);

    undo(board, numberMoves, log_moves);

    display_board(board);



printf("\n\n");



return 0;

}
