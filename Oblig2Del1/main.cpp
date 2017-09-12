#include <iostream>
#include <cstdlib>
#include "binarytree.h"



using namespace std;

/*
- Implementer en egen BinaryTree klasse med parametrisk konstruktør, hent()- og sett()-funksjoner tilsvarende CharNode klassen.
- Skriv et lite testprogram hvor du bygger et tre med 10 noder.
- Skriv en funksjon (helst i BinaryTree klassen) som skriver ut alle nodenes verdi.
*/


int main()
{

    int treeKeys[10] = {1, 2,5,4,7,5,5,4,4,6};
    BinaryTree myTree;

    cout << "Print tree before adding keys: ";
    myTree.PrintInOrder();

    for (int i = 0; i < 10; i++)
    {
        myTree.AddLeaf(treeKeys[i]);
    }

    cout << "Printing tree after adding keys: ";
    myTree.PrintInOrder();

//    int x = 0;
//    while (x >= 0)
//    {
//        cout << "\n\nWhich number to see children of? (negative number to exit)\n";
//        cin >> x;
//        myTree.PrintChildren(x);
//    }

    cout << "\nNumb of nodes: " << myTree.CountNodesInTreePublic(0);
    cout << "\nNumb of levels: " << myTree.CountLevelsPublic();


    cout << endl;
    return 0;
}
