// Oblig 2 av Anette Rana:)
#include <iostream>
#include <cstdlib>
#include "binarytree.h"


using namespace std;

void PrintNodeAndChildren(BinaryTree tree)
{
    int x = 0;
    while (x >= 0)
    {
        cout << "\n\nWhich number to see children of? (negative number to exit)\n";
        cin >> x;
        tree.PrintChildren(x);
    }
}

void DeleteFunction(BinaryTree tree)
{
    int input{0};
    while (input >= 0)
    {
        cout << "Enter a key value to delete. (negative number to exit)\n";
        cin >> input;
        if (input >= 0)
        {
            cout << endl;
            tree.RemoveNode(input);

            cout << "\nPrinting tree using in-order traversal: ";
            tree.PrintInOrder();
            cout << endl;
        }
    }
}

int main()
{
    int treeKeys[10] = {6,1,8,0,2,7,9,4,3,5};
    BinaryTree* myTree = new BinaryTree;

    for (int i = 0; i < 10; i++)
    {
        myTree->AddLeaf(treeKeys[i]);
    }

    // print:
    myTree->PrintPreOrder();
    myTree->PrintInOrder();
    myTree->PrintPostOrder();

    cout << "\nNumb of nodes: " << myTree->CountNodesInTreePublic(0);
    cout << "\nNumb of levels: " << myTree->CountLevelsPublic();


    cout << endl;

    DeleteFunction(*myTree);
    PrintNodeAndChildren(*myTree);
    DeleteFunction(*myTree);
    PrintNodeAndChildren(*myTree);
    DeleteFunction(*myTree);
    PrintNodeAndChildren(*myTree);
    DeleteFunction(*myTree);
    PrintNodeAndChildren(*myTree);
    DeleteFunction(*myTree);
    PrintNodeAndChildren(*myTree);
    DeleteFunction(*myTree);
    PrintNodeAndChildren(*myTree);





    cout << endl;
    return 0;
}














