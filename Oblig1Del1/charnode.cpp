#include "charnode.h"


int CharNode::sAntall;

CharNode::CharNode(char tegn, CharNode* neste):mTegn{tegn}, mNeste{neste}
{
   sAntall++;
}

CharNode::~CharNode()
{
    sAntall--;
}

void CharNode::Skriv()
{
    std::cout << mTegn << std::endl;
}

CharNode* CharNode::HentNeste()
{
    return mNeste;
}

int CharNode::HentAntall()
{
    return sAntall;
}
