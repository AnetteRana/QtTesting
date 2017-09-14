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
    node* CreateLeaf(int key);
    node* ReturnNode(int key);
    node* ReturnNodePrivate(int key, node* ptr);
    int CountNodesInTreePrivate(int numberOut, node* ptr);
    int CountLevelsPrivate(node* ptr, int counter, int& highest);
    void PrintPreOrderPrivate(node* ptr);
    void PrintInOrderPrivate(node* ptr);
    void PrintPostOrderPrivate(node* ptr);
    int FindSmallestPrivate(node* ptr);
    void RemoveNodePrivate(int key, node* parent);
    void RemoveRootMatch();
    void RemoveMatch(node* parent, node* match, bool left);

public:
    BinaryTree();
    void AddLeaf(int key);
    int ReturnRootKey();
    void PrintChildren(int key);
    int CountNodesInTreePublic(int numberOut);
    int CountLevelsPublic();
    void PrintPreOrder();
    void PrintInOrder();
    void PrintPostOrder();
    int FindSmallest();
    void RemoveNode(int key);


};

#endif // BINARYTREE_H
