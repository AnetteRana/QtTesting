#ifndef BINARYTREE_H
#define BINARYTREE_H


class BinaryTree
{

    char data;
    static int sAntall;
    BinaryTree* mLeft;
    BinaryTree* mRight;
    BinaryTree* mParent;
public:
    //BinaryTree(char tegn='0', Tree* mLeft=0, Tree* mRight=0, Tree* mParent=0);
    BinaryTree();
    BinaryTree* hentNesteL() const;
    BinaryTree* hentNesteR() const;
    BinaryTree* hentParent() const;
    void setNesteL();
    void setNesteR();
    void setNesteParent();

};

#endif // BINARYTREE_H
