
#include "Reversi.h"
int main()
{
    Reversi *game=new Reversi;
    game->start_game();
    delete game;
    return 0;
}
