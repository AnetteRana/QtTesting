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
    if (obj.ID == 10000)
    output << "----------------------------\n";
    else
    output << "Username: " << obj.username << "   |   ID: " << obj.ID << endl;
    return output;
}
