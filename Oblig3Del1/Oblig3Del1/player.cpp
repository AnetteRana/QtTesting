#include "player.h"
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

Player::Player()
{

}

ostream &operator<<(ostream &output, Player &obj)
{
    output << "Username: " << obj.username << "   |   ID: " << obj.ID << endl;
    return output;
}
