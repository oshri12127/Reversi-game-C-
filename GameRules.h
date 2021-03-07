#ifndef GAMERULES_H
#define GAMERULES_H
#include "Reversi.h"
bool checkMove(Reversi* game,int i,int j);
void flip(int countToFlip,pos *dir_p,int i_input,int j_input,Reversi* game);
bool IsCanFlip(pos *dir_p,int i_input,int j_input,Reversi* game,int *countToFlip);

#endif // GAMERULES_H
