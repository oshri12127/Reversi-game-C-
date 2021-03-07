#include "Board.h"

Board::Board()
{
    board[3][4].setKind(Piece::B);
    board[4][3].setKind(Piece::B);
    board[3][3].setKind(Piece::W);
    board[4][4].setKind(Piece::W);

}
void Board::setPiece(int row,int column,Piece::Kind c)
{
    board[row][column].setKind(c);
}

Piece::Kind Board::getPiece(int row,int column)
{
    return board[row][column].getKind();
}

void Board::printBoard()
{
    for(int i=0; i<Rows; i++)
    {
        for(int j=0; j<Columns; j++)
        {
            if(j==0)
                cout<<KindToString(board[i][j].getKind());
            else
                cout<<" "<<KindToString(board[i][j].getKind());

        }
        cout<<endl;
    }
}

Board::~Board()
{
    //dtor
}
string Board::KindToString(Piece::Kind c)//STRING THE KIND
{
    if (Piece::W == c)
        return "W";
    if (Piece::B == c)
        return "B";
    return "O";
}
bool Board::IsInBoard(int i,int j)
{
    if(i-1>=0&&i-1<Rows&&j-1>=0&&j-1<Columns)
        return true;
    return false;
}
