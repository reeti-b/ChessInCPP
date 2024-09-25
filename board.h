#ifndef BOARD_H
#define BOARD_H 

typedef struct chessPiece_struct {
   char* color;
   char typePiece;
   int numberOfTimesPieceMoved;
} chessPiece;

chessPiece** create_board();
void display_board(chessPiece** board,int* player);


#endif