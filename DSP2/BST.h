#ifndef BST_H
#define BST_H

#include<iostream>
#include "node.h"

using namespace std;

class BST{
public:
    BST();
    ~BST();
    void insert( int value);
    void remove(int value);
    void display() const;
    unsigned int BSTcomparisons();
    
private:
    void remove(Node * root, int value);
    void insert(Node * root, int value);
    void display(const Node * root) const;
    Node *removeMin(Node * parent, Node * node);
    void clear(Node * node);
    Node *root;
    unsigned int comparisons = 0;
};

BST::BST(){
    root = NULL;
}

BST::~BST(){
    clear(root);
}

void BST::clear(Node * node){
    if (node == NULL){
        return;
    }
    display(node->getLeftChild());
    delete(node);
    display(node->getRightChild());
    delete(node);
}

void BST::insert(Node * root, int value){
    Node * thisNode = root;
    while (thisNode != NULL){
        if (value > thisNode->getKey()){
            comparisons++;
            if (thisNode->getRightChild() != NULL){
                thisNode = thisNode->getRightChild();
                comparisons++;
            } else {
                thisNode->setRightChild(new Node(value));
            }
        } else if (value < thisNode->getKey()){
            comparisons++;
            if (thisNode->getLeftChild() != NULL){
                comparisons++;
                thisNode = thisNode->getLeftChild();
            } else {
                thisNode->setLeftChild(new Node(value));
            }
        }
    }
}

void BST::remove(Node * root, int value){
    if (root != NULL){
        if (root->getKey() < value){
            comparisons++;
            remove(root->getRightChild(), value);
        } else if (root->getKey() > value){
            comparisons++;
            remove(root->getLeftChild(), value);
        } else if (root->getLeftChild() != NULL && root->getRightChild() != NULL){
            comparisons++;
            Node *minRightSubtree = removeMin(root, root->getRightChild());
            root->setKey(minRightSubtree->getKey());
            delete(minRightSubtree);
        } else {
            Node * trash = root;
            if (root->getLeftChild() != NULL){
                comparisons++;
                root = root->getLeftChild();
            } else {
                root = root->getRightChild();
            }
            delete(trash);
        }
    }
}

Node *BST::removeMin(Node * parent, Node * node){
    if (node != NULL){
        if (node->getLeftChild() != NULL){
            comparisons++;
            return removeMin(node, node->getLeftChild());
        } else {
            parent->setLeftChild(node->getRightChild());
            return node;
        }
    }
    return NULL;
}

//pre-order traversal and print
void BST::display(const Node * node) const{
    if (node == NULL){
        return;
    }
    cout << "[" << node->getKey();
    display(node->getLeftChild());
    display(node->getRightChild());
    cout << "]";
}

void BST::insert( int value){
    insert(root, value);
}

void BST::remove(int value){
    remove(root, value);
}

void BST::display() const{
    display(root);
}

unsigned int BST::BSTcomparisons(){
    return comparisons;
}

#endif 
