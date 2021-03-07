#include "Reversi.h"


Reversi::Reversi():b(),PW(Piece::W),PB(Piece::B),quit(false),turn(Piece::B),inputOk(true)
{

    //ctor
}
void Reversi::start_game()//START
{
    b.printBoard();

    do
    {
        cout<<b.KindToString(turn)<<":"<<endl;
        input();
        if(quit==false)
            b.printBoard();
    }
    while(finish()==0);
    winner();
}
int Reversi::finish()
{
    if(IsbFull()==true)
        return -1;
    if(quit==true)
        return -1;

    return 0;
}
void Reversi::winner()//PRINT THE WINNER
{
    if(quit==true)
    {
        cout<<b.KindToString(turn)<<": QUIT"<<endl;
        nextTurn();
        cout<<b.KindToString(turn)<<" wins the game."<<endl;
        return;
    }

    if(PW.getCountPieces()>PB.getCountPieces())
    {
        cout<<"W wins the game."<<endl;
        return;
    }

    if(PW.getCountPieces()<PB.getCountPieces())
    {
        cout<<"B wins the game."<<endl;
        return;
    }
    cout<<"The game ends in a tie."<<endl;
}
bool Reversi::IsbFull()//IF BOARD IS FULL
{
    if(PW.getCountPieces()+PB.getCountPieces()==64)
        return true;
    return false;
}
void Reversi::nextTurn()
{
    if (turn == Piece::W)
    {
        turn = Piece::B;
        return;
    }
    turn=Piece::W;
}
bool Reversi::IsEmptyPlace(int i,int j)//CHECK IS PLACE EMPTY
{
    if(b.getPiece(i-1,j-1)==Piece::O)
        return true;
    return false;
}
void Reversi::input()//CHECK INPUT
{
    do
    {
        inputOk=true;
        string input = "";
        getline(cin, input);
        if(input=="QUIT")
        {
            quit=true;
            break;
        }
        if(input=="PASS")
        {
            cout<<b.KindToString(turn)<<": PASS"<<endl;
            break;
        }
        if(input.length()!=2)
            inputOk=false;
        if(inputOk)
            if((!(isdigit(input[1])))||(!(isupper(input[0]))))
                inputOk=false;
        if(inputOk)
            if(b.IsInBoard(input[1]-48,input[0]-64)==false)//"-64" to change from ASCI to num;
                inputOk=false;
        if(inputOk)
            if(IsEmptyPlace(input[1]-48,input[0]-64)==false)//"-48,-64" to change from ASCI to num;
                inputOk=false;
        if(inputOk)
            if(checkMove(this,(input[1]-48)-1,(input[0]-64)-1)==false)
                inputOk=false;
        if(inputOk==false)
            cerr<<"Invalid move; the game awaits a valid move."<<endl;
    }
    while(inputOk==false);
    if(quit==false)
        nextTurn();
}
Piece::Kind Reversi::opposite(Piece::Kind p)
{
    if (p == Piece::W)
    {
        return Piece::B;
    }
    return Piece::W;

}
void Reversi::WhichPlayerTurn(Piece::Kind t,int set_p)//SET THE COUNT PIECES
{
    if (t == Piece::W)
    {
        PW.setCountPieces(set_p);
    }
    PB.setCountPieces(set_p);
}
Reversi::~Reversi()
{
    //dtor
}

