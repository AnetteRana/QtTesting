#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;

class Player
{
public:
    string username;
    int ID; // the key

    Player();
    friend ostream &operator<<(ostream &output, Player &obj);
};

#endif // PLAYER_H
