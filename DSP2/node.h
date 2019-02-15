#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string>
#include<stdexcept>
#include<new>

using namespace std;

class Node {
    
public:
    Node( const int &key );
    void setKey( const int & );
    int getKey() const;
    void setRightChild( Node * );
    void setLeftChild( Node * );
    Node *getRightChild() const;
    Node *getLeftChild() const;
    bool isLeaf() const;
    
private:
    int key;
    Node *rightChild;
    Node *leftChild;
}; // Node<T> class


Node::Node( const int &key )
{
    this->key = key;
    this->rightChild = 0;
    this->leftChild = 0;
} // Node<T>::Node


void Node::setKey( const int &key )
{
    this->key = key;
} // Node<T>::setObject


int Node::getKey() const
{
    return key;
} // Node<T>::getObject


void Node::setRightChild( Node *nextPtr )
{
    this->rightChild = nextPtr;
} // Node<T>::setRightChild


void Node::setLeftChild( Node *nextPtr )
{
    this->leftChild = nextPtr;
} // Node<T>::setLeftChild

Node *Node::getRightChild() const
{
    return rightChild;
} // Node<T>::getRightChild

Node *Node::getLeftChild() const
{
    return leftChild;
} // Node<T>::getLeftChild

bool Node::isLeaf() const{
    if (rightChild == NULL && leftChild == NULL){
        return true;
    } else {
        return false;
    }
}

#endif /* node_h */

