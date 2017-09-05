#include "binarytree.h"

BinaryTree::BinaryTree(char idata, BinaryTree* imLeft, BinaryTree* imRight, BinaryTree* imParent):data{idata}, mLeft{imLeft}, mRight{imRight}, mParent{imParent}
{

}

BinaryTree* BinaryTree::getLeft(){    return mLeft;}
BinaryTree* BinaryTree::getRight(){    return mRight;}
BinaryTree* BinaryTree::getParent(){    return mParent;}
char BinaryTree::getData(){    return data;}

void BinaryTree::setData(char in)
{
    data = in;
}

void BinaryTree::setLeft(BinaryTree* in)
{
    mLeft = in;
}

void BinaryTree::setRight(BinaryTree* in)
{
    mRight = in;
}

void BinaryTree::setParent(BinaryTree* in)
{
    mParent = in;
}
