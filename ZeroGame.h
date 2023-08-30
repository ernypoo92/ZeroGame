//
// Created by kmurphy on 3/13/2023.
//

#ifndef ZEROGAME_H
#define ZEROGAME_H
#include <iostream>

class ZeroGame {
public:
    static const int SIZE = 4;
    ZeroGame();
    void Shuffle();
    int FindZeroPos();
    void Swap(int &a, int &b);
    void Right();
    void Left();
    void Switch();
    bool InOrder();
    friend std::ostream & operator << (std::ostream &, const ZeroGame &);
private:
    int game_[SIZE];

};


#endif //ZEROGAME_H
