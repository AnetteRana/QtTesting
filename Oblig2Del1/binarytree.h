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
    node* CreateLeaf(int key);
    node* ReturnNodePrivate(int key, node* ptr);


public:
    BinaryTree();

    void AddLeaf(int key);
    void PrintInOrder();
    node* ReturnNode(int key); // make private
    int ReturnRootKey();
    void PrintChildren(int key);

};

#endif // BINARYTREE_H
