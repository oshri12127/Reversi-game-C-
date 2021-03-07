#ifndef BOARD_H
#define BOARD_H
#include<iostream>
#include "Piece.h"
using namespace std;
class Board
{
public:
    Board();
    ~Board();
    void setPiece(int row,int column,Piece::Kind c);
    Piece::Kind getPiece(int row,int column);
    void printBoard();
    string KindToString(Piece::Kind c);
    bool IsInBoard(int i,int j);

private:
    enum {Rows = 8};
    enum {Columns = 8};
    Piece board[Rows][Columns];

};

#endif // BOARD_H
