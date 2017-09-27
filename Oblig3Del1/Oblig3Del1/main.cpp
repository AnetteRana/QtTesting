#include <iostream>
#include <vector>

using namespace std;

class Player
{
private:
    int level;
    string username;
    int key;
public:
    Player();
    int getKey();
};

Player::Player()
{
    level = 4;
    username = "Bob";
    key = 3;
}

int Player::getKey()
{
    return key;
}

int main()
{

Player one;
cout << one.getKey() << endl;







    return 0;
}
