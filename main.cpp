#include <iostream>
#include "ZeroGame.h"
using namespace std;

int GetChoice();
enum choices {LEFT = 1, RIGHT, SWITCH, FORFEIT};
int main() {
    cout << "Zero Game!" << endl;
    ZeroGame zg;
    int choice;
    int times = 0;

    do{
        cout << zg << endl;
        choice = GetChoice();
        if(choice == LEFT){
            zg.Left();
        } else if (choice == RIGHT){
            zg.Right();
        } else if (choice == SWITCH){
            zg.Switch();
        } else{
            break;
        }
        times++;
    }while(!zg.InOrder());

    if(zg.InOrder()){
        cout << zg << endl;
        cout << "You Win!!\nThat took "<< times << " times" << endl;
    } else{
        cout << "Thanks for playing try another time!" << endl;
    }

    return 0;
}

int GetChoice(){
    int choice;
    cout << "1. Move Left\n2. Move Right\n3. Switch\n4. Forfeit\nChoose one: ";
    cin >> choice;
    return choice;
}