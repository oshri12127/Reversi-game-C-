#include "Piece.h"

Piece::Piece(Kind k):kind(k)
{
}
Piece::Piece():kind(O)
{
}
Piece::Kind Piece::getKind() const
{
    return kind;
}
void Piece::setKind(Kind k)
{
    this->kind=k;
}
Piece::~Piece()
{
    //dtor
}
