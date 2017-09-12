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

int main()
{
    int treeKeys[10] = {6,1,8,0,2,7,9,4,3,5};
    BinaryTree myTree;

    for (int i = 0; i < 10; i++)
    {
        myTree.AddLeaf(treeKeys[i]);
    }

    cout << "Printing tree using in-order traversal: ";
    myTree.PrintInOrder();

    cout << "\nPrinting tree using pre-order traversal: ";
    myTree.PrintPreOrder();

    cout << "\nPrinting tree using post-order traversal: ";
    myTree.PrintPostOrder();

    cout << "\nNumb of nodes: " << myTree.CountNodesInTreePublic(0);
    cout << "\nNumb of levels: " << myTree.CountLevelsPublic();

    //PrintNodeAndChildren(myTree);


    cout << endl;
    return 0;
}
