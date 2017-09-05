#include "stack.h"

Stack::Stack()
{
    top = 0;
}

Stack::~Stack()
{

}

void Stack::push(char tegn)
{
    top = new CharNode(tegn, top);
}

void Stack::pop()
{
    if (top) // make sure top is nutt a nullptr
    {
        CharNode* temp = top->getNext();
        delete top;
        top = temp;
    }
}

int Stack::getSize() const
{
    int counter{0};
    CharNode* temp = top;
    while (temp)
    {
        temp = temp->getNext();
        counter++;
    }
    return counter;
}

// return true if stack is empty
bool Stack::isEmpty() const
{
    if (top)
        return false;
    else
        return true;
}

char Stack::getTop() const
{
    if (top)
    {
        return top->getChar();
    }
    return 0;
}
