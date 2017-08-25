#ifndef CHARNODE_H
#define CHARNODE_H

#include <iostream>



class CharNode
{
    char mTegn;
    CharNode* mNeste;
    static int sAntall;
public:
    CharNode (char tegn, CharNode* neste);
    ~CharNode ();
    void Skriv();
    CharNode* HentNeste();
    int HentAntall();

};

#endif // CHARNODE_H


