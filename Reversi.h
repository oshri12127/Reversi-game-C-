#ifndef REVERSI_H
#define REVERSI_H
#include "Player.h"
#include "Board.h"
#include <string>
class Reversi
{
public:
    Reversi();
    ~Reversi();
    void start_game();

private:
    Board b;
    Player PW,PB;
    bool quit;
    Piece::Kind turn;
    bool inputOk;

    int finish();
    void winner();
    bool IsbFull();
    void nextTurn();
    void input();
    bool IsEmptyPlace(int i,int j);
    Piece::Kind opposite(Piece::Kind p);
    void WhichPlayerTurn(Piece::Kind t,int set_p);

    friend bool checkMove(Reversi* game,int i,int j);
    friend void flip(int countToFlip,struct pos *dir_p,int i_input,int j_input,Reversi* game);
    friend bool IsCanFlip(struct pos *dir_p,int i_input,int j_input,Reversi* game,int *countToFlip);
};

#endif // REVERSI_H
