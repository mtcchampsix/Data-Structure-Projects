#ifndef AVLTREE_H
#define AVLTREE_H

#include<iostream>
#include "AVLNode.h"

using namespace std;

class AVLTree{
public:
    AVLTree();
    ~AVLTree();
    void insert(int value);
    void remove(int value);
    void display() const;
    int computeHeight(AVLNode * node);
    void rotateWithLeftChild(AVLNode * node);
    void doubleWithLeftChild(AVLNode * node);
    void rotateWithRightChild(AVLNode * node);
    void doubleWithRightChild(AVLNode * node);
    unsigned int AVLComparisons();
    
private:
    void clear(AVLNode * node);
    void balance(AVLNode * node);
    void insert(AVLNode * root, int value);
    void remove(AVLNode * root, int value);
    void display(const AVLNode * root) const;
    AVLNode * findMin(AVLNode * node);
    int max(int Height1, int Height2);
    AVLNode * root;
    const int IMBALANCED = 1;
    unsigned int comparisons = 0;
};

AVLTree::AVLTree(){
    root = NULL;
}

AVLTree::~AVLTree(){
    clear(root);
}

void AVLTree::clear(AVLNode * node){
    if (node == NULL){
        return;
    }
    display(node->getLeftChild());
    delete(node);
    display(node->getRightChild());
    delete(node);
}

int AVLTree::computeHeight(AVLNode * node){
    return node == NULL ? -1 : node->getHeight();
}

void AVLTree::balance(AVLNode * node){
    if (node == NULL){
        comparisons++;
        return;
    }
    if (node->getLeftChild()->getHeight() - node->getRightChild()->getHeight() > IMBALANCED){
        comparisons++;
        if (node->getLeftChild()->getLeftChild()->getHeight() >= node->getLeftChild()->getRightChild()->getHeight()){
            comparisons++;
            rotateWithLeftChild(node);
        } else {
            doubleWithLeftChild(node);
        }
    } else {
        if (node->getRightChild()->getHeight() - node->getLeftChild()->getHeight() > IMBALANCED){
            comparisons++;
            if (node->getRightChild()->getRightChild()->getHeight() >= node->getRightChild()->getLeftChild()->getHeight()){
                comparisons++;
                rotateWithRightChild(node);
            } else {
                doubleWithRightChild(node);
            }
        }
    }
    node->setHeight(max(node->getLeftChild()->getHeight(),node->getRightChild()->getHeight())+1); //look at textbook pseudocode and figure out what means
}

void AVLTree::insert(AVLNode * root, int value){
    if (root == NULL){
        comparisons++;
        root = new AVLNode(value);
    } else if ( value < root->getKey()){
        comparisons++;
        insert(root->getLeftChild(), value);
    } else if (root->getKey() < value){
        comparisons++;
        insert(root->getRightChild(), value);
    }
    balance(root);
}

void AVLTree::remove(AVLNode * node, int value){
    if (node == NULL){
        comparisons++;
        return;
    }
    if (value < node->getKey()){
        comparisons++;
        remove(node->getLeftChild(), value);
    } else if (value > node->getKey()){
        comparisons++;
        remove(node->getRightChild(), value);
    } else if (node->getLeftChild() != NULL && node->getRightChild() != NULL){
        node->setKey(findMin(node->getRightChild())->getKey());
        comparisons++;
        remove(node->getRightChild(), node->getKey());
    } else {
        AVLNode * old = node;
        node = (node->getLeftChild() != NULL) ? node->getLeftChild() : node->getRightChild();
        comparisons++;
        delete(old);
    }
    balance(node);
}

void AVLTree::display(const AVLNode * node) const{
    if (node == NULL){
        return;
    }
    cout << "[" << node->getKey();
    display(node->getLeftChild());
    display(node->getRightChild());
    cout << "]";
}

void AVLTree::rotateWithLeftChild(AVLNode * node){
    AVLNode * node2 = node->getLeftChild();
    node->setLeftChild(node2->getRightChild());
    node2->setRightChild(node);
    node->setHeight(max(node->getLeftChild()->getHeight(), node->getRightChild()->getHeight())+1);
    node2->setHeight(max(node2->getLeftChild()->getHeight(), node->getHeight())+1);
    node = node2;
}

void AVLTree::doubleWithLeftChild(AVLNode * node){
    rotateWithRightChild(node->getLeftChild());
    rotateWithLeftChild(node);
}

void AVLTree::rotateWithRightChild(AVLNode * node){
    AVLNode * node2 = node->getRightChild();
    node->setRightChild(node2->getLeftChild());
    node2->setLeftChild(node);
    node->setHeight(max(node->getRightChild()->getHeight(), node->getLeftChild()->getHeight())+1);
    node2->setHeight(max(node2->getRightChild()->getHeight(), node->getHeight())+1);
    node = node2;
}

void AVLTree::doubleWithRightChild(AVLNode * node){
    rotateWithLeftChild(node->getRightChild());
    rotateWithRightChild(node);
}

AVLNode *AVLTree::findMin(AVLNode * node){
    if (node->isLeaf()){
        return node;
    }
    else {
        findMin(node->getLeftChild());
    }
    return node;
}

int AVLTree::max(int Height1, int Height2){
    if (Height1 > Height2){
        return Height1;
    } else if (Height1 < Height2){
        return Height2;
    } else {
        return Height1;
    }
}

void AVLTree::insert(int value){
    insert(root,value);
}

void AVLTree::remove(int value){
    remove(root, value);
}

void AVLTree::display() const{
    display(root);
}

unsigned int AVLTree::AVLComparisons(){
    return comparisons;
}

#endif
