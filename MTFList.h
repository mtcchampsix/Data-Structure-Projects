#ifndef MTFLIST_H
#define MTFLIST_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "nosuchobject.h"
#include "node.h"

using namespace std;


class MTFList {
public:
    MTFList();
    ~MTFList();
    unsigned size() const;
    bool search(int s) throw (NoSuchObject);
    void add(const int & s);
    
private:
    int sz;
    Node<int> * head;
};

MTFList::MTFList(){
    sz = 0;
    head = NULL;
}

MTFList::~MTFList(){
    Node<int> * temp = head;
    while (temp != NULL){
        head = head->getNextPtr();
        delete(temp);
        temp = head;
    }
}

unsigned MTFList::size() const{
    return sz;
}

bool MTFList::search(int s) throw (NoSuchObject){ //after the item is found, move it to front
    Node<int> * prev = NULL;
    Node<int> * temp = head;
    while (temp != NULL){
        if (head->getObject() == s){
            return true;
        } else if (temp->getObject() == s){
            prev->setNextPtr(temp->getNextPtr());
            temp->setNextPtr(head);
            head = temp;
            return true;
        }
        prev = temp;
        temp = temp->getNextPtr();
    }
    return false;
}

void MTFList::add(const int & s){
    Node<int> * newnode = new Node<int>(s);
    if (head == NULL){
        head = newnode;
    } else {
        newnode->setNextPtr(head);
        head = newnode;
    }
    sz++;
}

#endif
