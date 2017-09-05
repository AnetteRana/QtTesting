#include <iostream>
#include "charnode.h"
#include "stack.h"

using namespace std;


int main()
{
    // testing stack class
    Stack* myStack = new Stack();
    myStack->push('a');
    myStack->push('b');
    myStack->push('c');
    myStack->pop();
    myStack->pop();


    std::cout << "\nTop: " << myStack->getTop() << "\nSize: " << myStack->getSize() << std::endl;


    return 0;
}
