#include "Player.h"

Player::Player(Piece::Kind k):kindPlayer(k),count_pieces(start_pieces)
{
    //ctor
}
Piece::Kind Player::getKind()const
{
    return kindPlayer;
}
int Player::getCountPieces()const
{
    return count_pieces;
}
void Player::setCountPieces(int count_p)
{
    count_pieces=count_pieces+count_p;
}

Player::~Player()
{
    //dtor
}
