#include "stack.h"


Stack::Stack()
{
    std::cout << "Stack constructed!\n";
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

}

int Stack::size() const
{
    return 0;
}

bool Stack::empty() const
{
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
