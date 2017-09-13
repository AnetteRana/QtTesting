#include <iostream>
#include <cstdlib>
#include "binarytree.h"

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::node* BinaryTree::CreateLeaf(int key)
{
    node* ny = new node;
    ny->key = key;
    ny->left = NULL;
    ny->right = NULL;

    return ny;
}

void BinaryTree::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
}

void BinaryTree::AddLeafPrivate(int key, node* ptr)
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

BinaryTree::node* BinaryTree::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BinaryTree::node* BinaryTree::ReturnNodePrivate(int key, node* ptr)
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

int BinaryTree::ReturnRootKey()
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

void BinaryTree::PrintChildren(int key)
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

int BinaryTree::CountNodesInTreePrivate(int numberOut, node* ptr)
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

int BinaryTree::CountNodesInTreePublic(int numberOut)
{
    CountNodesInTreePrivate(numberOut, root);
}

int BinaryTree::CountLevelsPublic()
{
    int levels = 0;
    CountLevelsPrivate(root, 0, levels);
    return levels;
}

int BinaryTree::CountLevelsPrivate(node* ptr, int counter, int& highest)
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

void BinaryTree::PrintPreOrder()
{
    if (root)
    {
        PrintPreOrderPrivate(root);
    }
    else
    {
        cout << "The tree is empty.\n";
    }
}

void BinaryTree::PrintPreOrderPrivate(node* ptr)
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

void BinaryTree::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BinaryTree::PrintInOrderPrivate(node* ptr)
{
    if (root != NULL)
    {

        if (ptr->left != NULL)
        {
            PrintInOrderPrivate(ptr->left);
        }
        cout << ptr->key << " ";
        if (ptr->right != NULL)
        {
            PrintInOrderPrivate(ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty.\n";
    }
}

void BinaryTree::PrintPostOrder()
{
    if (root)
    {
        PrintPostOrderPrivate(root);
    }
    else
    {
        cout << "The tree is empty.\n";
    }
}

void BinaryTree::PrintPostOrderPrivate(node* ptr)
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

void BinaryTree::DeleteNode(int key)
{

    node* ToDelete = ReturnNode(key);


}

void BinaryTree::RemoveNode(int key)
{
    if (root)
    {
        if (root->key == key)
        {
            // need to remove the root node
        }
        else
        {
            RemoveNodePrivate(key, root);
        }
    }
    else
    {
        cout << "Can't remove node, since the tree is empty\n";
    }
}

BinaryTree::node* BinaryTree::GetSmallestNode(node* ptr)
{
    if (ptr->left)
    {
        return GetSmallestNode(ptr->left);
    }
    return ptr;
}

void BinaryTree::RemoveNodePrivate(int key, node* parent)
{
    // left:
    if (parent->left && key < parent->key)
    {
        if (key == parent->left->key)
        {
            // parent points to "node to delete"
            node* toDelete = parent->left;

            if (parent->left->right)
            {
                // node has child to right
                node* smallest = GetSmallestNode(parent->left->right);
                smallest->left = parent->left->left;
                parent->left = smallest;
            }
            else
            {
                // no right children
                if (parent->left->left)
                {
                    parent->left = parent->left->left;
                }
                else
                {
                    parent->left = nullptr;
                }
            }
            // delete node toDelete
        }
        else
        {
            RemoveNodePrivate(key, parent->left);
        }
    }

    // right:
    else if (parent->right && key > parent->key)
    {
        if (key == parent->right->key)
        {
            // parent points to "node to delete"
            node* toDelete = parent->right;

            if (parent->right->right)
            {
                // node has child to right
                node* smallest = GetSmallestNode(parent->right->right);
                smallest->left = parent->right->left;
                smallest->right = parent->right->right;
                parent->right = smallest;
            }
            else
            {
                // no right children
                if (parent->right->left)
                {
                    parent->right = parent->right->left;
                }
                else
                {
                    parent->right = nullptr;
                }
            }
            // delete node toDelete
        }
        else
        {
            RemoveNodePrivate(key, parent->right);
        }
    }

    // no key match:
    else
    {
        cout << "Can't remove, no such node in tree.\n";
    }

}






