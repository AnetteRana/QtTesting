#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

class BinaryTree
{
private:

    struct node
    {
        int key;
        node* left;
        node* right;
    };

    node* root;
    void AddLeafPrivate(int key, node* ptr);
    void PrintInOrderPrivate(node* ptr);

public:
    BinaryTree();

    node* CreateLeaf(int key);
    void AddLeaf(int key);
    void PrintInOrder();


};

#endif // BINARYTREE_H
