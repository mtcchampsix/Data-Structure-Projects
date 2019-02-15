#ifndef NODE_H
#define NODE_H
#include<string>

using namespace std;

class Node{
    
public:
    Node();
    Node(string word, Node * next = NULL);
    Node * getNext() { return next; }
    string getWord() { return word; }
    void setNext(Node * next) { this->next = next; }
    void setWord(string word) { this->word = word; }
    
private:
    string word;
    Node * next;

};

Node::Node(){
    word = "";
    next = NULL;
}

Node::Node(string word, Node * next){
    this->word = word;
    this->next = next;
}



#endif
