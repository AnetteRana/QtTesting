#include <iostream>
#include <fstream> // read / write to file
#include "charnode.h"

using namespace std;


int main()
{
    // read from file
    string line;
    ifstream myfile ("myFile.txt");
    while ( getline (myfile,line) )
    {
        cout << line << '\n';
    }
    myfile.close();




    // make a list
    CharNode* liste = new CharNode ('a', 0);
    liste = new CharNode ('b', liste);
    liste = new CharNode ('c', liste);
    liste = new CharNode ('d', liste);


    // go through list and print
    CharNode* current = liste;

    while (current != nullptr)
    {
        current->Skriv();
        current = current->HentNeste();
    }


    return 0;
}
