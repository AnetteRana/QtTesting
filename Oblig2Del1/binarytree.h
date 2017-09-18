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
    int CountNodesInTreePrivate(int numberOut, node* ptr);
    int CountLevelsPrivate(node* ptr, int counter, int& highest);

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
    int CountNodesInTreePublic();
    int CountLevelsPublic();
    void PrintPreOrder();
    void PrintInOrder();
    void PrintPostOrder();
    T FindSmallest();
    void RemoveNode(T key);

    void PrintNodeAndChildren();
    void DeleteFunction();
    void VisualPrint();
    void VisualPrintNodeAndChildren();
    void InsertFunction();
};

// Siden det er template klasse må alt være i headeren:
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
        cout << "No such node.\n";
    }
}

template <class T>
int BinaryTree<T>::CountNodesInTreePrivate(int numberOut, node* ptr)
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
int BinaryTree<T>::CountNodesInTreePublic()
{
    return CountNodesInTreePrivate(0, root);
}

template <class T>
int BinaryTree<T>::CountLevelsPublic()
{
    int levels = 0;
    CountLevelsPrivate(root, 0, levels);
    return levels;
}

template <class T>
int BinaryTree<T>::CountLevelsPrivate(node* ptr, int counter, int& highest)
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
T BinaryTree<T>::FindSmallest()
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
T BinaryTree<T>::FindSmallestPrivate(node* ptr)
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
}

template <class T>
void BinaryTree<T>::RemoveMatch(node* parent, node* match, bool left)
{
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

// extra funksjoner for å printe treet, og å slette noder
template <class T>
void BinaryTree<T>::PrintNodeAndChildren()
{
    T x;
    cout << "\n\nWhich node to see children of?\n";
    cin >> x;
    PrintChildren(x);

}

template <class T>
void BinaryTree<T>::DeleteFunction()
{
    T input;

    cout << "Enter a node to delete.\n";
    cin >> input;
    cout << endl;
    RemoveNode(input);

    cout << endl;
}

// attempt at visual print
template <class T>
void BinaryTree<T>::VisualPrint()
{
    if (root)
    {
        node* lvl1 = root;
        node* lvl2[2] = {nullptr};

        for (int i = 0; i <= 1; i++)
        {
            if (lvl1->left)
                lvl2[i] = lvl1->left;
            i++;
            if (lvl1->right)
                lvl2[i] = lvl1->right;
        }

        node* lvl3[4] = {nullptr};

        int j = 0;
        for (int i = 0; i <= 1; i++)
        {
            if (lvl2[i]->left)
                lvl3[i+(i*1)] = lvl2[i]->left;
            j++;
            if (lvl2[i]->right)
                lvl3[i+1+(i*1)] = lvl2[i]->right;
            j++;
        }

        node* lvl4[8] = {nullptr};

        j = 0;
        for (int i = 0; i <= 3; i++)
        {
            if (lvl3[i]->left)
                lvl4[i+(i*1)] = lvl3[i]->left;
            j++;
            if (lvl3[i]->right)
                lvl4[i+1+(i*1)] = lvl3[i]->right;
            j++;
        }

        // print level 1
        cout << string(50, ' ') << "__" << lvl1->key << "__" << endl;
        //2
        for(int i = 0; i <= 1; i++)
        {
            cout << string(29, ' ') << string(2, '_');
            if (lvl2[i])
                cout << lvl2[i]->key;
            else
                cout << '-';
            cout << string(2, '_');
        }
        cout << endl;
        // 3
        for(int i = 0; i <= 3; i++)
        {
            cout << string(16, ' ') << string(2, '_');
            if (lvl3[i])
                cout << lvl3[i]->key;
            else
                cout << '-';
            cout << string(2, '_');
        }
        cout << endl;
        // 4
        for(int i = 0; i < 8; i++)
        {
            cout << string(7, ' ') << string(2, '_');
            if (lvl4[i])
                cout << lvl4[i]->key;
            else
                cout << '-';
            cout << string(2, '_');
        }
    }
}


template <class T>
void BinaryTree<T>::VisualPrintNodeAndChildren()
{
    cout << "Which node to look at?";
    T key;
    cin >> key;

    node* ptr = ReturnNode(key);
    if (ptr)
    {
        cout << "  __" << key << "__\n";
        cout << " |     |\n";
        cout << " ";
        if (ptr->left)
            cout << ptr->left->key;
        else
            cout << " ";
        cout << "     ";
        if (ptr->right)
            cout << ptr->right->key;
    }
    else
    {
        cout << "No such node.\n";
    }
}

template <class T>
void BinaryTree<T>::InsertFunction()
{
    T key;
    cout << "What to insert? ";
    cin >> key;
    AddLeaf(key);
}


#endif // BINARYTREE_H
