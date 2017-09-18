// Oblig 2 av Anette Rana:)
#include <iostream>
#include <cstdlib>
#include "binarytree.h"

using namespace std;

int main()
{
    /*
    int treeKeys[10] = {6,1,8,0,2,7,9,4,3,5};
    BinaryTree<int>* myTree = new BinaryTree<int>;
    */
    char treeKeys[10] = {'g','b','i','a','c','h','j','e','d','f'};
    BinaryTree<char>* myTree = new BinaryTree<char>;

    ////// ^^^ kommenter ut en av treene over ^^^

    // bygger treet
    for (int i = 0; i < 10; i++)
    {
        myTree->AddLeaf(treeKeys[i]);
    }

    // test program
    int program;
    cout << "\n\nWhat to do?\n1) Delete a node\n2) Print a node, and its children\n3) Visual print of top four levels\n4) Insert\n5) Traverse\n6) Stats\n";
    cin >> program;
    while(program > 0)
    {
        switch (program)
        {
        case 1:
            myTree->DeleteFunction();
            break;
        case 2:
            myTree->VisualPrintNodeAndChildren();
            break;
        case 3:
            myTree->VisualPrint();
            break;
        case 4:
            myTree->InsertFunction();
            break;
        case 5:
            // demonstrate different ways to print:
            myTree->PrintPreOrder();
            myTree->PrintInOrder();
            myTree->PrintPostOrder();
            break;
        case 6:
            cout << "\nNumb of nodes: " << myTree->CountNodesInTreePublic();
            cout << "\nNumb of levels: " << myTree->CountLevelsPublic();
            break;
        default:
            cout << "Huh?\n";
            break;
        }
        cout << "\n\nWhat to do?\n1) Delete a node\n2) Print a node, and its children\n3) Visual print of top four levels\n4) Insert\n5) Traverse\n6) Stats\n";
        cin >> program;
    }

    cout << endl;
    return 0;
}














