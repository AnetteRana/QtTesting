#include <iostream>
#include "binarytree.h"
#include "node.h"




using namespace std;

/*
- Implementer en egen BinaryTree klasse med parametrisk konstruktør, hent()- og sett()-funksjoner tilsvarende CharNode klassen.
- Skriv et lite testprogram hvor du bygger et tre med 10 noder.
- Skriv en funksjon (helst i BinaryTree klassen) som skriver ut alle nodenes verdi.
*/


int main()
{

    Node* atest = new Node(5, 0, 0);
    Node* btest = new Node(8, 0, 0);
    if (btest->data < atest->data)
    {
        atest->Left = btest;
    }
    else
    {
        atest->Right = btest;
    }
    cout << "Right: " << atest->Right->data;




    cout << endl;
    return 0;
}
