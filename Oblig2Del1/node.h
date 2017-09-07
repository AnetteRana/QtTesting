#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    T data;
    Node* Left;
    Node* Right;
public:
    Node(T);
    T getData();
    void setData(T);
};

template <class T>
Node<T>::Node(T in) : data{in}
{

}

template<class T>
T Node<T>::getData()
{
    return data;
}

template<class T>
void Node<T>::setData(T in)
{
    data = in;
}

#endif // NODE_H
