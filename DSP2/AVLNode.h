#ifndef AVLNODE_H
#define AVLNODE_H

#include<iostream>
#include<string>
#include<stdexcept>
#include<new>

using namespace std;

class AVLNode {
    
public:
    AVLNode( const int &key );
    void setKey( const int & );
    int getKey() const;
    void setRightChild( AVLNode * );
    void setLeftChild( AVLNode * );
    AVLNode *getRightChild() const;
    AVLNode *getLeftChild() const;
    void setHeight(int value);
    int getHeight();
    bool isLeaf() const;
    
private:
    int key;
    int height;
    AVLNode *rightChild;
    AVLNode *leftChild;
};


AVLNode::AVLNode( const int &key )
{
    this->key = key;
    this->rightChild = 0;
    this->leftChild = 0;
    height = 0;
}


void AVLNode::setKey( const int &key )
{
    this->key = key;
}


int AVLNode::getKey() const
{
    return key;
}


void AVLNode::setRightChild( AVLNode *nextPtr )
{
    this->rightChild = nextPtr;
}


void AVLNode::setLeftChild( AVLNode *nextPtr )
{
    this->leftChild = nextPtr;
}

AVLNode *AVLNode::getRightChild() const
{
    return rightChild;
}

AVLNode *AVLNode::getLeftChild() const
{
    return leftChild;
}

bool AVLNode::isLeaf() const{
    if (rightChild == NULL && leftChild == NULL){
        return true;
    } else {
        return false;
    }
}

void AVLNode::setHeight(int value){
    height = value;
}

int AVLNode::getHeight(){
    return height;
}

#endif 


