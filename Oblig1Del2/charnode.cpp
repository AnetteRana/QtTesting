#include "charnode.h"


int CharNode::sAmount;

CharNode::CharNode(char inChar, CharNode* inNext):mChar{inChar}, mNext{inNext}
{
    sAmount++;
}

CharNode::~CharNode()
{
    sAmount--;
}

void CharNode::printChar()
{
    std::cout << mChar;
}

// getters
CharNode* CharNode::getNext(){return mNext;}
int CharNode::getAmount(){return sAmount;}
char CharNode::getChar() {return mChar;}

void CharNode::setNext(CharNode* in)
{
    mNext = in;
}

// sette ny node bakerst
void CharNode::newNodeInBack(CharNode* list, char nodeData)
{
    CharNode* newNode = new CharNode(nodeData, 0);
    CharNode* forrige;

    for (CharNode* p = list; p; p=p->getNext())
    {
        forrige = p;
    }
    forrige->setNext(newNode);
}

// function to delete a linked list
void CharNode::deleteList (CharNode* listToDelete)
{
    CharNode* temp = listToDelete;
    while (listToDelete)
    {
        temp = listToDelete;
        delete temp;
    }
}
