#ifndef CHARNODE_H
#define CHARNODE_H

#include <iostream>


class CharNode
{
private:
    char mChar;
    CharNode* mNext;
    static int sAmount;
public:
    CharNode(char inChar, CharNode* inNext);
    ~CharNode();
    void printChar();
    CharNode* getNext();
    int getAmount();
    char getChar();
    void setNext(CharNode*);
    void newNodeInBack(CharNode*, char);
    void deleteList (CharNode* listToDelete);
};


#endif // CHARNODE_H
