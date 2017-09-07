#ifndef NODE_H
#define NODE_H


class Node
{
public:
    int data;
    Node* Left;
    Node* Right;
    Node(int, Node*, Node*);
};


Node::Node(int in = 0, Node* left = 0, Node* right = 0) : data{in}, Left{left}, Right{right}
{

}

#endif // NODE_H
