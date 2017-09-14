#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <cstdlib>
using namespace std;


template <class T>
class BinaryTree
{
private:

    struct node
    {
        T key;
        node* left;
        node* right;
    };


    node* root;

    void AddLeafPrivate(T key, node* ptr);
    node* CreateLeaf(T key);
    node* ReturnNode(T key);
    node* ReturnNodePrivate(T key, node* ptr);
    T CountNodesInTreePrivate(T numberOut, node* ptr);
    T CountLevelsPrivate(node* ptr, T counter, T& highest);
    void PrintPreOrderPrivate(node* ptr);
    void PrintInOrderPrivate(node* ptr);
    void PrintPostOrderPrivate(node* ptr);
    T FindSmallestPrivate(node* ptr);
    void RemoveNodePrivate(T key, node* parent);
    void RemoveRootMatch();
    void RemoveMatch(node* parent, node* match, bool left);
    void RemoveSubtree(node* ptr);

public:
    BinaryTree();
    ~BinaryTree();
    void AddLeaf(T key);
    T ReturnRootKey();
    void PrintChildren(T key);
    T CountNodesInTreePublic(T numberOut);
    T CountLevelsPublic();
    void PrintPreOrder();
    void PrintInOrder();
    void PrintPostOrder();
    T FindSmallest();
    void RemoveNode(T key);


};



template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}
template <class T>
BinaryTree<T>::~BinaryTree()
{
    if (root)
    RemoveSubtree(root);
}
template <class T>
class BinaryTree<T>::node* BinaryTree<T>::CreateLeaf(T key)
{
    node* ny = new node;
    ny->key = key;
    ny->left = NULL;
    ny->right = NULL;

    return ny;
}
template <class T>
void BinaryTree<T>::AddLeaf(T key)
{
    AddLeafPrivate(key, root);
}
template <class T>
void BinaryTree<T>::AddLeafPrivate(T key, node* ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(key);
    }
    else if (key < ptr->key)
    {
        if (ptr->left != NULL)
        {
            AddLeafPrivate(key, ptr->left);
        }
        else
        {
            ptr->left = CreateLeaf(key);
        }
    }
    else // (key >= ptr->key)
    {
        if (ptr->right != NULL)
        {
            AddLeafPrivate(key, ptr->right);
        }
        else
        {
            ptr->right = CreateLeaf(key);
        }
    }
}
template <class T>
class BinaryTree<T>::node* BinaryTree<T>::ReturnNode(T key)
{
    return ReturnNodePrivate(key, root);
}
template <class T>
class BinaryTree<T>::node* BinaryTree<T>::ReturnNodePrivate(T key, node* ptr)
{

