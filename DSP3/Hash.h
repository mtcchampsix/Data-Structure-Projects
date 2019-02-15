#ifndef HASH_H
#define HASH_H

#include "Node.h"
#include<string>
#include<cmath>

using namespace std;

class HashTable{
public:
    HashTable();
    HashTable(unsigned long wordCount);
    void insert(string word);
    bool find(string word);
    unsigned long hash(string word);
    unsigned long getCapacity() { return capacity; }
    void print();
    
private:
    Node * findLastWord(Node * node);
    bool contains(Node * node, string word);
    bool isPrime(unsigned long i);
    
    unsigned long capacity;
    Node * hashArray;
    
};

HashTable::HashTable(){
    capacity = 0;
    hashArray = new Node[capacity];
}

HashTable::HashTable(unsigned long wordCount){
    unsigned long prime = 0;
    for (unsigned long i = 0; i < wordCount; i++){
        if (isPrime(i)){
            prime = (pow(2,i))-1;
        }
        if (prime > wordCount){
            hashArray = new Node[prime];
            capacity = prime;
            break;
        }
    }
}

bool HashTable::isPrime(unsigned long number){
    if (number > 1 && number != 11 && number != 23 && number != 29)
    {
        for (unsigned long i = number - 1; i > 1; i--)
        {
            if ((number % i) == 0)
                return false;
        }
        return true;
    }
    return false;
}

void HashTable::insert(string word){
    unsigned long index = hash(word);
    if (hashArray[index].getWord() == ""){
        hashArray[index].setWord(word);
    } else {
        Node *temp = findLastWord(&hashArray[index]);
        temp->setNext(new Node(word));
    }
}

Node* HashTable::findLastWord(Node *node){
    Node* temp = node;
    while (temp != NULL){
        if (temp->getNext() == NULL){
            return temp;
        } else {
            temp = temp->getNext();
        }
    }
    return temp;
}

bool HashTable::find(string word){
    unsigned long index = hash(word);
    if (hashArray[index].getWord() == word){
        return true;
    } else if (hashArray[index].getWord() != word){
        return contains(&hashArray[index], word);
    } else {
        return false;
    }
}

bool HashTable::contains(Node * node, string word){
    Node * temp = node;
    while (temp != NULL){
        if (temp->getWord() == word){
            return true;
        } else {
            temp = temp->getNext();
        }
    }
    return false;
}

unsigned long HashTable::hash(string word){
    unsigned long hash = 0;
    for (unsigned long i = 0; i < word.length()-1; i++){
        hash = (37 * hash) + word.at(i);
    }
    hash = hash % capacity;
    return hash;
}

void HashTable::print(){
    for (int i = 0; i < capacity; i++){
        cout << hashArray[i].getWord() << endl;
    }
}
#endif 
