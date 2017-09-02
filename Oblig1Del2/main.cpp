#include <iostream>
#include "charnode.h"
#include "stack.h"

using namespace std;


int main()
{
    /*
    // make linked list of nodes
    CharNode* list = new CharNode('a', 0);
    list = new CharNode('b', list);
    list = new CharNode('c', list);
    list->newNodeInBack(list, 's');

    // traverse and print nodes in linked list
    CharNode* current = list;
    while (current)
    {
        current->printChar(); // print node
        current = current->getNext(); // get next node
    }
    */
    ////////////////////////////////////////////////////////// Time to get stacky!


    // testing stack class
    Stack* myStack = new Stack();
    myStack->push('a');
    myStack->push('b');
    myStack->pop();

    std::cout << myStack->getTop();




    // end of code
    std::cout << endl;
    return 0;
}
