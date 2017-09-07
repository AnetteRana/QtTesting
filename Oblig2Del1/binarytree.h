#ifndef BINARYTREE_H
#define BINARYTREE_H


class BinaryTree
{
    char data;
    BinaryTree* mLeft;
    BinaryTree* mRight;
    BinaryTree* mParent;
public:
    BinaryTree(char data='0', BinaryTree* mLeft=0, BinaryTree* mRight=0, BinaryTree* mParent=0);

    // set & get - NODEs pointers and data
    BinaryTree* getLeft();
    void setLeft(BinaryTree*);

    BinaryTree* getRight();
    void setRight(BinaryTree*);

    BinaryTree* getParent();
    void setParent(BinaryTree*);

    char getData();
    void setData(char);

    // void insertNode (data);


};

#endif // BINARYTREE_H
