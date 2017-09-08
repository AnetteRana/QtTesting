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









