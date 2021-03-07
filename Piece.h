#ifndef PIECE_H
#define PIECE_H
class Piece
{

public:
    enum Kind
    {
        W,
        B,
        O
    };
    Piece(Kind k);
    Piece();
    ~Piece();
    Kind getKind()const;
    void setKind(Kind k);
private:
    Kind kind;

};

#endif // PIECE_H
