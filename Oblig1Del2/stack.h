#ifndef STACK_H
#define STACK_H

#include "charnode.h"



class Stack
{
private:
CharNode* top;
public:
    Stack();
    ~Stack();
    void push(char tegn);
    void pop();
    int size() const;
    bool empty() const;
    char getTop() const;
};


#endif // STACK_H
