#include "player.h"
#include <iostream>
#include <time.h>

using namespace std;

int hashFunction(int key)
{
    return key % 31;
}

int main()
{
    srand(time(0)); // to make random numbers

    // make blank hash table
    Player blank;
    blank.ID = 10000;
    blank.username = "____";
    Player myHashTable[31] = blank; // index 0-12
    int hashTableSize = 31;

    // create player list
    Player playerArray[15]; // fill an array with Players
    // give them names
    string names[15] = {"Luke", "Leia", "Jack", "Jill", "Joan", "Matt", "Roma", "Mimi", "Kiki", "Suzi", "Jake", "Mana", "Dina", "Tina", "Jojo"};
    for (int i = 0; i < 15; i++)
    {
        playerArray[i].username = names[i];
    }
    // give them IDs + print players
    cout << "*****     | Create players |     *****\n";
    for (int i = 0; i < 15; i++)
    {
        playerArray[i].ID = rand()%19+1; // players get IDs here
        cout << playerArray[i] << endl;
    }

    // insert to hash table
    for (int i = 0; i < 15; i++)
    {
        int index = hashFunction(playerArray[i].ID);
        for (int j = 0; j < hashTableSize ;j++)
        {
            if (myHashTable[ index ].ID == 10000)
            {
                myHashTable[ index ] = playerArray[i];
                break;
            }
            else
            {
                index++;
                index % hashTableSize;
            }
        }
    }

    // print hash table
    cout << "*****     | Hash table |     *****\n";
    for (int i = 0; i < hashTableSize; i++)
    {
        cout << myHashTable[i] << endl;
    }

    // random ints


    return 0;
}
