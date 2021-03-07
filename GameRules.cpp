#include "GameRules.h"
struct pos
{
    int x;
    int y;
};
void checkDir(int dir,pos *dir_p);
bool checkMove(Reversi* game,int i_input,int j_input)
{
    int dir=1;
    bool canF=false;
    bool wasFlip=false;
    pos dir_p;
    int countToFlip;

    for(int u=i_input-1; u<=i_input+1; u++)
    {
        for(int f=j_input-1; f<=j_input+1; f++)
        {
            countToFlip=0;
            if(u>=0&&u<8&&f>=0&&f<8)
            {
                if(game->b.getPiece(u,f)==game->opposite(game->turn))
                {
                    checkDir(dir,&dir_p);
                    canF=IsCanFlip(&dir_p,i_input,j_input,game,&countToFlip);
                    if(canF==true)
                    {
                        flip(countToFlip,&dir_p,i_input,j_input,game);
                        wasFlip=true;
                    }
                }
            }
            dir++;
        }
    }
    return wasFlip;
}
bool IsCanFlip(pos *dir_p,int i_input,int j_input,Reversi* game,int *countToFlip)
{
    i_input+=dir_p->x;
    j_input+=dir_p->y;
    while((i_input>=0&&i_input<8&&j_input>=0&&j_input<8))
    {
        if(game->b.getPiece(i_input,j_input)==game->opposite(game->turn))
        {
            *countToFlip+=1;
        }
        if(game->b.getPiece(i_input,j_input)==game->turn)
        {
            return true;
        }
        i_input+=dir_p->x;
        j_input+=dir_p->y;

    }
    return false;
}
void flip(int countToFlip,pos *dir_p,int i_input,int j_input,Reversi* game)
{
    game->b.setPiece(i_input,j_input,game->turn);
    game->WhichPlayerTurn(game->turn,1);
    for(int q=0; q<countToFlip; q++)
    {
        i_input+=dir_p->x;
        j_input+=dir_p->y;
        game->b.setPiece(i_input,j_input,game->turn);
        game->WhichPlayerTurn(game->turn,1);
        game->WhichPlayerTurn(game->opposite(game->turn),-1);
    }
}
void checkDir(int dir,pos *dir_p)
{
    if(dir==1){dir_p->x=-1;dir_p->y=-1;}
    if(dir==2){dir_p->x=-1;dir_p->y=0;}
    if(dir==3){dir_p->x=-1;dir_p->y=1;}
    if(dir==4){dir_p->x=0;dir_p->y=-1;}
    if(dir==6){dir_p->x=0;dir_p->y=1;}
    if(dir==7){dir_p->x=1;dir_p->y=-1;}
    if(dir==8){dir_p->x=1;dir_p->y=0;}
    if(dir==9){dir_p->x=1;dir_p->y=1;}
}