    if (ptr)
    {
        if (ptr->key == key)
        {
            return ptr;
        }
        else if (ptr->key > key)
        {
            return ReturnNodePrivate(key, ptr->left);
        }
        else
        {
            return ReturnNodePrivate(key, ptr->right);
        }
    }
    else
    {
        return NULL;
    }

}
template <class T>
T BinaryTree<T>::ReturnRootKey()
{
    if (root != NULL)
    {
        return root->key;
    }
    else
    {
        cout << "Root empty\n";
        return 0;
    }
}
template <class T>
void BinaryTree<T>::PrintChildren(T key)
{
    node* ptr = ReturnNode(key);
    if (ptr)
    {
        cout << "Parent = " << key << endl;
        if (ptr->left)
        {
            cout << "Left child = " << ptr->left->key << endl;
        }
        else
        {
            cout << "Left child = NULL\n";
        }
        if (ptr->right)
        {
            cout << "Right child = " << ptr->right->key << endl;
        }
        else
        {
            cout << "Right child = NULL\n";
        }
    }
    else
    {
        cout << "No children\n";
    }

}
template <class T>
T BinaryTree<T>::CountNodesInTreePrivate(T numberOut, node* ptr)
{
    if (ptr)
    {
        numberOut++;
        if (ptr->left)
        {
            numberOut=CountNodesInTreePrivate(numberOut, ptr->left);
        }
        if (ptr->right)
        {
            numberOut=CountNodesInTreePrivate(numberOut, ptr->right);
        }
    }
    return numberOut;
}
template <class T>
T BinaryTree<T>::CountNodesInTreePublic(T numberOut)
{
    return CountNodesInTreePrivate(numberOut, root);
}
template <class T>
T BinaryTree<T>::CountLevelsPublic()
{
    int levels = 0;
    CountLevelsPrivate(root, 0, levels);
    return levels;
}
template <class T>
T BinaryTree<T>::CountLevelsPrivate(node* ptr, T counter, T& highest)
{
    if (ptr)
    {
        counter++;
        if (ptr->left)
        {
            counter=CountLevelsPrivate(ptr->left, counter, highest);
        }
        if (ptr->right)
        {
            counter=CountLevelsPrivate(ptr->right, counter, highest);
        }
        if ((!ptr->left)&&(!ptr->right))
        {
            if (counter > highest)
            {
                highest = counter;
            }
            counter--;
            return counter;
        }
    }
    counter--;
    return counter;
}
template <class T>
void BinaryTree<T>::PrintPreOrder()
{
    if (root)
    {
        cout << "\nPrinting tree using pre-order traversal: ";
        PrintPreOrderPrivate(root);
    }
    else
    {
        cout << "The tree is empty.\n";
    }
}
template <class T>
void BinaryTree<T>::PrintPreOrderPrivate(node* ptr)
{
    cout << ptr->key << " ";
    if (ptr->left)
    {
        PrintPreOrderPrivate(ptr->left);
    }
    if (ptr->right)
    {
        PrintPreOrderPrivate(ptr->right);
    }
}
template <class T>
void BinaryTree<T>::PrintInOrder()
{
    cout << "\nPrinting tree using in-order traversal: ";
    PrintInOrderPrivate(root);
}
template <class T>
void BinaryTree<T>::PrintInOrderPrivate(node* ptr)
{
    if (root)
    {

        if (ptr->left)
        {
            PrintInOrderPrivate(ptr->left);
        }
        cout << ptr->key << " ";
        if (ptr->right)
        {
            PrintInOrderPrivate(ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty.\n";
    }
}
template <class T>
void BinaryTree<T>::PrintPostOrder()
{
    if (root)
    {
        cout << "\nPrinting tree using post-order traversal: ";
        PrintPostOrderPrivate(root);
    }
    else
    {
        cout << "The tree is empty.\n";
    }
}
template <class T>
void BinaryTree<T>::PrintPostOrderPrivate(node* ptr)
{
    if (ptr->left)
    {
        PrintPostOrderPrivate(ptr->left);
    }
    if (ptr->right)
    {
        PrintPostOrderPrivate(ptr->right);
    }
    cout << ptr->key << " ";
}
template <class T>
T BinaryTree<T>::BinaryTree<T>::FindSmallest()
{
    if (root)
    {
        return FindSmallestPrivate(root);
    }
    else
    {
        cout << "Error, no root.\n";
        return 0;
    }
}
template <class T>
T BinaryTree<T>::BinaryTree<T>::FindSmallestPrivate(node* ptr)
{
    if (ptr->left)
    {
        return FindSmallestPrivate(ptr->left);
    }
    else
    {
        return ptr->key;
    }
}
template <class T>
void BinaryTree<T>::RemoveNode(T key)
{
    if (root)
    {
        if (root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            RemoveNodePrivate(key, root);
        }
    }
}
template <class T>
void BinaryTree<T>::RemoveNodePrivate(T key, node* parent)
{
    if (key < parent->key && parent->left)
    {
        parent->left->key == key ?
                    RemoveMatch(parent, parent->left, true) :
                    RemoveNodePrivate(key, parent->left);
    }
    else if (key > parent->key && parent->right)
    {
        parent->right->key == key ?
                    RemoveMatch(parent, parent->right, false) :
                    RemoveNodePrivate(key, parent->right);
    }
    else
    {
        cout << "Key not found\n";
    }
}
template <class T>
void BinaryTree<T>::RemoveRootMatch()
{
    node* delPtr = root;
    T smallestInRightSubtree;

    // no children
    if (!root->left && !root->right)
    {
        root = nullptr;
    }
    // 1 child
    else if (!root->left && root->right)
    {
        root = root->right;
        delPtr->right = nullptr;
        delete delPtr;
    }
    else if (root->left && !root->right)
    {
        root = root->left;
        delPtr->left = nullptr;
        delete delPtr;
    }
    // 2 children
    else
    {
        smallestInRightSubtree = FindSmallestPrivate(root->right);
        RemoveNodePrivate(smallestInRightSubtree, root);
        root->key = smallestInRightSubtree;

    }
    cout << "Something should be removed\n";
}
template <class T>
void BinaryTree<T>::RemoveMatch(node* parent, node* match, bool left)
{
    cout << "Lets remove node\n";
    node* delPtr = match;
    T smallestInRightSubtree;

    // no children
    if (!match->left && !match->right)
    {
        left ? parent->left = nullptr : parent->right = nullptr;
        delete delPtr;
    }
    // 1 child
    else if (match->left && !match->right)
    {
        left ? parent->left = match->left : parent->right = match->left;
        match->left = nullptr;
        delete delPtr;
    }
    else if (!match->left && match->right)
    {
        left ? parent->left = match->right : parent->right = match->right;
        match->right = nullptr;
        delete delPtr;
    }
    // 2 children
    else
    {
        smallestInRightSubtree = FindSmallestPrivate(match->right);
        RemoveNodePrivate(smallestInRightSubtree, match);
        match->key = smallestInRightSubtree;
    }

}
template <class T>
void BinaryTree<T>::RemoveSubtree(node* ptr)
{
 if (ptr->left)
 {
     RemoveSubtree(ptr->left);
 }
 if (ptr->right)
 {
    RemoveSubtree(ptr->right);
 }
 cout << "Deleting the node: " << ptr->key << endl;
 delete ptr;
}





#endif // BINARYTREE_H
