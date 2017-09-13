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
    BinaryTree* myTree = new BinaryTree;

    for (int i = 0; i < 10; i++)
    {
        myTree->AddLeaf(treeKeys[i]);
    }

    cout << "\nPrinting tree using pre-order traversal: ";
    myTree->PrintPreOrder();

    cout << "\nPrinting tree using in-order traversal: ";
    myTree->PrintInOrder();

    cout << "\nPrinting tree using post-order traversal: ";
    myTree->PrintPostOrder();

    cout << "\nNumb of nodes: " << myTree->CountNodesInTreePublic(0);
    cout << "\nNumb of levels: " << myTree->CountLevelsPublic();


    cout << endl;

//    int input{0};
//    while (input >= 0)
//    {
//        cout << "Enter a key value to delete. (negative number to exit)\n";
//        cin >> input;
//        if (input >= 0)
//        {
//            cout << endl;
//            myTree->RemoveNode(input);

//            cout << "\nPrinting tree using in-order traversal: ";
//            myTree->PrintInOrder();
//            cout << endl;
//        }
//    }




    cout << endl;
    return 0;
}














