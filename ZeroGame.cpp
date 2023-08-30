//
// Created by kmurphy on 3/13/2023.
//
#include <time.h>
#include "ZeroGame.h"
/**
 * Populates the array witht he values starting at zero
 */
ZeroGame::ZeroGame(){
    srand(time(NULL));
    for(int i=0; i<SIZE; i++){
        game_[i]=i;
    }
    Shuffle();
}
/**
 * mix up the values in the array
 */
void ZeroGame::Shuffle(){
    for(int i=0; i<SIZE; i++){
        int r = rand() % SIZE;
        Swap(game_[i], game_[r]);
    }
}
/**
 * Finds the position of the zero inside the array game_
 * @return  Zero position, -1 if it can't find the zero
 */
int ZeroGame::FindZeroPos(){
    for(int i=0; i<SIZE; i++){
        if(game_[i] == 0)
            return i;
    }
    return -1;
}
/**
 * Swap the values from a to b
 * @param a A position in the array
 * @param b A second position in the array
 */
void ZeroGame::Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void ZeroGame::Left(){
    int zero = FindZeroPos();
    if(zero > 0){
        Swap(game_[zero-1], game_[zero]);
    }
}

void ZeroGame::Switch(){
    int zero = FindZeroPos();
    if(zero > 0 && zero < SIZE-1){
        Swap(game_[zero-1], game_[zero+1]);
    }
}

void ZeroGame::Right(){
    int zero = FindZeroPos();
    if(zero < SIZE-1){
        Swap(game_[zero], game_[zero+1]);
    }
}

bool ZeroGame::InOrder(){
    for(int i; i < SIZE; i++){
        if(game_[i] != i){
            return false;
        }
    }
    return true;
}
/**
 * Display the array leaving a space where the 0 should be
 * @param out Display
 * @param g Zerogame object
 * @return ostream with the display
 */
std::ostream & operator << (std::ostream & out, const ZeroGame & g){
    for(auto i: g.game_){
        if(i==0){
            out << "[ ]";
        } else{
            out << "[" << i << "]";
        }
    }
    return out;
}