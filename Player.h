#ifndef PLAYER_H
#define PLAYER_H
#include "Piece.h"

class Player
{
public:
    Player(Piece::Kind kindPlayer);
    ~Player();
    Piece::Kind getKind()const;
    int getCountPieces()const;
    void setCountPieces(int countPieces);


private:
    enum {start_pieces=2};
    const Piece::Kind kindPlayer;
    int count_pieces;
};

#endif // PLAYER_H
